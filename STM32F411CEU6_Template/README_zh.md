**简体中文** | [English](README.md)

# STM32F411CEU6 工程模板

## 简介

基于 STM32F411CEU6 与 HAL 库的 Keil 裸机模板。采用 16 MHz 内部 HSI，集成查询式延时和 USART1 收发。

## 示例

程序每秒由 USART1（PA9/PA10，115200，8N1）发送 `TEST,1142!`；收到一帧数据后通过空闲中断回显。

## 使用

使用 Keil MDK 5（ARM Compiler 5）打开 `Projects/MDK-ARM/STM32F411CEU6.uvprojx`，编译并下载。

## 目录

- `Users`：应用与中断
- `Drivers`：HAL、CMSIS 及系统驱动
- `Projects`：Keil 工程
- `Output`：编译输出
