project('nlohmann_json', 'cpp', version: '3.12.0')

nlohmann_json_dep = declare_dependency(
  include_directories: include_directories('single_include')
)

nlohmann_json_multiple_headers = declare_dependency(
  include_directories: include_directories('include'),
  version: '3.12.0',
  variables: ['includedir=@0@'.format(meson.current_source_dir() / 'include')],
)

meson.override_dependency('nlohmann_json', nlohmann_json_multiple_headers)
