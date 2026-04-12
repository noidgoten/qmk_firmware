# goten's KBD75 layout

Two layers, caps-lock RGB indicator.

## Layer 0 — base

Standard 75% ANSI, with:
- `MO(1)` right of spacebar
- `KC_HOME` at the far right of the number row
- `KC_NO` on the two unused slots at the top-right of the F-row (no physical switches there)

## Layer 1 — hold `MO(1)`

| Key | Function |
| --- | --- |
| F1 | Calculator |
| F2 | Media Select |
| `1` | `UG_TOGG` — underglow on/off |
| `W` / `A` | Brightness up / down |
| `E` / `S` | Saturation up / down |
| `R` / `D` | Hue up / down |
| `T` / `F` | Cycle mode forward / back |
| `Y` / `G` | Speed up / down |
| `\` | `QK_BOOT` (reboot into bootloader) |
| `Bksp` | `EE_CLR` (clear EEPROM) |
| `N` | `NK_TOGG` (toggle NKRO) |
| Arrow `↑` | `KC_MSTP` (media stop) |
| Arrow `←` / `↓` / `→` | Prev / Play-Pause / Next track |

## Caps-lock indicator

While Caps Lock is on, LEDs 0 and 15 of the 16-LED underglow strip turn red. Implemented with `RGBLIGHT_LAYERS` (defined in `config.h`).

The board also has a dedicated caps-lock LED on pin B2 (configured in `keyboard.json`); both indicators light up together.

## Defaults

- `RGBLIGHT_DEFAULT_HUE 180` (cyan) — initial color on first boot / after EEPROM clear.
- `rgblight.sleep: true` in board `keyboard.json` — underglow turns off when USB is suspended.

## Build

```
make kbdfans/kbd75/rev1:goten
```

Flash:

```
make kbdfans/kbd75/rev1:goten:flash
```
