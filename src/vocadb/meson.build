vocadb_api_module = custom_target('vocadb_api_module',
                                  input: 'vocadb-api.cppm',
                                  output: ['vocadb-api.o', 'vocadb-api.gcm'],
                                  command: [
                                    cxx_compiler.cmd_array(),
                                    '-std=c++26',
                                    opt_flag,
                                    '-fmodules',
                                    '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
                                    '-c', '@INPUT@',
                                    '-o', '@OUTPUT0@',
                                    '-fconstexpr-ops-limit=3355443200',
                                  ],
                                  depends: [std_module]
                                 )

if get_option('build_anidb_sourcegen')

  curl_cpr_dep = dependency('cpr')
  json_dep = dependency('nlohmann_json',
                        version: '>=3.12.99',
                        fallback: 'json')

#  cpr_inc = curl_cpr_dep.get_variable(cmake: 'CPR_INCLUDE_DIRS')
  cpr_h_module = custom_target('cpr_h_module',
    input: 'cpr.cppm', # Fake input.
    output: ['cpr_h.gcm'],
    command: [
        cxx_compiler.cmd_array(),
        '-std=c++26',
        opt_flag,
        '-fmodules',
        '-fmodule-only',
        '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
        '-x', 'c++-user-header',
#        '-I', cpr_inc,
        '-c', 'cpr/cpr.h',
    ],
  )

  cpr_module = custom_target('cpr_module',
    input: 'cpr.cppm',
    output: ['cpr.o', 'cpr.gcm'],
    command: [
        cxx_compiler.cmd_array(),
        '-std=c++26',
        opt_flag,
        '-fmodules',
        '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
        '-c', '@INPUT@',
        '-o', '@OUTPUT0@',
#        '-I', cpr_inc,
    ],
    depends: [cpr_h_module]
  )

  json_module = custom_target('json_module',
    input: 'json.cppm',
    output: ['json.o', 'json.gcm'],
    command: [
        cxx_compiler.cmd_array(),
        '-std=c++26',
        opt_flag,
        '-fmodules',
        '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
        '-c', '@INPUT@',
        '-o', '@OUTPUT0@',
        '-DNLOHMANN_JSON_BUILD_MODULES',
        '-I', '../subprojects/json-9810c39/include',
    ],
    depends: [std_module]
  )

  scraper_conf_data = configuration_data()
  scraper_conf_data.set('RES_DIR', meson.project_source_root() / 'res/')
  scraper_conf_data.set('GEN_DIR', meson.current_source_dir() / 'gen/')
  scraper_conf_file = configure_file(input: 'config.h.in',
                                     output: 'config.h',
                                     configuration: scraper_conf_data)

  scraper_src = ['main.cpp', 'scraper.cpp']

  scraper_exe = executable('vocadb-scraper', scraper_src, json_module, cpr_module, misc_modules_gcm,
                           dependencies: [magic_enum_dep, curl_cpr_dep, json_dep, dpp_dep],
                           link_with: misc_modules_lib,
                           sources: scraper_conf_file)

endif

vocadb_events_module = custom_target('events_module',
                              input: 'gen/release_events.cppm',
                              output: ['release_events.o', 'release_events.gcm'],
                              command: [
                                cxx_compiler.cmd_array(),
                                '-std=c++26',
                                opt_flag,
                                '-fmodules',
                                '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
                                '-c', '@INPUT@',
                                '-o', '@OUTPUT0@',
                                '-fconstexpr-ops-limit=3355443200',
                                '-fconstexpr-loop-limit=2000000',
                                '-I', meson.current_source_dir(),
                                '--embed-dir=@0@'.format(meson.project_source_root() / 'res')
                              ],
                              depends: [vocadb_api_module, std_module]
                             )

vocadb_lib = static_library('vocadb',
                            objects: [vocadb_api_module[0], vocadb_events_module[0]])
vocadb_gcm = [vocadb_api_module[1], vocadb_events_module[1]]
