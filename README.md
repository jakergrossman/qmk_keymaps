# My QMK firmwares
Uses GNU stow to install keymaps into `$QMK_HOME` to avoid having to maintain a personal fork of QMK.

## Firmware
Firmware files are generated via [GitHub action](.github/workflows/build.yml) and are available for download
in the Actions section.

## Building
Use the provided install script to place the keymaps in the appropriate place with `stow`:

```
git clone https://github.com/jakergrossman/qmk_keymaps
cd qmk_keymaps
./install
```

A list of keyboards and keymaps is printed.
Then compile the keymap as you would any other (`qmk compile -kb <keyboard> -km <keymap>`).

To uninstall, use `./install -D`
