project('songbot', ['c', 'cpp'],
        license : 'GPLv3+',
        version : '0.0.1',
        meson_version : '>=1.4.0',
        default_options : ['c_std=c23',
                           'cpp_std=c++26',
                           'buildtype=release',
                           'optimization=g'])


fs = import('fs')

# Always the wrap, never a system package: the module is compiled from
# upstream's module/magic_enum.cppm, which header-only packages don't install.
magic_enum_proj = subproject('magic_enum', version: '>=0.10.0')
magic_enum_dep = magic_enum_proj.get_variable('magic_enum_dep')
magic_enum_root = meson.project_source_root() / 'subprojects' / 'magic_enum-@0@'.format(magic_enum_dep.version())
magic_enum_module_src = magic_enum_root / 'module' / 'magic_enum.cppm'
assert(fs.is_file(magic_enum_module_src),
       'magic_enum module not found at ' + magic_enum_module_src
       + ' (does the wrap directory match the project version?)')

uni_algo_dep = dependency('uni-algo',
                          fallback: ['uni-algo'])

boostut_dep = dependency('ut',
                         default_options: {'wrap_mode': 'forcefallback'},
                         fallback: ['boostut', 'boostut_dep'])

systemd_dep = dependency('libsystemd')

zlib_dep = dependency('zlib')
ssl_dep = dependency('openssl')

# PREBUILT IN songbot-sdk: D++ and prometheus-cpp. sdk-update.yml builds each
# overlay standalone (tools/sdk-install-subproject.sh) and installs it with
# .pc files, so CI does not compile them on every run. An SDK copy is used
# only when it was built from exactly this checkout's wrap and overlay: its .pc
# carries `srchash`, from tools/srchash.sh, and it is compared here with the
# same script's output. A version check would not do -- renovate bumps a wrap
# without the overlay's hand-written project() version, and an overlay-only
# change (a new .cpp) keeps the version -- and either way the PR must compile
# the overlay, which is what pr-build.yml is for. Any mismatch, or no SDK copy
# at all, builds the wrap as before.
#
# Probed with pkg-config directly rather than dependency(required: false), so
# the fallback path never resolves the system copy before the subproject's own
# meson.override_dependency().
pkgconf_prog = find_program('pkg-config', 'pkgconf', required: false)
sdk_prebuilt = {}
foreach wrap, pc : {'dpp': 'dpp', 'prometheus-cpp': 'prometheus-cpp-core'}
  want = run_command('tools/srchash.sh', wrap, check: true).stdout().strip()
  have = ''
  if pkgconf_prog.found()
    have = run_command(pkgconf_prog, '--variable=srchash', pc,
                       check: false).stdout().strip()
  endif
  if have != '' and have != want
    warning('The installed @0@ (@1@.pc) was built from a different @0@.wrap or overlay; building it from the wrap instead'.format(wrap, pc))
  endif
  sdk_prebuilt += {wrap: have == want}
endforeach

# DPP discord library — native Meson build via subprojects/packagefiles/dpp/meson.build
if sdk_prebuilt['dpp']
  dpp_dep = dependency('dpp')
else
  dpp_dep = subproject('dpp').get_variable('dpp_dep')
endif
nlohmann_json_dep = dependency('nlohmann_json', fallback: ['json', 'nlohmann_json_multiple_headers'])

# prometheus-cpp — native Meson build via subprojects/packagefiles/prometheus-cpp/meson.build
if sdk_prebuilt['prometheus-cpp']
  prometheus_core_dep = dependency('prometheus-cpp-core')
  prometheus_pull_dep = dependency('prometheus-cpp-pull')
else
  prometheus_proj = subproject('prometheus-cpp')
  prometheus_core_dep = prometheus_proj.get_variable('core_dep')
  prometheus_pull_dep = prometheus_proj.get_variable('pull_dep')
endif
prometheus_dep = declare_dependency(dependencies: [prometheus_pull_dep, prometheus_core_dep, zlib_dep])

# C++ Module Mapper
module_conf_data = configuration_data()
module_conf_data.set('BUILD_DIR', meson.project_build_root())
module_conf_data.set('UNI_ALGO_INCLUDEDIR', uni_algo_dep.get_variable('includedir'))
prometheus_core_inc       = prometheus_core_dep.get_variable('includedir')
prometheus_core_build_inc = prometheus_core_dep.get_variable('generated_includedir')
prometheus_pull_inc       = prometheus_pull_dep.get_variable('includedir')
prometheus_pull_build_inc = prometheus_pull_dep.get_variable('generated_includedir')

module_conf_data.set('PROMETHEUS_CORE_INCLUDEDIR', prometheus_core_inc)
module_conf_data.set('PROMETHEUS_PULL_INCLUDEDIR', prometheus_pull_inc)

dpp_includedir = dpp_dep.get_variable('includedir')

module_mapper_file = configure_file(input: 'module.mapper.in',
                                    output: 'module.mapper',
                                    configuration: module_conf_data)

opt_flag = '-O' + get_option('optimization')

# Language flags for the hand-written module compile commands. Each CMI and
# every importer must agree on these. -freflection turns on C++26 static
# reflection, which magic_enum >= 0.10 uses in place of its
# __PRETTY_FUNCTION__ parsing; std_module needs it too, so that `import std`
# provides <meta>. MAGIC_ENUM_REQUIRE_STD_REFLECTION makes any TU that
# preprocesses magic_enum (today only the module) fail rather than fall back
# to the old backend. reflection_args goes into both cpp26_args and the
# project arguments, which don't reach the custom_target commands.
reflection_args = ['-freflection', '-DMAGIC_ENUM_REQUIRE_STD_REFLECTION']
cpp26_args = ['-std=c++26'] + reflection_args

add_project_arguments( reflection_args,
                       '-fmodules',
                       '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
                       '-Mno-modules',
                       '-fcoroutines',
                       '-fconstexpr-ops-limit=3355443200',
                       '--embed-dir=@0@'.format(meson.project_source_root() / 'res'),
                       '-DDPP_USE_EXTERNAL_JSON',
                       language: ['cpp'])

cxx_compiler = meson.get_compiler('cpp')

subdir('src')
subdir('test')
