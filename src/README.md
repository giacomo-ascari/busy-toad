# Source code

## Organization

The development relies on a CubeMX + cmake toolchain. The code for the primary MCU is `bt_h750`, while the secondary's one is found in `bt_h523`.

## How to stuff

### Flash #1

After having built the `.elf` file all is left to do is to flash it.

On terminal 1:

- `st-info --probe` giusto per vedere se legge la roba
- `st-util` per lanciare partire il server gdb. importante!

On terminal 2:

- `gdb-multiarch PATH_TO_ELF`
- `(gdb) target extended-remote localhost:4242`
- `(gdb) load`
- `(gdb) continue`

### Flash #2

`STM32_Programmer_CLI -c port=SWD mode=UR reset=HWrst -w build/Debug/bt_h750.elf -v -rst`

### Flash #3

Trust VSCode.


