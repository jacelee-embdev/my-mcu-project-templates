**简体中文** | [English](README.md)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

# STM32F103RCT6 HAL

## 简介

基于 STM32F103RCT6 与 HAL 库的 Keil 裸机模板。采用 8 MHz 外部晶振，主频 72 MHz，集成查询式延时和 USART1 收发。

## 示例

程序每秒由 USART1（PA9/PA10，115200，8N1）发送 `1142!`；收到一帧数据后通过空闲中断回显。

## 使用

使用 Keil MDK 5（ARM Compiler 5）打开 `Projects/MDK-ARM/stm32f103.uvprojx`，编译并下载。

## 目录

- `Users`：应用与中断
- `Drivers`：HAL、CMSIS 及系统驱动
- `Projects`：Keil 工程
- `Output`：编译输出

## 许可证

本项目采用 **MIT License** 开源许可证。Copyright (c) 2026 JesMicro。完整条款请参阅根目录的 [LICENSE](LICENSE) 文件。第三方组件遵循各自的许可证。
