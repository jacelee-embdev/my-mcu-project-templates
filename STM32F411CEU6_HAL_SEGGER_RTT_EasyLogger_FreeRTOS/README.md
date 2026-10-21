**English** | [简体中文](README_zh.md)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

# STM32F411CEU6 HAL + SEGGER RTT + EasyLogger + FreeRTOS

A reusable STM32F411CEU6 firmware template combining STM32 HAL, SEGGER RTT, EasyLogger, and FreeRTOS. It provides peripheral initialization, centralized task creation, and a small status task as a starting point for applications that need scheduling and structured debug output.

## Configuration

- HSI and PLL provide a 100 MHz system clock. TIM1 supplies the HAL time base, while FreeRTOS uses a 1000 Hz tick.
- USART1 uses PA9/TX and PA10/RX at 115200 baud, 8N1. Standard `printf` and EasyLogger output through RTT channel 0.
- CMSIS-RTOS2 initializes and starts the kernel; application resources use native FreeRTOS APIs.

## Quick start

Open `MDK-ARM/STM32F411CEU6.uvprojx` in Keil MDK 5 with ARM Compiler 5, build, and flash through SWD. Use a J-Link and RTT Viewer channel 0 to observe startup and status logs. The status task toggles the PC13 LED and logs every 500 ticks, approximately 500 ms with the current configuration. Check the LED wiring against your board.

## Reuse

Create tasks and RTOS resources in `Z02_Business/Init/os_init.c` through `OS_Init()`. Board drivers belong in `Z01_BSP`, and application tasks in `Z02_Business`. Replace or remove `Status_Task` together with its initialization and Keil references when adding application logic. Adjust logging in `Middlewares_User/EasyLogger` and peripheral settings in `STM32F411CEU6.ioc`.

After CubeMX regeneration, retain the TIM1 time base, `OS_Init()` call, logging setup, and RTT redirection. Keep the generated default task disabled and review source groups and include paths. Review logging synchronization before adding concurrent writers.

## License

This project is licensed under the **MIT License**. Copyright (c) 2026 JesMicro. See the [LICENSE](LICENSE) file in the project root for the full license text. Third-party components are subject to their respective licenses.
