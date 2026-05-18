gtk_dep = dependency('gtk4')
adwaita_dep = dependency('libadwaita-1', version: '>= 1.5')
libsoup_dep = dependency('libsoup-3.0')
peel_dep = dependency('peel', fallback: ['peel', 'peel_dep'])

peel_gen_prog = find_program('peel-gen')

peel_gtk = custom_target('util-peel-codegen',
  command: [
    peel_gen_prog,
    '--recursive',
    '--out-dir', '@OUTDIR@',
    'Gtk', '4.0',
    'Adw', '1',
    'Soup', '3.0',
  ],
  output: 'peel',
)

peel_gtk_dep = declare_dependency(sources: peel_gtk)

util_deps = [gtk_dep, adwaita_dep, libsoup_dep, peel_dep, peel_gtk_dep, nlohmann_json_dep]

executable('song_searcher',
           ['song_searcher.cpp'],
           dependencies: util_deps)
