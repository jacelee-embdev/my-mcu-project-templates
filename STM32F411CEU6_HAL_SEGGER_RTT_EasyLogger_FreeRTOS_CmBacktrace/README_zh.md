**简体中文** | [English](README.md)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

# STM32F411CEU6 HAL + SEGGER RTT + EasyLogger + FreeRTOS + CmBacktrace

本工程在 HAL、RTT、EasyLogger 和 FreeRTOS 基础上集成 CmBacktrace，提供 HardFault 诊断与任务栈回溯能力，可作为需要运行故障分析的 STM32F411CEU6 项目起点。

## 基础配置

- HSI 经 PLL 倍频至 100 MHz；HAL 使用 TIM1 时基，FreeRTOS 节拍频率为 1000 Hz。
- USART1：PA9/TX、PA10/RX，115200 baud、8N1。
- `printf`、EasyLogger 和 CmBacktrace 共用 RTT 通道 0；状态任务提供 PC13 LED 翻转和周期日志。

## 快速使用

使用 Keil MDK 5 / ARM Compiler 5 打开 `MDK-ARM/STM32F411CEU6.uvprojx`，编译并通过 SWD 下载。连接 J-Link，在 RTT Viewer 通道 0 查看输出。复用时在 `Core/Src/main.c` 中修改固件名称和版本标识，并保留对应构建的可执行文件，便于后续地址解析及调用栈分析。

## 扩展入口

在 `Z02_Business/Init/os_init.c` 的 `OS_Init()` 中创建任务；板级驱动放在 `Z01_BSP`，业务任务放在 `Z02_Business`。日志与故障分析组件位于 `Middlewares_User`。

CubeMX 重新生成代码前，备份 FreeRTOS 目录；生成后保留 TIM1 时基、`OS_Init()`、日志初始化及 RTT 重定向，继续禁用默认任务。`HardFault_Handler()` 由 `cmb_fault.S` 提供，生成的同名 C 实现须保持禁用。保留 FreeRTOS `Source/tasks.c` 和 `Source/include/FreeRTOS.h` 中的 CmBacktrace 适配；升级内核时应重新核对并移植这些修改。

## 许可证

本项目采用 **MIT License** 开源许可证。Copyright (c) 2026 JesMicro。完整条款请参阅根目录的 [LICENSE](LICENSE) 文件。第三方组件遵循各自的许可证。
