# Build

source .venv/bin/activate && make haverworks/theseus75:goten

# Flash

source .venv/bin/activate && make haverworks/theseus75:goten:flash

# Generate JSON

source .venv/bin/activate && qmk c2json -kb haverworks/theseus75 -km goten -o theseus75_goten.json keyboards/haverworks/theseus75/keymaps/goten/keymap.c
