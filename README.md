**English** | [简体中文](README_zh.md)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

# Embedded Project Template Collection

## Overview

This repository collects embedded chip project templates used for everyday learning, development, and experiments. It supports cloud backup through GitHub and quick recovery after local code loss or development-environment changes. The collection is not limited to any chip vendor, processor architecture, or software framework. It currently includes projects for STMicroelectronics STM32 and Espressif ESP32-S3 devices, with room for additional platforms in the future. Each directory is an independent project that can be extended with drivers, functional modules, and experimental code.

## Templates

| Project | Platform and configuration | Framework / tools | Current contents |
|---|---|---|---|
| [ESP32-S3](ESP32_S3/) | Xtensa, 240 MHz, 16 MB flash | ESP-IDF, CMake | Empty `app_main()` and custom partition table |
| [STM32F103C8T6 HAL](STM32F103C8T6_HAL/README.md) | Cortex-M3, 72 MHz | HAL, CMSIS, Keil MDK | PA4 LED and USART1 communication |
| [STM32F103RCT6 HAL](STM32F103RCT6_HAL/README.md) | Cortex-M3, 72 MHz | HAL, CMSIS, Keil MDK | USART1 communication |
| [STM32F103ZET6 HAL](STM32F103ZET6_HAL/README.md) | Cortex-M3, 72 MHz | HAL, CMSIS, Keil MDK | USART1 communication |
| [STM32F411CEU6 HAL](STM32F411CEU6_HAL/README.md) | Cortex-M4F, 16 MHz HSI | HAL, CMSIS, Keil MDK | USART1 communication |
| [STM32F411CEU6 HAL + RTT + EasyLogger](STM32F411CEU6_HAL_SEGGER_RTT_EasyLogger/README.md) | Cortex-M4F, 100 MHz (HSI + PLL) | HAL, CMSIS, SEGGER RTT, EasyLogger, Keil MDK | Bare-metal logging and USART1 initialization |
| [STM32F411CEU6 HAL + RTT + EasyLogger + FreeRTOS](STM32F411CEU6_HAL_SEGGER_RTT_EasyLogger_FreeRTOS/README.md) | Cortex-M4F, 100 MHz (HSI + PLL) | HAL, CMSIS, SEGGER RTT, EasyLogger, FreeRTOS, Keil MDK | Centralized task creation, PC13 status LED, logging, and USART1 initialization |
| [STM32F411CEU6 HAL + RTT + EasyLogger + FreeRTOS + CmBacktrace](STM32F411CEU6_HAL_SEGGER_RTT_EasyLogger_FreeRTOS_CmBacktrace/README.md) | Cortex-M4F, 100 MHz (HSI + PLL) | HAL, CMSIS, SEGGER RTT, EasyLogger, FreeRTOS, CmBacktrace, Keil MDK | RTOS logging, USART1 initialization, and HardFault / task stack diagnostics |
| [STM32F411CEU6 HAL + RTT + EasyLogger + FreeRTOS + SystemView](STM32F411CEU6_HAL_SEGGER_RTT_EasyLogger_FreeRTOS_SystemView/README.md) | Cortex-M4F, 100 MHz (HSI + PLL) | HAL, CMSIS, SEGGER RTT, EasyLogger, FreeRTOS, SystemView, Keil MDK | RTOS task tracing with SystemView, RTT logging, PC13 status LED, and USART1 initialization |
| [STM32F411CEU6 SPL](STM32F411CEU6_SPL/README.md) | Cortex-M4F, 16 MHz HSI | SPL, CMSIS, Keil MDK | Minimal project verified on hardware |
| [STM32F411CEU6 SPL + RTT + EasyLogger](STM32F411CEU6_SPL_SEGGER_RTT_EasyLogger/README.md) | Cortex-M4F, 16 MHz HSI | SPL, CMSIS, SEGGER RTT, EasyLogger, Keil MDK | Hardware-verified real-time logging over RTT |
| [STM32F411CEU6 HAL Typical Product Development Standard](STM32F411CEU6_HAL_Typical_Product_Development_Standard/README.md) | Cortex-M4F, 16 MHz HSI | HAL, CMSIS, Keil MDK | Base firmware and a typical product development directory structure |

## Development Environments

- The STM32 projects use Keil MDK 5, ARM Compiler 5, STM32 HAL or SPL, and CMSIS for building, with SWD for programming and debugging.
- The ESP32-S3 project uses ESP-IDF and CMake. Its project configuration is stored in `sdkconfig`, and its application entry point is in `main/main.c`.
- Each platform retains its native project layout and build workflow. Refer to the documentation and project files in the corresponding directory for exact settings.

## Quick Start

1. Clone or download this repository and select a template that matches the target device and development environment.
2. Read the template documentation and check its clock, pin, flash, and debug-interface settings.
3. Install the toolchain for the selected platform, then open the Keil project or load the ESP-IDF project to build and flash it.
4. Verify the base project before adding experimental code. Keeping an unchanged copy or using a separate branch is recommended so that a known-good version remains available for recovery and testing.

## Directory Conventions

STM32 directory names follow `Device_Library[_SEGGER_RTT][_EasyLogger][_FreeRTOS][_CmBacktrace][_SystemView]`, listing only integrated components. An omitted OS suffix indicates bare-metal firmware. The `Typical_Product_Development_Standard` suffix identifies the complete directory layout organized for typical product development.

The standard STM32 templates organize code under `Users`, `Drivers`, `Projects`, and `Output`. The HAL + RTT series uses a CubeMX layout with `Core`, `Drivers`, `MDK-ARM`, and `Middlewares_User`; its FreeRTOS variants also include `Middlewares`, `Z01_BSP` for board drivers, and `Z02_Business` for application tasks. The full project folder template also provides categories for project management, hardware, software, mechanical design, testing, and tools. The ESP32-S3 project follows the ESP-IDF layout with a root CMake configuration, `sdkconfig`, and a `main` component. Future platforms may follow their official or team-specific structures and do not need to use a single forced layout.

## Notes

- Before use, verify the clock, pin assignments, storage capacity, and programming settings against the actual device, development board, and schematic.
- After changing the system clock or low-level configuration, review related delay, serial-port, and partition implementations.
- The root `.gitignore` filters common Keil-generated files. When adding another platform, review its build directories and add the appropriate ignore rules.

## License

This project is licensed under the **MIT License**. Copyright (c) 2026 JesMicro. See the [LICENSE](LICENSE) file in the project root for the full license text. Third-party components are subject to their respective licenses.
