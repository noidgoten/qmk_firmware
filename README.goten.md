# Build

make haverworks/theseus75:goten

# Flash

make haverworks/theseus75:goten:flash

# Generate JSON

qmk c2json -kb haverworks/theseus75 -km goten -o theseus75_goten.json keyboards/haverworks/theseus75/keymaps/goten/keymap.c

# Layers

Two layers, defined in `keyboards/haverworks/theseus75/keymaps/goten/keymap.c`.

- **Layer 0** — base, normal typing.
- **Layer 1** — momentary, active only while the **left thumb's 2.25u key** (leftmost of the three middle keys, labeled "Space" in the board JSON) is held down. This is `MO(1)` at matrix position `[5,4]`.

Layer 1 overlays a handful of keys — everything else is transparent (falls through to layer 0):

| Physical key          | Layer 0 | Layer 1 (MO held)    |
| --------------------- | ------- | -------------------- |
| Top-right corner      | Del     | PrtSc                |
| Backspace             | Bksp    | Del                  |
| Right encoder press   | Mute    | Play/Pause           |
| `1`                   | 1       | RGB toggle           |
| `Q` / `A`             | Q / A   | Brightness up / down |
| `W` / `S`             | W / S   | Saturation up / down |
| `E` / `D`             | E / D   | Hue up / down        |
| `R` / `F`             | R / F   | RGB mode next / prev |
| `T` / `G`             | T / G   | RGB speed up / down  |

# Encoders

Two rotary encoders, one per half. Their behavior changes per layer via `encoder_map[]` in `keymap.c`. Requires `ENCODER_MAP_ENABLE = yes` in `rules.mk`.

**Left encoder** (matrix `[0,0]`, top-left macro column)

|         | CCW          | CW           | Press          |
| ------- | ------------ | ------------ | -------------- |
| Layer 0 | RGB dimmer   | RGB brighter | RGB toggle     |
| Layer 1 | RGB prev mode | RGB next mode | (falls through) |

**Right encoder** (matrix `[6,8]`, top-right)

|         | CCW         | CW        | Press      |
| ------- | ----------- | --------- | ---------- |
| Layer 0 | Volume down | Volume up | Mute       |
| Layer 1 | Prev track  | Next track | Play/Pause |

Press behavior is defined in the main `LAYOUT_ansi(...)` block (first and last slots of row 0); rotation behavior is in the `encoder_map[]` block below it.

# Notable deviations from the stock `default` keymap

- Uses `LAYOUT_ansi` instead of `LAYOUT_all` (no ISO / split-backspace / split-rshift keys).
- `MO(1)` moved from the narrow middle "FN" key to the leftmost 2.25u "Space" key; the middle key becomes a second Space.
- Right thumb `GUI` slot disabled (`KC_NO`).
- Top-right corner is `Del` (base) / `PrtSc` (layer 1) — default has `PrtSc` on base.
