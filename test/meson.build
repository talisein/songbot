ut_module = custom_target('ut_module',
    input: 'ut.cppm',
    output: ['ut.o', 'ut.gcm'],
    command: [
        cxx_compiler.cmd_array(),
        '-std=c++26',
        '-fmodules',
        '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
        '-c', '@INPUT@',
        '-o', '@OUTPUT0@',
        '-I', boostut_dep.get_variable('includedir', default_value: '@0@/subprojects/ut-v2.3.1/include/boost'.format(meson.project_source_root())),
        '-I', meson.current_source_dir(),
    ],
    depends: [std_module]
)

ut_args = ['-r', 'junit', '-o']
songs_test =  executable('songs_test', 'songs.cpp', ut_module, misc_modules_gcm, vocadb_gcm,
                         link_whole: [misc_modules_lib, vocadb_lib],
                         dependencies: [boostut_dep, dpp_dep])
test('songs', songs_test, args: [ut_args])

concerts_test =  executable('concerts_test', 'concerts.cpp', ut_module, misc_modules_gcm, vocadb_gcm,
                            link_whole: [misc_modules_lib, vocadb_lib],
                            dependencies: [boostut_dep, dpp_dep])
test('concerts', concerts_test, args: [ut_args])
