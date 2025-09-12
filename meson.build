project('songbot', ['c', 'cpp'],
        license : 'GPLv3+',
        version : '0.0.1',
        meson_version : '>=1.4.0',
        default_options : ['c_std=c23',
                           'cpp_std=c++23',
                           'buildtype=release'])


magic_enum_dep = dependency('magic_enum',
			    version: '>=0.9.7',
                fallback: ['magic_enum'])

uni_algo_dep = dependency('uni-algo',
                          fallback: ['uni-algo'])

boostut_dep = dependency('ut',
                         default_options: {'wrap_mode': 'force'},
                         fallback: ['boostut', 'boostut_dep'])

systemd_dep = dependency('libsystemd')

zlib_dep = dependency('zlib')
ssl_dep = dependency('openssl')

# DPP discord library
cmake = import('cmake')
dpp_opts = cmake.subproject_options()
dpp_opts.add_cmake_defines({'DPP_BUILD_TEST': false})
dpp_opts.add_cmake_defines({'DPP_NO_VCPKG': true})
dpp_opts.add_cmake_defines({'DPP_NO_CONAN': true})
dpp_opts.add_cmake_defines({'BUILD_SHARED_LIBS': true})
dpp_opts.add_cmake_defines({'BUILD_VOICE_SUPPORT': false})
dpp_opts.add_cmake_defines({'CMAKE_SUPPRESS_DEVELOPER_WARNINGS': true})
dpp_proj = cmake.subproject('dpp', options: dpp_opts)
dpp_dep = dpp_proj.dependency('dpp')

# prometheus-cpp
prometheus_opts = cmake.subproject_options()
prometheus_opts.add_cmake_defines({'ENABLE_PUSH': false})
prometheus_opts.add_cmake_defines({'ENABLE_TESTING': false})
prometheus_opts.add_cmake_defines({'GENERATE_PKGCONFIG': false})
prometheus_opts.add_cmake_defines({'CMAKE_SUPPRESS_DEVELOPER_WARNINGS': true})
prometheus_proj = cmake.subproject('prometheus-cpp', options: prometheus_opts)
prometheus_pull_dep  = prometheus_proj.dependency('pull')
prometheus_core_dep  = prometheus_proj.dependency('core')
prometheus_dep = declare_dependency(dependencies: [prometheus_pull_dep, prometheus_core_dep, zlib_dep])

# C++ Module Mapper
cxx_compiler = meson.get_compiler('cpp')
module_conf_data = configuration_data()
module_conf_data.set('BUILD_DIR', meson.project_build_root())
module_conf_data.set('UNI_ALGO_INCLUDEDIR', uni_algo_dep.get_variable('includedir'))
module_conf_data.set('MAGIC_ENUM_INCLUDEDIR', magic_enum_dep.get_variable('includedir', default_value: '@0@/subprojects/magic_enum-0.9.7/include'.format(meson.project_source_root())))
prometheus_core_inc = prometheus_core_dep.get_variable('includedir', default_value: '@0@/subprojects/prometheus-cpp-with-submodules/core/include'.format(meson.project_source_root()))
prometheus_core_build_inc = meson.current_build_dir() / 'subprojects' / 'prometheus-cpp-with-submodules' / '__CMake_build' / 'core' / 'include'
prometheus_pull_build_inc = meson.current_build_dir() / 'subprojects' / 'prometheus-cpp-with-submodules' / '__CMake_build' / 'pull' / 'include'

module_conf_data.set('PROMETHEUS_CORE_INCLUDEDIR', prometheus_core_inc)
prometheus_pull_inc = prometheus_pull_dep.get_variable('includedir', default_value: '@0@/subprojects/prometheus-cpp-with-submodules/pull/include'.format(meson.project_source_root()))
module_conf_data.set('PROMETHEUS_PULL_INCLUDEDIR', prometheus_pull_inc)

dpp_includedir = dpp_dep.get_variable('includedir', default_value: '@0@/subprojects/DPP-10.1.3/include'.format(meson.project_source_root()))
module_conf_data.set('DPP_INCLUDEDIR', dpp_includedir)

module_mapper_file = configure_file(input: 'module.mapper.in',
                                    output: 'module.mapper',
                                    configuration: module_conf_data)

add_project_arguments( '-fmodules',
                       '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
                       '-Mno-modules',
                       '-fcoroutines',
                       language: ['cpp'])

subdir('src')
subdir('test')
