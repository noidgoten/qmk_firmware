# goten's GMMK Pro layout

Two layers, caps-lock indicator on the left column.

## Layer 0 — base

Standard ANSI, with these deviations from the stock `default`:
- Top-right corner: `KC_DEL` (default has `KC_PSCR`)
- Right of `Bksp`: `KC_HOME` (default has `KC_DEL`)
- `MO(1)` right of spacebar (same as default)

## Layer 1 — hold `MO(1)`

| Row | Key | Function |
| --- | --- | --- |
| F-row | F1 | Calculator |
| F-row | F2 | Media Select |
| `1` | — | RGB toggle (`RM_TOGG`) |
| `W` / `A` | — | Brightness up / down (`RM_VALU` / `RM_VALD`) |
| `E` / `S` | — | Saturation up / down |
| `R` / `D` | — | Hue up / down |
| `T` / `F` | — | Cycle mode forward / back |
| `Y` / `G` | — | Speed up / down |
| `\` | — | `QK_BOOT` (reboot into bootloader) |
| `N` | — | `NK_TOGG` (toggle NKRO) |
| Arrow `↑` | — | `KC_MSTP` (media stop) |
| Arrow `←` / `↓` / `→` | — | Prev / Play-Pause / Next track |

## Encoder (rotary knob)

| Layer | CCW | CW |
| --- | --- | --- |
| 0 | Volume down | Volume up |
| 1 | Prev RGB mode | Next RGB mode |

## Caps-lock indicator

While Caps Lock is on, the five LEDs of the leftmost column (~, Tab, Caps, LShift, LCtrl) turn red. Implemented in `rgb_matrix_indicators_user()`.

## Build

```
make gmmk/pro/rev1/ansi:goten
```

Flash:

```
make gmmk/pro/rev1/ansi:goten:flash
```
