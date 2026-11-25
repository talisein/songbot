project('songbot', ['c', 'cpp'],
        license : 'GPLv3+',
        version : '0.0.1',
        meson_version : '>=1.4.0',
        default_options : ['c_std=c23',
                           'cpp_std=c++26',
                           'buildtype=release',
                           'optimization=g'])


# Always the wrap, never a system package: the module is compiled from
# upstream's module/magic_enum.cppm, which header-only packages don't install.
magic_enum_proj = subproject('magic_enum', version: '>=0.10.0')
magic_enum_dep = magic_enum_proj.get_variable('magic_enum_dep')
magic_enum_root = meson.project_source_root() / 'subprojects' / 'magic_enum-@0@'.format(magic_enum_proj.version())
magic_enum_module_src = magic_enum_root / 'module' / 'magic_enum.cppm'
assert(import('fs').is_file(magic_enum_module_src),
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

# DPP discord library — native Meson build via subprojects/packagefiles/dpp/meson.build
dpp_dep = dependency('dpp', fallback: ['dpp', 'dpp_dep'])
nlohmann_json_dep = dependency('nlohmann_json', fallback: ['json', 'nlohmann_json_multiple_headers'])

# prometheus-cpp — native Meson build via subprojects/packagefiles/prometheus-cpp/meson.build
prometheus_core_dep = dependency('prometheus-cpp-core', fallback: ['prometheus-cpp', 'core_dep'])
prometheus_pull_dep = dependency('prometheus-cpp-pull', fallback: ['prometheus-cpp', 'pull_dep'])
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
# every importer must agree on these.
cpp26_args = ['-std=c++26']

add_project_arguments( '-fmodules',
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
