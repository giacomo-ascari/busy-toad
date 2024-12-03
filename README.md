# busy-toad

## Intro

Evolution of the digital pedal geekyToad. This page is a list of features/hardware that I would like to implement. Nothing is set in stone of course, but it's just a place to collect interesting stuff and ideas.

## System

### I/O

- Two audio instr/line inputs as TRS Jack (differential or single-ended)
- Two audio instr/line outputs as TRS Jack (differential or single-ended)
- One stereo output for headphones, hardwired to the two outputs
- OLED display, power LED, some non-assigned (yet) LEDs
- A lot of buttons and One rotary encoder with push button
- Volume knobs for heaphones
- Two digital inputs as TS Jack (e.g. stomp buttons)
- Two analog inputs as TRS Jack (e.g. expression pedals)
- USB C device for power and FS data transfer

### Features

- Two effect chains (primary and secondary)
- Programmable digital/analog inputs as dynamic controls of effects
- Drum machine (synth + samples)
- Chromatic tuner
- Mixing matrix for effect chains and drum machine
- Display brightness control

## Hardware

### MCU - STM32H750VBT6

- LQFP100 14x14x1.4mm
- ARM Cortex-M7, 480MHz, FPU, 128kB flash, 1024kB RAM
- [mouser link](https://www.mouser.dk/ProductDetail/STMicroelectronics/STM32H750VBT6?qs=sGAEpiMZZMuI9neUTtPr7zWYd8yNnBbm60PgquT%2FyNhWon6x3TDxMg%3D%3D)

### CODEC - CS4272

- same codec on some focusrite scarlet interfaces [apparently](https://khronscave.blogspot.com/2019/10/55-focusrite-scarlett-2i2-teardown.html)
- it just works. no fancy headphone/microphones things. low-power portable electronics are overrated
- [cirrus logic link](https://www.cirrus.com/products/cs4272/)

Honorable mentions:
- E.D.'s favorite: tlv320aic3104-21
- daisy seed's: pcm3060 [ti link](https://www.ti.com/product/PCM3060#features)

### FLASH - W25Q512JV

- w25q512jveim (still on the table!)
- the quad spi interface with the mcu needs a lot of pins :/

### DISPLAY - 3.83" OLED

- 3.83" OLED module, 320x132, 4-wire SPI, 16 level grayscale
- looks really interesting and promising, especially for the grayscale control (could have controllable brightness and such)
- framerate unknow, but still probably better than normal lcd displays
- [buydisplay link](https://www.buydisplay.com/catalog/product/view/id/1847/s/arduino-raspberry-pi-3-83-inch-oled-module-320x132-spi-16-level-grayscale/)
- ALTERNATIVE: ILI9341 SPI LCD display (the usual basically)

## Various notes

- STM32 Cube IDE because yes.
- Debugging is done with cortex 4-wire-jtag/swd 10 pin connection.
- This version will only feature one MCU. I feel like this should be a mix of prototype/learning experience and functional product.
- For the Eq: Linkwitz–Riley filters
- circuitry for codec I/O:
  - INA116: instrumentation amplifier with extremely low input bias
  - INA105 and 106: differential amplifiers with unit and fixed gain
  - INA1620: beast, dual differential signals amp
  - INA321 and 2321: instrumentation amplifiers, also dual channel
  - MCP6001/1R/1U/2/4: low power opamp used in gt
  - Quad Analog Switch/ Multiplexer/Demultiplexer MC74HC4066A
- For the switching circuitry
  - MC74HC4066A (same as the focusrite, but apparently a little bit noisy)
  - TS5A3157
  - DG409 / DG410
  - MAX4617 (chatgpt likes this)
  - ADG736 (I like this one!) / ADG734 / ADG1606
  - TS5A3157
  - MAX14689
- Available in lab
  - CA3140 (opamp)
  - MCP6294 (quad opamp)
  - MCP602 (dual op amp)
  - LM358 (dual op amp)
  - LM386N (audio amp)
  - AD623ANZ (opamp dif amp)
  - AD620ANZ (opamp dif amp)
- Expression pedals are hard man [...](https://missionengineering.com/understanding-expression-pedals/)
- I'm extremely dubious about the feasibility of the 48v phantom power for condenser microphones. A solution can be just buying an external mic pre-amp.
- [cool colors, i like them](https://coolors.co/30bced-303036-fffaff-fc5130-050401)
- [Differences-between-Mic-Line-and-Instrument-level](https://support.focusrite.com/hc/en-gb/articles/115004171025-Differences-between-Mic-Line-and-Instrument-level)
