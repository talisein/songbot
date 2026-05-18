gnome = import('gnome')

gtk_dep = dependency('gtk4')
adwaita_dep = dependency('libadwaita-1', version: '>= 1.5')
libsoup_dep = dependency('libsoup-3.0')
glycin_dep = dependency('glycin-2')
glycin_gtk4_dep = dependency('glycin-gtk4-2')
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
    'Gly', '2',
    'GlyGtk4', '2',
  ],
  output: 'peel',
)

peel_gtk_dep = declare_dependency(sources: peel_gtk)

util_deps = [gtk_dep, adwaita_dep, libsoup_dep, glycin_dep, glycin_gtk4_dep, peel_dep, peel_gtk_dep, nlohmann_json_dep]

res = gnome.compile_resources('song_searcher_resources',
    'song_searcher.gresource.xml',
    install_header: false,
    export: false,
    c_name: 'song_searcher_resources')

executable('song_searcher',
           ['song_searcher.cpp',
            'song_item.cpp',
            'primary_song_data_cell.cpp',
            'secondary_song_data_cell.cpp'],
           res,
           dependencies: util_deps)
