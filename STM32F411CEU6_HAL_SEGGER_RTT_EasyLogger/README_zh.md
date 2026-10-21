**简体中文** | [English](README.md)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

# STM32F411CEU6 HAL + SEGGER RTT + EasyLogger

本工程是可直接复用的 STM32F411CEU6 裸机模板，集成 HAL 外设初始化、SEGGER RTT 调试输出与 EasyLogger 日志，保留 CubeMX 配置和 Keil 工程，便于在现有基础上扩展驱动和业务代码。

## 基础配置

- HSI 经 PLL 倍频至 100 MHz，HAL 使用 SysTick 时基。
- USART1：PA9/TX、PA10/RX，115200 baud、8N1。
- `printf` 与 EasyLogger 共用 RTT 通道 0，采用同步输出，支持日志等级、颜色、时间和模块标签。

## 快速使用

使用 Keil MDK 5 / ARM Compiler 5 打开 `MDK-ARM/STM32F411CEU6.uvprojx`，编译并通过 SWD 下载。连接 J-Link，在 RTT Viewer 中查看通道 0；主循环约每两秒输出一组示例日志。日志通过 RTT 输出，USART1 可用于业务通信。

## 扩展入口

业务代码从 `Core/Src/main.c` 扩展；日志初始化位于 `Middlewares_User/EasyLogger/debug/debug.c`，配置位于 `Middlewares_User/EasyLogger/inc/elog_cfg.h`，`printf` 重定向位于 `Core/Src/usart.c`。

更换硬件前，请检查 `STM32F411CEU6.ioc` 中的时钟与引脚。CubeMX 重新生成代码后，核对中间件分组、头文件路径和用户代码。后续接入 RTOS 时，应调整 HAL 时基并适配日志同步机制。

## 许可证

本项目采用 **MIT License** 开源许可证。Copyright (c) 2026 JesMicro。完整条款请参阅根目录的 [LICENSE](LICENSE) 文件。第三方组件遵循各自的许可证。
