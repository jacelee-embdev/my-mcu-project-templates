**English** | [简体中文](README_zh.md)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

# STM32F411CEU6 HAL

## Overview

A Keil bare-metal template for the STM32F411CEU6 using the HAL library. It runs from the 16 MHz internal HSI and includes polling-delay and USART1 drivers.

## Demo

The firmware sends `TEST,1142!` every second through USART1 (PA9/PA10, 115200, 8N1). Each received frame is echoed after the USART idle-line interrupt.

## Usage

Open `Projects/MDK-ARM/STM32F411CEU6.uvprojx` with Keil MDK 5 (ARM Compiler 5), then build and flash the project.

## Layout

- `Users`: application and interrupt handlers
- `Drivers`: HAL, CMSIS, and system drivers
- `Projects`: Keil project files
- `Output`: build artifacts

## License

This project is licensed under the **MIT License**. Copyright (c) 2026 JesMicro. See the [LICENSE](LICENSE) file in the project root for the full license text. Third-party components are subject to their respective licenses.
