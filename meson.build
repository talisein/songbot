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
dpp_proj = cmake.subproject('dpp', options: dpp_opts)
dpp_dep = dpp_proj.dependency('dpp')
# C++ Module Mapper
cxx_compiler = meson.get_compiler('cpp')
module_conf_data = configuration_data()
module_conf_data.set('BUILD_DIR', meson.project_build_root())
module_conf_data.set('UNI_ALGO_INCLUDEDIR', uni_algo_dep.get_variable('includedir'))
module_conf_data.set('MAGIC_ENUM_INCLUDEDIR', magic_enum_dep.get_variable('includedir', default_value: '@0@/subprojects/magic_enum-0.9.7/include'.format(meson.project_source_root())))

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
