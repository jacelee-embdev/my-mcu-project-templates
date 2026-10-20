**简体中文** | [English](README.md)

# STM32F411CEU6 HAL + SEGGER RTT + EasyLogger + FreeRTOS

本工程是集成 HAL、SEGGER RTT、EasyLogger 和 FreeRTOS 的 STM32F411CEU6 模板，提供外设初始化、统一任务创建入口及基础状态任务，适合需要任务调度和日志输出的项目。

## 基础配置

- HSI 经 PLL 倍频至 100 MHz；HAL 使用 TIM1 时基，FreeRTOS 节拍频率为 1000 Hz。
- USART1：PA9/TX、PA10/RX，115200 baud、8N1；`printf` 与 EasyLogger 通过 RTT 通道 0 输出。
- CMSIS-RTOS2 负责内核初始化与启动，业务资源使用 FreeRTOS 原生接口创建。

## 快速使用

使用 Keil MDK 5 / ARM Compiler 5 打开 `MDK-ARM/STM32F411CEU6.uvprojx`，编译并通过 SWD 下载。连接 J-Link，在 RTT Viewer 通道 0 查看启动与状态日志。状态任务每隔 500 个节拍（约 500 ms）翻转 PC13 LED 并输出日志，使用前请核对开发板接线。

## 扩展入口

在 `Z02_Business/Init/os_init.c` 的 `OS_Init()` 中创建任务和资源；板级驱动放在 `Z01_BSP`，业务任务放在 `Z02_Business`。可替换状态任务，并同步调整初始化代码及 Keil 引用。日志配置位于 `Middlewares_User/EasyLogger`，外设配置位于 `STM32F411CEU6.ioc`。

CubeMX 重新生成代码后，保留 TIM1 时基、`OS_Init()`、日志初始化及 RTT 重定向，继续禁用默认任务，并核对分组和头文件路径。增加并发日志输出前，应检查同步机制。

项目条款见 [LICENSE](LICENSE)，第三方组件遵循各自许可证。
