**English** | [简体中文](README_zh.md)

# STM32F411CEU6 HAL Typical Product Development Standard

## Overview

A complete project directory organized according to a typical product development standard. Its firmware uses the STM32F411CEU6 and HAL library, runs from the 16 MHz HSI, and includes polling-delay and USART1 drivers.

## Demo

The firmware sends `TEST,1142!` every second through USART1 (PA9/PA10, 115200, 8N1). Each received frame is echoed after the USART idle-line interrupt.

## Usage

Open `03_Firmware/01_APP/STM32F411CEU6/07_Projects/MDK-ARM/STM32F411CEU6.uvprojx` with Keil MDK 5 (ARM Compiler 5), then build and flash the project.

## Layout

- `00_Project_Management`: project management
- `02_Hardware`: hardware resources
- `03_Firmware`: application and bootloader firmware
- `04_Software`: companion software
- `05_Mechanical`, `06_FCT`, and `07_Tools`: mechanical, test, and tool resources
