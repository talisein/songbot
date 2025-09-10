std_module = custom_target('std_module',
    input: files('/usr/include/c++/15/bits/std.cc'),
    output: 'std.gcm',
    command: [cxx_compiler.cmd_array(),
              '-std=c++26',
              '-fmodules',
              '-fmodule-only',
              '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
              '-fsearch-include-path',
              '-c', 'bits/std.cc'
             ],
 )

magic_enum_all_module = custom_target('magic_enum_all_module',
    input: 'magic_enum.cppm', # Fake input. The input is all.h from the subproject.
    output: ['magic_enum_all.gcm'],
    command: [
        cxx_compiler.cmd_array(),
        '-std=c++26',
        '-fmodules',
        '-fmodule-only',
        '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
        '-x', 'c++-user-header',
        '-I', magic_enum_dep.get_variable('includedir', default_value: '@0@/subprojects/magic_enum-0.9.7/include'.format(meson.project_source_root())),
        '-c', 'magic_enum/magic_enum_all.hpp',
    ],
)

magic_enum_module = custom_target('magic_enum_module',
    input: 'magic_enum.cppm',
    output: ['magic_enum.o', 'magic_enum.gcm'],
    command: [
        cxx_compiler.cmd_array(),
        '-std=c++26',
        '-fmodules',
        '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
        '-c', '@INPUT@',
        '-o', '@OUTPUT0@',
        '-I', magic_enum_dep.get_variable('includedir', default_value: '@0@/subprojects/magic_enum-0.9.7/include'.format(meson.project_source_root())),
        '-I', meson.current_source_dir(),
    ],
    depends: [magic_enum_all_module]
)

uni_algo_all_module = custom_target('uni_algo_all_module',
    input: 'uni_algo.cppm', # Fake input. The input is all.h from the subproject.
    output: ['uni_algo_all.gcm'],
    command: [
        cxx_compiler.cmd_array(),
        '-std=c++26',
        '-fmodules',
        '-fmodule-only',
        '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
        '-x', 'c++-user-header',
        '-c', 'uni_algo/all.h',
        '-I', uni_algo_dep.get_variable('includedir'),
        '-DUNI_ALGO_STATIC_DATA',
    ],
)

uni_algo_module = custom_target('uni_algo_module',
    input: 'uni_algo.cppm',
    output: ['uni_algo.o', 'uni_algo.gcm'],
    command: [
        cxx_compiler.cmd_array(),
        '-std=c++26',
        '-fmodules',
        '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
        '-c', '@INPUT@',
        '-o', '@OUTPUT0@',
        '-I', uni_algo_dep.get_variable('includedir'),
        '-I', meson.current_source_dir(),
    ],
    depends: [uni_algo_all_module]
)

songs_module = custom_target('songs_module',
    input: 'songs.cppm',
    output: ['songs.o', 'songs.gcm'],
    command: [
        cxx_compiler.cmd_array(),
        '-std=c++26',
        '-fmodules',
        '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
        '-c', '@INPUT@',
        '-o', '@OUTPUT0@',
    ],
    depends: [std_module, uni_algo_module, magic_enum_module]
)

concerts_module = custom_target('concerts_module',
    input: 'concerts.cppm',
    output: ['concerts.o', 'concerts.gcm'],
    command: [
        cxx_compiler.cmd_array(),
        '-std=c++26',
        '-fmodules',
        '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
        '-c', '@INPUT@',
        '-o', '@OUTPUT0@',
    ],
    depends: [std_module, uni_algo_module, magic_enum_module, songs_module]
)


src = ['main.cpp']

exe = executable('songbot', src, songs_module, std_module, uni_algo_module, magic_enum_module, concerts_module,
                 dependencies: magic_enum_dep,
                )
