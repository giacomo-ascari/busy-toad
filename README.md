# busy-toad

## Intro

Evolution of the digital pedal geekyToad. This page is a list of features/hardware that I would like to implement. Nothing is set in stone of course, but it's just a place to collect interesting stuff and ideas.

## System

### I/O

The majority of the inputs is a straight up copy of geekyToad with some additions and optimizations.
- Two instr/line/mic/mic48v inputs as XLR Combo Jack
- Two instr/line outputs as XLR Combo Jack
- One stereo output for headphones
- OLED display, power LED, two non-assigned (yet) LEDs
- Two rotary encoders with push buttons
- Next/previous tab buttons
- Volume knobs for effects/drummachine/master, mute/unmute stomp button, expression pedal input (TS) amap
- SD card to load samples for drummachine into the flash

### Features

- Effect chain for every input (with programmable expression pedals)
- Drum machine (samples + synth)
- Mixing matrix for effect chains and drum machine
- Display brightness control

## Hardware

### MCU - STM32H750VBT6

- LQFP100 14x14x1.4mm
- ARM Cortex-M7, 480MHz, FPU, 128kB flash, 1024kB RAM
- [mouser link](https://www.mouser.dk/ProductDetail/STMicroelectronics/STM32H750VBT6?qs=sGAEpiMZZMuI9neUTtPr7zWYd8yNnBbm60PgquT%2FyNhWon6x3TDxMg%3D%3D)

### CODEC - CS4272

- same codec on some focusrite scarlet interfaces
- [cirrus logic link](https://www.cirrus.com/products/cs4272/)

Honorable mentions:
- E.D.'s favorite: tlv320aic3104-21
- daisy seed's: pcm3060 [ti link](https://www.ti.com/product/PCM3060#features)

### FLASH - N/A

- serial flash memory ???

Honorable mention:
- w25q512jv (still on the table!)

### DISPLAY - 3.83" OLED

- 3.83" OLED module, 320x132, 4-wire SPI, 16 level grayscale
- looks really interesting and promising, especially for the grayscale control (could have controllable brightness and such)
- framerate unknow, but still probably better than normal lcd displays
- [buydisplay link](https://www.buydisplay.com/catalog/product/view/id/1847/s/arduino-raspberry-pi-3-83-inch-oled-module-320x132-spi-16-level-grayscale/)

## Various notes

- STM32 Cube IDE because yes.
- Debugging is done with cortex jtag/swd 10 pin connection.
- This version will only feature one MCU. I feel like this should be a mix of prototype/learning experience and functional product.
- circuitry for codec I/O:
  - INA116: instrumentation amplifier with extremely low input bias
  - INA105 and 106: differential amplifiers with unit and fixed gain
  - INA1620: beast, dual differential signals amp
  - INA321 and 2321: instrumentation amplifiers, also dual channel
  - MCP6001/1R/1U/2/4: low power opamp used in gt
  - 
- I'm extremely dubious about the feasibility of the 48v phantom power for condenser microphones. A solution can be just buying an external mic pre-amp.
- [nice colors, i like them](https://coolors.co/30bced-303036-fffaff-fc5130-050401)
- [Differences-between-Mic-Line-and-Instrument-level](https://support.focusrite.com/hc/en-gb/articles/115004171025-Differences-between-Mic-Line-and-Instrument-level)
