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

prometheus_counter_h_module = custom_target('prometheus_counter_h_module',
    input: 'prometheus.cppm', # Fake input. The input is prometheus.h from the subproject.
    output: ['counter_h.gcm'],
    command: [
        cxx_compiler.cmd_array(),
        '-std=c++26',
        '-fmodules',
        '-fmodule-only',
        '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
        '-x', 'c++-user-header',
        '-I', prometheus_core_build_inc,
        '-I', prometheus_core_inc,
        '-c', 'prometheus/counter.h',
    ],
)

prometheus_registry_h_module = custom_target('prometheus_registry_h_module',
    input: 'prometheus.cppm', # Fake input. The input is prometheus.h from the subproject.
    output: ['registry_h.gcm'],
    command: [
        cxx_compiler.cmd_array(),
        '-std=c++26',
        '-fmodules',
        '-fmodule-only',
        '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
        '-x', 'c++-user-header',
        '-I', prometheus_core_build_inc,
        '-I', prometheus_core_inc,
        '-c', 'prometheus/registry.h',
    ],
)

prometheus_exposer_h_module = custom_target('prometheus_exposer_h_module',
    input: 'prometheus.cppm', # Fake input. The input is prometheus.h from the subproject.
    output: ['exposer_h.gcm'],
    command: [
        cxx_compiler.cmd_array(),
        '-std=c++26',
        '-fmodules',
        '-fmodule-only',
        '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
        '-x', 'c++-user-header',
        '-I', prometheus_core_build_inc,
        '-I', prometheus_core_inc,
        '-I', prometheus_pull_build_inc,
        '-I', prometheus_pull_inc,
        '-c', 'prometheus/exposer.h',
    ],
)

prometheus_module = custom_target('prometheus_module',
    input: 'prometheus.cppm',
    output: ['prometheus.o', 'prometheus.gcm'],
    command: [
        cxx_compiler.cmd_array(),
        '-std=c++26',
        '-fmodules',
        '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
        '-c', '@INPUT@',
        '-o', '@OUTPUT0@',
        '-I', prometheus_core_build_inc,
        '-I', prometheus_core_inc,
        '-I', prometheus_pull_build_inc,
        '-I', prometheus_pull_inc,
    ],
    depends: [prometheus_counter_h_module, prometheus_registry_h_module, prometheus_exposer_h_module],
)

dpp_h_module = custom_target('dpp_h_module',
    input: 'dpp.cppm', # Fake input. The input is dpp.h from the subproject.
    output: ['dpp_h.gcm'],
    command: [
        cxx_compiler.cmd_array(),
        '-std=c++26',
        '-fmodules',
        '-fmodule-only',
        '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
        '-x', 'c++-user-header',
        '-I', dpp_includedir,
        '-c', 'dpp/dpp.h',
    ],
                            )

dpp_module = custom_target('dpp_module',
    input: 'dpp.cppm',
    output: ['dpp.o', 'dpp.gcm'],
    command: [
        cxx_compiler.cmd_array(),
        '-std=c++26',
        '-fmodules',
        '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
        '-I', dpp_includedir,
        '-c', '@INPUT@',
        '-o', '@OUTPUT0@',
    ],
    depends: [dpp_h_module],
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

util_module = custom_target('util_module',
    input: 'util.cppm',
    output: ['util.o', 'util.gcm'],
    command: [
        cxx_compiler.cmd_array(),
        '-std=c++26',
        '-fmodules',
        '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
        '-c', '@INPUT@',
        '-o', '@OUTPUT0@',
        '-fconstexpr-ops-limit=3355443200',
    ],
    depends: [std_module, uni_algo_module, magic_enum_module]
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
        '-fconstexpr-ops-limit=3355443200',
    ],
    depends: [std_module, uni_algo_module, magic_enum_module, util_module]
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
        '-fconstexpr-ops-limit=3355443200',
    ],
    depends: [std_module, uni_algo_module, magic_enum_module, songs_module, util_module]
)


src = ['main.cpp', 'context.cpp', 'sd_notify.cpp', 'config_file.cpp', 'commands.cpp', 'errors.cpp', 'setlist_command.cpp', 'song_command.cpp']

exe = executable('songbot', src, songs_module, std_module, uni_algo_module, magic_enum_module, concerts_module, dpp_module, prometheus_module, util_module,
                 dependencies: [magic_enum_dep, dpp_dep, systemd_dep, prometheus_dep],
                 install: true
                )
