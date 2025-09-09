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

cxx_compiler = meson.get_compiler('cpp')

module_conf_data = configuration_data()
module_conf_data.set('BUILD_DIR', meson.project_build_root())
module_conf_data.set('UNI_ALGO_INCLUDEDIR', uni_algo_dep.get_variable('includedir'))
module_conf_data.set('MAGIC_ENUM_INCLUDEDIR', magic_enum_dep.get_variable('includedir', default_value: '@0@/subprojects/magic_enum-0.9.7/include'.format(meson.project_source_root())))
#module_conf_data.set('BOOSTUT_INCLUDEDIR', boostut_dep.get_variable('includedir'))

module_mapper_file = configure_file(input: 'module.mapper.in',
                                    output: 'module.mapper',
                                    configuration: module_conf_data)

add_project_arguments( '-fmodules',
                       '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
                       '-Mno-modules',
                       language: ['cpp'])

subdir('src')
subdir('test')
