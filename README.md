# busy-toad

## Intro

Evolution of the digital pedal geekyToad. This page is a list of features/hardware that I would like to implement. Nothing is set in stone of course, but it's just a place to collect interesting stuff and ideas.

## System

### I/O

The majority of the inputs is a straight up copy of geekyToad with some additions and optimizations.
- Two instr/line/mic/mic48v inputs as XLR Combo Jack
- Two instr/line outputs as XLR Combo Jack
- OLED display, power LED, two non-assigned (yet) LEDs
- Two rotary encoders with push buttons
- Mute/unmute button, Next/previous tab buttons
- Volume knob, Expression pedal input (TS) (one for every ADC available)
- USB host

### Features

- Effect chain for every input
- Drum machine (samples + synth)
- Mixing matrix

## Hardware

### MCU - STM32H750VBT6

- LQFP100 14x14x1.4mm
- ARM Cortex-M7, 480MHz, FPU, 128kB flash, 1024kB RAM
- [mouser link](https://www.mouser.dk/ProductDetail/STMicroelectronics/STM32H750VBT6?qs=sGAEpiMZZMuI9neUTtPr7zWYd8yNnBbm60PgquT%2FyNhWon6x3TDxMg%3D%3D)

### CODEC - PCM3060

- same codec as the daisy seed
- [ti link](https://www.ti.com/product/PCM3060#features)

Honorable mention: tlv320aic3104-21

### FLASH - N/A

- serial flash memory ???
Honorable mention: w25q512jv

### DISPLAY - 3.83" OLED

- 3.83" OLED module, 320x132, 4-wire SPI, 16 level grayscale
- looks really interesting and promising, especially for the grayscale control (could have controllable brightness and such)
- framerate unknow, but still probably better than normal lcd displays
- [buydisplay link](https://www.buydisplay.com/catalog/product/view/id/1847/s/arduino-raspberry-pi-3-83-inch-oled-module-320x132-spi-16-level-grayscale/)

## Various notes

- STM32 Cube IDE
- [colori belli](https://coolors.co/30bced-303036-fffaff-fc5130-050401)
- [Differences-between-Mic-Line-and-Instrument-level](https://support.focusrite.com/hc/en-gb/articles/115004171025-Differences-between-Mic-Line-and-Instrument-level)
