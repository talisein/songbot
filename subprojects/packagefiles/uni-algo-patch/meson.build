project('uni-algo', ['cpp'],
        license : 'MIT',
        version : '1.2')

uni_algo_inc = include_directories('include')
uni_algo_dep = declare_dependency(version: meson.project_version(),
                                 include_directories: uni_algo_inc,
                                 compile_args: ['-DUNI_ALGO_STATIC_DATA'],
                                 variables: ['includedir=@0@'.format(meson.current_source_dir() / 'include')])

meson.override_dependency('uni-algo', uni_algo_dep)
