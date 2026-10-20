**English** | [简体中文](README_zh.md)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

# STM32F411CEU6 SPL

This is a basic STM32F411CEU6 project template based on the STM32F4 Standard Peripheral Library (SPL). It can be used as the starting point for future projects.

The project has been verified by building and running it on hardware. It can be downloaded successfully and reaches `main()`.

## Development Environment

- Keil MDK-ARM 5.38
- Arm Compiler 5.06 update 7
- Keil STM32F4xx DFP 2.17.1
- STM32F4xx SPL (STSW-STM32065 V1.9.0)

## Project Structure

```text
STM32F411CEU6_SPL
├── BSP
├── Core
│   ├── Inc
│   └── Src
├── Drivers
│   ├── CMSIS
│   └── STM32F4xx_StdPeriph_Driver
├── MDK-ARM
├── Middlewares
├── OBJ
├── SYSTEM
├── Tasks
├── .gitignore
├── LICENSE
├── README.md
└── README_zh.md
```

## Usage

1. Open `MDK-ARM/STM32F411CEU6_SPL.uvprojx` with Keil.
2. Build the project.
3. Configure ST-Link and download the program to the target board.
4. Add BSP, logging, RTOS, or application code as needed.

This template does not include serial logging, EZ-LOG, RTT, or application-specific features.

## Verification Status

- Build result: 0 errors, 0 warnings
- Startup file: `startup_stm32f411xe.s`
- Target MCU: STM32F411CEU6
- Verified with ST-Link to reach `main()` and continue running

## License

This project is licensed under the [MIT License](LICENSE).

Copyright (c) 2026 JesMicro
