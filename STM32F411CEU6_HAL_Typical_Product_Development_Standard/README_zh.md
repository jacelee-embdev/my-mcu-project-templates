**简体中文** | [English](README.md)

# STM32F411CEU6 HAL 典型产品开发规范

## 简介

按典型产品开发规范组织的完整工程目录模板。固件基于 STM32F411CEU6 和 HAL 库，采用 16 MHz HSI，集成查询式延时和 USART1 收发。

## 示例

程序每秒由 USART1（PA9/PA10，115200，8N1）发送 `TEST,1142!`；收到一帧数据后通过空闲中断回显。

## 使用

使用 Keil MDK 5（ARM Compiler 5）打开 `03_Firmware/01_APP/STM32F411CEU6/07_Projects/MDK-ARM/STM32F411CEU6.uvprojx`，编译并下载。

## 目录

- `00_Project_Management`：项目管理
- `02_Hardware`：硬件资料
- `03_Firmware`：应用与 Bootloader
- `04_Software`：配套软件
- `05_Mechanical`、`06_FCT`、`07_Tools`：结构、测试与工具
