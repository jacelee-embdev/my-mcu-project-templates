**English** | [简体中文](README_zh.md)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

# STM32F411CEU6 HAL + SEGGER RTT + EasyLogger + FreeRTOS + CmBacktrace

A reusable STM32F411CEU6 firmware template combining HAL peripherals, RTT logging, FreeRTOS scheduling, and CmBacktrace fault diagnostics. It extends the logging and RTOS foundation with a HardFault entry point and task stack information, providing a starting point for applications that need runtime fault analysis.

## Configuration

- HSI and PLL provide a 100 MHz system clock; TIM1 supplies the HAL time base, and FreeRTOS uses a 1000 Hz tick.
- USART1 uses PA9/TX and PA10/RX at 115200 baud, 8N1.
- Standard `printf`, EasyLogger, and CmBacktrace diagnostics use RTT channel 0. A status task toggles the PC13 LED and emits periodic logs.

## Quick start

Open `MDK-ARM/STM32F411CEU6.uvprojx` in Keil MDK 5 with ARM Compiler 5, build, and flash through SWD. Connect a J-Link and inspect RTT Viewer channel 0. Set firmware identification and version strings in `Core/Src/main.c` when adapting the template to a product. Keep the matching build executable for subsequent address and call-stack analysis.

## Reuse

Create application tasks in `Z02_Business/Init/os_init.c` through `OS_Init()`. Board drivers live in `Z01_BSP`; application tasks live in `Z02_Business`. Logging and fault-analysis components are under `Middlewares_User`.

Before CubeMX regeneration, back up the FreeRTOS directory. Afterwards, preserve TIM1, the `OS_Init()` call, logging initialization, and RTT redirection; keep the default task disabled. The generated `HardFault_Handler()` must remain disabled because `cmb_fault.S` supplies the entry point. Preserve CmBacktrace adaptations in FreeRTOS `Source/tasks.c` and `Source/include/FreeRTOS.h`; review and reapply them when upgrading the kernel.

## License

This project is licensed under the **MIT License**. Copyright (c) 2026 JesMicro. See the [LICENSE](LICENSE) file in the project root for the full license text. Third-party components are subject to their respective licenses.
