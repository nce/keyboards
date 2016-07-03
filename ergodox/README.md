Ergodox
=======

## Flashing

*I used the [21ee3eb](https://github.com/jackhumbert/qmk_firmware/tree/21ee3eb569caffdf2ad581c668682c0109c978e5)
commit at the time of writing this guide.*

Qmk has a few [nice additions](https://github.com/jackhumbert/qmk_firmware/tree/21ee3eb569caffdf2ad581c668682c0109c978e5#going-beyond-the-keycodes),
and some of them are in my `ergodox` keymap, like the Space Cadet Shift.

Compiling the qmk repository was no problem at all (on 10.11). For flashing the
`teensy` the console tool need to be installed.

```
$ brew install teensy_loader_cli
```

Compiling and flashing the customized keymap is done with:

```
$ make KEYMAP=nce teensy
```

## Keymap

```
 ,--------------------------------------------------.           ,--------------------------------------------------.
 | Esc    |   1  |   2  |   3  |   4  |   5  |  =   |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 | Ctrl   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 |--------+------+------+------+------+------| Lbkt |           | Rbkt |------+------+------+------+------+--------|
 | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   |Grv/L1| Lgui |  `~  |  '"  | Lgui |                                       |  Up  | Down |   [  |   ]  | Rgui |
   `----------------------------------'                                       `----------------------------------'
                                        ,-------------.       ,--------------.
                                        | Del  | Alt  |       | Alt |Ctrl/Esc|
                                 ,------|------|------|       |------+-------+-------.
                                 |      |      | Home |       | MDIA |       |       |
                                 | Back |  Esc |------|       |------| Enter | Space |
                                 | spac |      | End  |       | PgDn |       |       |
                                `--------------------'       `----------------------'
```
