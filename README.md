# Custom Keyboards

This is a collection of all my keyboard business.

  * [GH60 China Clone](gh60-hx/README.md)

## Firmware Flashing

*Note: this is a guide for a MacOS Setup using the
[d4982a2](https://github.com/tmk/tmk_keyboard/tree/d4982a21ac8f3ba003da41ceb581bffb4e78fefa) commit of the tmk repo*

Flashing a new Layout is pretty straightforward with the - non graphical -
[tmk](https://github.com/tmk/tmk_keyboard) suite. The necessary tools are
the `AVR Toolchain` and `dfu-programmer` (more on that, in the build
instructions there).

After setting up the custom key layout, compile the layout to a hex file by
running `make` in the respective directory of the cloned tmk repo.

By copying (my) keymaps in the directory, they can be compiled via:

```
$ make KEYMAP=name
```

Where `name` is representing the filename of the custom layout
(eg. `keymap_name.c`).

The resulting hex file can now be flashed onto the connected keyboard,
after **a short press on the
button on the bottom** of the keyboard and running:

```
$ make dfu
```

# DIY Usb Cable
This is a reference for the parts i use to create DIY usb(2.0) cables.

## Parts

Description | Conrad Part # | est. Price | Conrad Link
----------- | ------------- | ---------- | ----------
USB A Metal | 747013        | 1.00 €     | [USB A Metal](https://www.conrad.de/de/selbstkonfektionierbarer-usb-a-steckverbinder-stecker-gerade-10120098-usb-a-bkl-electronic-inhalt-1-st-747013.html)
USB Micro   | n.a. | ... |
USB Mini Metal | 730789        | 1.09 €     | [USB Mini Metal](https://www.conrad.de/de/mini-usb-stecker-20-stecker-gerade-10120252-mini-usb-b-bkl-electronic-inhalt-1-st-730789.html)
4x0.14mm² Kabel | 608205 | 1.49€/m | [Mikrofonkabel](https://www.conrad.de/de/mikrofonkabel-4-x-014-mm-schwarz-lappkabel-49900009-meterware-608205.html)


### Heat Shrink

2:1 Heatshrinks should be okay. Even for USB A

Connector | rec. Size
--------- | ---------
USB A     | 9.5mm
Micro USB | 6.4mm
Mini USB  | 6.4mm

### Paracord

2mm is fine for the above mentioned cable
