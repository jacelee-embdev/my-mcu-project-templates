**English** | [简体中文](README_zh.md)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

# STM32F411CEU6 HAL + SEGGER RTT + EasyLogger

A reusable bare-metal firmware template for STM32F411CEU6. It combines STM32 HAL peripheral initialization, SEGGER RTT debug output, and EasyLogger so application development can start with a working logging foundation. The project includes its CubeMX configuration and Keil project, allowing peripheral settings and application code to evolve together.

## Configuration

- Cortex-M4F running at 100 MHz from the internal HSI through the PLL; HAL uses SysTick as its time base.
- USART1 uses PA9 for TX and PA10 for RX, configured for 115200 baud, 8 data bits, no parity, and one stop bit.
- Standard `printf` and EasyLogger share RTT channel 0. Logging is synchronous and supports levels, colors, timestamps, and module tags.

## Quick start

Open `MDK-ARM/STM32F411CEU6.uvprojx` in Keil MDK 5 with ARM Compiler 5, build, and flash through SWD. Connect a J-Link and open RTT Viewer on channel 0. The main loop emits sample messages approximately every two seconds. USART1 remains available for application communication; log output goes through RTT.

## Reuse

Add application code in `Core/Src/main.c`. Logging setup is in `Middlewares_User/EasyLogger/debug/debug.c`, options are in `Middlewares_User/EasyLogger/inc/elog_cfg.h`, and `printf` redirection is in `Core/Src/usart.c`. Drivers and middleware retain their existing directories.

Before changing hardware, review clock and pin settings in `STM32F411CEU6.ioc`. After CubeMX regeneration, check middleware source groups, include paths, and user code. When adding an RTOS, move the HAL time base to a separate timer and adapt log synchronization.

## License

This project is licensed under the **MIT License**. Copyright (c) 2026 JesMicro. See the [LICENSE](LICENSE) file in the project root for the full license text. Third-party components are subject to their respective licenses.
