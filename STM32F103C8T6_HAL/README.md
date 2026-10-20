**English** | [简体中文](README_zh.md)

# STM32F103C8T6 HAL

## Overview

A Keil bare-metal template for the STM32F103C8T6 using the HAL library. It runs at 72 MHz from an 8 MHz external crystal and includes LED, polling-delay, and USART1 drivers.

## Demo

The firmware toggles the PA4 LED every second and sends `1142!` through USART1 (PA9/PA10, 115200, 8N1). Each received frame is echoed after the USART idle-line interrupt.

## Usage

Open `Projects/MDK-ARM/STM32F103.uvprojx` with Keil MDK 5 (ARM Compiler 5), then build and flash the project.

## Layout

- `Users`: application and interrupt handlers
- `Drivers`: HAL, CMSIS, and board-level drivers
- `Projects`: Keil project files
- `Output`: build artifacts
