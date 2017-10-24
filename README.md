# Infinity Clock Project

A infinity clock is basically an RGB LED strip between two mirrors, one which is semi-transparent. My implementation uses an `STM32F103` microcontroller for control. This repository contains the `GNU ARM Eclipse` that runs on this controller.

## Hardware components

To assemble this project yourself, you're going to need:
* an `STM32F103C8T6` MCU, preferably the _STM32 Min System Dev Board_ that you can by on eBay
* a `WS2812` RGB LED strip with 60 LED's
* a rotary switch with QEP output signal and button
* other hardware elements (the mirrors and a frame)

## Pinout

The **STM32 Min System Dev Board**'s pins are connected to external components as follows:
* **PB3** : LED strip data in
* **PA0** : logical 1 (connected to rotary switch _COM_ input)
* **PA1** : push button (on rotary switch)
* **PA2** : QEP channel A
* **PA3** : QEP channel B

## Usage

The rotary switch can be used to adjust brightness in default state.

To adjust the current time, keep the button down for about a second (_long press_), then use the rotary to set the _hour hand_, press the button (_short_) to move on to setting the _minute hand_, and so on.
