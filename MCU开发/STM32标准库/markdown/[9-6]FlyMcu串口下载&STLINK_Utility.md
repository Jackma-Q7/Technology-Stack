## [9-6]FlyMcu串口下载&STLINK_Utility
### FlyMcu串口下载
**特点**

+ 通过 **UART（串口）** 进行程序下载
+ 需要芯片处于 **系统存储器启动模式**（Bootloader模式）
+ 无需额外调试器，只需USB转TTL串口线
+ 主要用于**量产烧录**或**无调试器时的程序更新**

**使用步骤**

1. **硬件连接**
    - USB转TTL的 `TX` → MCU的 `UART_RX`（通常是PA10）
    - USB转TTL的 `RX` → MCU的 `UART_TX`（通常是PA9）
    - 共地（GND）
    - 注意：FlyMcu 可能控制 **BOOT0** 和 **RESET** 引脚来自动进入Bootloader模式，但多数情况下需要手动设置BOOT0跳线
2. **进入Bootloader模式**
    - **BOOT0 = 1**，**BOOT1 = 0**
    - 复位芯片（或重新上电）
3. **软件配置**
    - 选择正确的串口号、波特率（一般115200）
    - 加载编译好的 `.hex` 或 `.bin` 文件
    - 点击“开始编程”

### STLINK Utility
（现为STM32CubeProgrammer的一部分）

特点

+ 通过 **ST-LINK调试器**（SWD或JTAG接口）进行烧录/调试
+ 功能更强大：擦除、编程、读取、选项字节配置等
+ 支持**离线烧录**（通过ST-LINK的脱机编程功能）
+ 目前ST官方已将其整合到 **STM32CubeProgrammer** 中

使用步骤（以ST-LINK V2为例）

**硬件连接**

1. text

```plain
ST-LINK V2  -->  STM32
SWDIO       -->  SWDIO（PA13）
SWCLK       -->  SWCLK（PA14）
GND         -->  GND
3.3V        -->  3.3V（可选，可为目标板供电）
```

2. **软件操作**
    - 连接ST-LINK到电脑
    - 打开STM32CubeProgrammer或STLINK Utility
    - 选择接口类型为 **SWD**
    - 点击连接，识别到芯片后即可进行烧录操作

---

三、对比总结

| 特性 | FlyMcu（串口） | ST-LINK Utility（调试器） |
| --- | --- | --- |
| **连接方式** | UART（串口） | SWD/JTAG（调试接口） |
| **是否需要Bootloader** | 是（使用内置Bootloader） | 否（直接通过调试接口访问内核） |
| **速度** | 较慢（受串口波特率限制） | 快（基于SWD/JTAG） |
| **功能** | 基本烧录 | 烧录、调试、内存查看、选项字节配置等 |
| **适用场景** | 量产、无调试器时的简易烧录 | 开发调试、量产（脱机模式） |
| **易用性** | 简单，但需手动设置BOOT引脚 | 一键连接，无需跳线切换 |


---

四、常见问题与注意事项

FlyMcu常见问题

1. **无法连接**
    - 检查BOOT0/BOOT1引脚设置是否正确
    - 检查串口线是否完好（RX/TX交叉连接）
    - 尝试降低波特率（如57600）
2. **芯片无法启动用户程序**
    - 烧录完成后需将BOOT0切回0，然后复位

ST-LINK常见问题

1. **无法识别芯片**
    - 检查SWD连接是否正常
    - 检查目标板是否供电
    - 尝试按住复位键再点击连接，然后释放复位键
2. **选项字节锁住芯片**
    - 可通过ST-LINK Utility的“选项字节”功能解除读保护

---

五、现代替代方案推荐

目前ST官方推荐使用 **STM32CubeProgrammer**，它整合了：

+ 串口编程（类似FlyMcu功能）
+ ST-LINK编程（替代STLINK Utility）
+ USB DFU、I2C、SPI等多种编程方式
+ 跨平台（Windows、Linux、macOS）

**建议**：对于新项目，直接使用 **STM32CubeProgrammer** 更全面、更方便。
