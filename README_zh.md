**简体中文** | [English](README.md)

# 嵌入式工程模板合集

## 项目简介

本仓库集中保存日常学习、开发和实验使用的嵌入式芯片工程模板，便于通过 GitHub 进行云端备份，并在本地代码丢失或开发环境变更后快速恢复。仓库不限定芯片厂商、处理器架构或软件框架；目前收录了意法半导体 STM32 和乐鑫 ESP32-S3 工程，后续可继续加入其他平台。每个目录均作为独立工程使用，可在其基础上添加驱动、功能模块和实验代码。

## 模板一览

| 工程 | 平台与配置 | 开发框架 / 工具 | 当前内容 |
|---|---|---|---|
| [ESP32-S3](ESP32_S3/) | Xtensa，240 MHz，16 MB Flash | ESP-IDF、CMake | 空白 `app_main()` 与自定义分区表 |
| [STM32F103C8T6](STM32F103C8T6_Template/README_zh.md) | Cortex-M3，72 MHz | HAL、CMSIS、Keil MDK | PA4 LED、USART1 收发 |
| [STM32F103RCT6](STM32F103RCT6_Template/README_zh.md) | Cortex-M3，72 MHz | HAL、CMSIS、Keil MDK | USART1 收发 |
| [STM32F103ZET6](STM32F103ZET6_Template/README_zh.md) | Cortex-M3，72 MHz | HAL、CMSIS、Keil MDK | USART1 收发 |
| [STM32F411CEU6](STM32F411CEU6_Template/README_zh.md) | Cortex-M4F，16 MHz HSI | HAL、CMSIS、Keil MDK | USART1 收发 |
| [STM32F411CEU6 完整工程目录](STM32F411CEU6_EmbeddedProject_Folder_Template/README_zh.md) | Cortex-M4F，16 MHz HSI | HAL、CMSIS、Keil MDK | 基础固件及完整项目目录 |

## 开发环境

- STM32 工程使用 Keil MDK 5、ARM Compiler 5、STM32 HAL 库和 CMSIS 编译，并通过 SWD 下载与调试。
- ESP32-S3 工程使用 ESP-IDF 和 CMake，工程配置位于 `sdkconfig`，应用入口位于 `main/main.c`。
- 不同平台保留各自原生的工程结构和构建方式，具体配置以对应目录中的说明及工程文件为准。

## 快速开始

1. 克隆或下载本仓库，选择与目标芯片和开发环境匹配的模板。
2. 阅读模板说明并检查时钟、引脚、Flash 和调试接口等配置。
3. 安装对应平台的工具链，打开 Keil 工程或加载 ESP-IDF 工程后进行编译和下载。
4. 确认基础工程正常后再添加实验代码。建议复制模板或创建独立分支，保留一份可随时恢复和验证的基础版本。

## 目录约定

STM32 常规模板使用 `Users`、`Drivers`、`Projects` 和 `Output` 组织代码；完整目录模板还包含项目管理、硬件、软件、结构、测试和工具等分类。ESP32-S3 工程遵循 ESP-IDF 结构，使用根目录 CMake 配置、`sdkconfig` 和 `main` 组件。新增其他平台时可沿用其官方或团队约定的目录结构，无需强制统一。

## 注意事项

- 使用前请根据实际芯片、开发板和原理图检查时钟、引脚、存储容量及下载配置。
- 修改系统时钟或底层配置后，应同步检查延时、串口和分区等相关实现。
- 根目录 `.gitignore` 已过滤常见 Keil 生成文件；新增其他平台时，应检查其构建目录并补充忽略规则。

## 许可证

本项目采用 [MIT License](LICENSE)。
