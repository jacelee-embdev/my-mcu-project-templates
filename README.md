**English** | [简体中文](README_zh.md)

# Embedded Project Template Collection

## Overview

This repository collects embedded chip project templates used for everyday learning, development, and experiments. It supports cloud backup through GitHub and quick recovery after local code loss or development-environment changes. The collection is not limited to any chip vendor, processor architecture, or software framework. It currently includes projects for STMicroelectronics STM32 and Espressif ESP32-S3 devices, with room for additional platforms in the future. Each directory is an independent project that can be extended with drivers, functional modules, and experimental code.

## Templates

| Project | Platform and configuration | Framework / tools | Current contents |
|---|---|---|---|
| [ESP32-S3](ESP32_S3/) | Xtensa, 240 MHz, 16 MB flash | ESP-IDF, CMake | Empty `app_main()` and custom partition table |
| [STM32F103C8T6](STM32F103C8T6_Template/README.md) | Cortex-M3, 72 MHz | HAL, CMSIS, Keil MDK | PA4 LED and USART1 communication |
| [STM32F103RCT6](STM32F103RCT6_Template/README.md) | Cortex-M3, 72 MHz | HAL, CMSIS, Keil MDK | USART1 communication |
| [STM32F103ZET6](STM32F103ZET6_Template/README.md) | Cortex-M3, 72 MHz | HAL, CMSIS, Keil MDK | USART1 communication |
| [STM32F411CEU6](STM32F411CEU6_Template/README.md) | Cortex-M4F, 16 MHz HSI | HAL, CMSIS, Keil MDK | USART1 communication |
| [STM32F411CEU6 Full Project Folder](STM32F411CEU6_EmbeddedProject_Folder_Template/README.md) | Cortex-M4F, 16 MHz HSI | HAL, CMSIS, Keil MDK | Base firmware and a complete project structure |

## Development Environments

- The STM32 projects use Keil MDK 5, ARM Compiler 5, the STM32 HAL library, and CMSIS for building, with SWD for programming and debugging.
- The ESP32-S3 project uses ESP-IDF and CMake. Its project configuration is stored in `sdkconfig`, and its application entry point is in `main/main.c`.
- Each platform retains its native project layout and build workflow. Refer to the documentation and project files in the corresponding directory for exact settings.

## Quick Start

1. Clone or download this repository and select a template that matches the target device and development environment.
2. Read the template documentation and check its clock, pin, flash, and debug-interface settings.
3. Install the toolchain for the selected platform, then open the Keil project or load the ESP-IDF project to build and flash it.
4. Verify the base project before adding experimental code. Keeping an unchanged copy or using a separate branch is recommended so that a known-good version remains available for recovery and testing.

## Directory Conventions

The standard STM32 templates organize code under `Users`, `Drivers`, `Projects`, and `Output`. The full project folder template also provides categories for project management, hardware, software, mechanical design, testing, and tools. The ESP32-S3 project follows the ESP-IDF layout with a root CMake configuration, `sdkconfig`, and a `main` component. Future platforms may follow their official or team-specific structures and do not need to use a single forced layout.

## Notes

- Before use, verify the clock, pin assignments, storage capacity, and programming settings against the actual device, development board, and schematic.
- After changing the system clock or low-level configuration, review related delay, serial-port, and partition implementations.
- The root `.gitignore` filters common Keil-generated files. When adding another platform, review its build directories and add the appropriate ignore rules.

## License

This project is released under the [MIT License](LICENSE).
