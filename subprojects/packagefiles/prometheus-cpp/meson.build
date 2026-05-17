project('prometheus-cpp', ['c', 'cpp'],
        version: '1.3.0',
        meson_version: '>=1.4.0',
        default_options: ['cpp_std=c++11'])

cc = meson.get_compiler('c')
threads_dep = dependency('threads')
zlib_dep = dependency('zlib')
rt_dep = cc.find_library('rt', required: false)

generated_inc = include_directories('generated-include')
util_inc      = include_directories('util/include')
core_inc      = include_directories('core/include')
pull_inc      = include_directories('pull/include')
civetweb_inc  = include_directories('3rdparty/civetweb/include')

# --- core ---

core_lib = static_library('prometheus-cpp-core',
  files(
    'core/src/check_names.cc',
    'core/src/counter.cc',
    'core/src/detail/builder.cc',
    'core/src/detail/ckms_quantiles.cc',
    'core/src/detail/time_window_quantiles.cc',
    'core/src/detail/utils.cc',
    'core/src/family.cc',
    'core/src/gauge.cc',
    'core/src/histogram.cc',
    'core/src/info.cc',
    'core/src/registry.cc',
    'core/src/serializer.cc',
    'core/src/summary.cc',
    'core/src/text_serializer.cc',
  ),
  include_directories: [core_inc, generated_inc],
  dependencies: [threads_dep, rt_dep],
  install: false,
)

core_dep = declare_dependency(
  link_with: core_lib,
  include_directories: [core_inc, generated_inc],
  dependencies: [threads_dep, rt_dep],
  variables: {
    'includedir': meson.current_source_dir() / 'core/include',
    'generated_includedir': meson.current_source_dir() / 'generated-include',
  },
)

# --- civetweb (embedded, consumed only by pull) ---

civetweb_lib = static_library('civetweb',
  files(
    '3rdparty/civetweb/src/civetweb.c',
    '3rdparty/civetweb/src/CivetServer.cpp',
  ),
  include_directories: civetweb_inc,
  c_args: ['-DCIVETWEB_API=', '-DUSE_IPV6', '-DSOCKET_TIMEOUT_QUANTUM=200', '-DNO_SSL'],
  dependencies: [threads_dep],
  install: false,
)

# --- pull ---

pull_lib = static_library('prometheus-cpp-pull',
  files(
    'pull/src/basic_auth.cc',
    'pull/src/endpoint.cc',
    'pull/src/exposer.cc',
    'pull/src/handler.cc',
    'pull/src/metrics_collector.cc',
  ),
  include_directories: [pull_inc, generated_inc, core_inc, util_inc, civetweb_inc],
  cpp_args: ['-DHAVE_ZLIB'],
  dependencies: [threads_dep, zlib_dep, rt_dep],
  link_with: [core_lib, civetweb_lib],
  install: false,
)

pull_dep = declare_dependency(
  link_with: [pull_lib, core_lib, civetweb_lib],
  include_directories: [pull_inc, generated_inc, core_inc, util_inc],
  dependencies: [threads_dep, zlib_dep, rt_dep],
  variables: {
    'includedir': meson.current_source_dir() / 'pull/include',
    'generated_includedir': meson.current_source_dir() / 'generated-include',
  },
)

meson.override_dependency('prometheus-cpp-core', core_dep)
meson.override_dependency('prometheus-cpp-pull', pull_dep)
