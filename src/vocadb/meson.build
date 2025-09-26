

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
        '-fmodules',
        '-fmodule-mapper=@0@'.format(module_mapper_file.full_path()),
        '-c', '@INPUT@',
        '-o', '@OUTPUT0@',
        '-DNLOHMANN_JSON_BUILD_MODULES',
        '-I', '../subprojects/json-9810c39/include',
    ],
  )

  scraper_src = ['main.cpp', 'vocadb-api.cpp']

  scraper_exe = executable('vocadb-scraper', scraper_src, songs_module, std_module, uni_algo_module, magic_enum_module, concerts_module, util_module, cpr_module, json_module,
                           dependencies: [magic_enum_dep, curl_cpr_dep, json_dep])








endif
