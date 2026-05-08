## [9-6]FlyMcu串口下载&STLINK_Utility
### FlyMcu串口下载
**<font style="color:rgb(15, 17, 21);">特点</font>**

+ <font style="color:rgb(15, 17, 21);">通过</font><font style="color:rgb(15, 17, 21);"> </font>**<font style="color:rgb(15, 17, 21);">UART（串口）</font>**<font style="color:rgb(15, 17, 21);"> </font><font style="color:rgb(15, 17, 21);">进行程序下载</font>
+ <font style="color:rgb(15, 17, 21);">需要芯片处于</font><font style="color:rgb(15, 17, 21);"> </font>**<font style="color:rgb(15, 17, 21);">系统存储器启动模式</font>**<font style="color:rgb(15, 17, 21);">（Bootloader模式）</font>
+ <font style="color:rgb(15, 17, 21);">无需额外调试器，只需USB转TTL串口线</font>
+ <font style="color:rgb(15, 17, 21);">主要用于</font>**<font style="color:rgb(15, 17, 21);">量产烧录</font>**<font style="color:rgb(15, 17, 21);">或</font>**<font style="color:rgb(15, 17, 21);">无调试器时的程序更新</font>**

**<font style="color:rgb(15, 17, 21);">使用步骤</font>**

1. **<font style="color:rgb(15, 17, 21);">硬件连接</font>**
    - <font style="color:rgb(15, 17, 21);">USB转TTL的</font><font style="color:rgb(15, 17, 21);"> </font>`<font style="color:rgb(15, 17, 21);background-color:rgb(235, 238, 242);">TX</font>`<font style="color:rgb(15, 17, 21);"> </font><font style="color:rgb(15, 17, 21);">→ MCU的</font><font style="color:rgb(15, 17, 21);"> </font>`<font style="color:rgb(15, 17, 21);background-color:rgb(235, 238, 242);">UART_RX</font>`<font style="color:rgb(15, 17, 21);">（通常是PA10）</font>
    - <font style="color:rgb(15, 17, 21);">USB转TTL的</font><font style="color:rgb(15, 17, 21);"> </font>`<font style="color:rgb(15, 17, 21);background-color:rgb(235, 238, 242);">RX</font>`<font style="color:rgb(15, 17, 21);"> </font><font style="color:rgb(15, 17, 21);">→ MCU的</font><font style="color:rgb(15, 17, 21);"> </font>`<font style="color:rgb(15, 17, 21);background-color:rgb(235, 238, 242);">UART_TX</font>`<font style="color:rgb(15, 17, 21);">（通常是PA9）</font>
    - <font style="color:rgb(15, 17, 21);">共地（GND）</font>
    - <font style="color:rgb(15, 17, 21);">注意：FlyMcu 可能控制</font><font style="color:rgb(15, 17, 21);"> </font>**<font style="color:rgb(15, 17, 21);">BOOT0</font>**<font style="color:rgb(15, 17, 21);"> </font><font style="color:rgb(15, 17, 21);">和</font><font style="color:rgb(15, 17, 21);"> </font>**<font style="color:rgb(15, 17, 21);">RESET</font>**<font style="color:rgb(15, 17, 21);"> </font><font style="color:rgb(15, 17, 21);">引脚来自动进入Bootloader模式，但多数情况下需要手动设置BOOT0跳线</font>
2. **<font style="color:rgb(15, 17, 21);">进入Bootloader模式</font>**
    - **<font style="color:rgb(15, 17, 21);">BOOT0 = 1</font>**<font style="color:rgb(15, 17, 21);">，</font>**<font style="color:rgb(15, 17, 21);">BOOT1 = 0</font>**
    - <font style="color:rgb(15, 17, 21);">复位芯片（或重新上电）</font>
3. **<font style="color:rgb(15, 17, 21);">软件配置</font>**
    - <font style="color:rgb(15, 17, 21);">选择正确的串口号、波特率（一般115200）</font>
    - <font style="color:rgb(15, 17, 21);">加载编译好的</font><font style="color:rgb(15, 17, 21);"> </font>`<font style="color:rgb(15, 17, 21);background-color:rgb(235, 238, 242);">.hex</font>`<font style="color:rgb(15, 17, 21);"> </font><font style="color:rgb(15, 17, 21);">或</font><font style="color:rgb(15, 17, 21);"> </font>`<font style="color:rgb(15, 17, 21);background-color:rgb(235, 238, 242);">.bin</font>`<font style="color:rgb(15, 17, 21);"> </font><font style="color:rgb(15, 17, 21);">文件</font>
    - <font style="color:rgb(15, 17, 21);">点击“开始编程”</font>

### STLINK Utility
<font style="color:rgb(15, 17, 21);">（现为STM32CubeProgrammer的一部分）</font>

<font style="color:rgb(15, 17, 21);">特点</font>

+ <font style="color:rgb(15, 17, 21);">通过</font><font style="color:rgb(15, 17, 21);"> </font>**<font style="color:rgb(15, 17, 21);">ST-LINK调试器</font>**<font style="color:rgb(15, 17, 21);">（SWD或JTAG接口）进行烧录/调试</font>
+ <font style="color:rgb(15, 17, 21);">功能更强大：擦除、编程、读取、选项字节配置等</font>
+ <font style="color:rgb(15, 17, 21);">支持</font>**<font style="color:rgb(15, 17, 21);">离线烧录</font>**<font style="color:rgb(15, 17, 21);">（通过ST-LINK的脱机编程功能）</font>
+ <font style="color:rgb(15, 17, 21);">目前ST官方已将其整合到</font><font style="color:rgb(15, 17, 21);"> </font>**<font style="color:rgb(15, 17, 21);">STM32CubeProgrammer</font>**<font style="color:rgb(15, 17, 21);"> </font><font style="color:rgb(15, 17, 21);">中</font>

<font style="color:rgb(15, 17, 21);">使用步骤（以ST-LINK V2为例）</font>

**<font style="color:rgb(15, 17, 21);">硬件连接</font>**

1. <font style="color:rgb(15, 17, 21);">text</font>

```plain
ST-LINK V2  -->  STM32
SWDIO       -->  SWDIO（PA13）
SWCLK       -->  SWCLK（PA14）
GND         -->  GND
3.3V        -->  3.3V（可选，可为目标板供电）
```

2. **<font style="color:rgb(15, 17, 21);">软件操作</font>**
    - <font style="color:rgb(15, 17, 21);">连接ST-LINK到电脑</font>
    - <font style="color:rgb(15, 17, 21);">打开STM32CubeProgrammer或STLINK Utility</font>
    - <font style="color:rgb(15, 17, 21);">选择接口类型为</font><font style="color:rgb(15, 17, 21);"> </font>**<font style="color:rgb(15, 17, 21);">SWD</font>**
    - <font style="color:rgb(15, 17, 21);">点击连接，识别到芯片后即可进行烧录操作</font>

---

<font style="color:rgb(15, 17, 21);">三、对比总结</font>

| <font style="color:rgb(15, 17, 21);">特性</font> | <font style="color:rgb(15, 17, 21);">FlyMcu（串口）</font> | <font style="color:rgb(15, 17, 21);">ST-LINK Utility（调试器）</font> |
| --- | --- | --- |
| **<font style="color:rgb(15, 17, 21);">连接方式</font>** | <font style="color:rgb(15, 17, 21);">UART（串口）</font> | <font style="color:rgb(15, 17, 21);">SWD/JTAG（调试接口）</font> |
| **<font style="color:rgb(15, 17, 21);">是否需要Bootloader</font>** | <font style="color:rgb(15, 17, 21);">是（使用内置Bootloader）</font> | <font style="color:rgb(15, 17, 21);">否（直接通过调试接口访问内核）</font> |
| **<font style="color:rgb(15, 17, 21);">速度</font>** | <font style="color:rgb(15, 17, 21);">较慢（受串口波特率限制）</font> | <font style="color:rgb(15, 17, 21);">快（基于SWD/JTAG）</font> |
| **<font style="color:rgb(15, 17, 21);">功能</font>** | <font style="color:rgb(15, 17, 21);">基本烧录</font> | <font style="color:rgb(15, 17, 21);">烧录、调试、内存查看、选项字节配置等</font> |
| **<font style="color:rgb(15, 17, 21);">适用场景</font>** | <font style="color:rgb(15, 17, 21);">量产、无调试器时的简易烧录</font> | <font style="color:rgb(15, 17, 21);">开发调试、量产（脱机模式）</font> |
| **<font style="color:rgb(15, 17, 21);">易用性</font>** | <font style="color:rgb(15, 17, 21);">简单，但需手动设置BOOT引脚</font> | <font style="color:rgb(15, 17, 21);">一键连接，无需跳线切换</font> |


---

<font style="color:rgb(15, 17, 21);">四、常见问题与注意事项</font>

<font style="color:rgb(15, 17, 21);">FlyMcu常见问题</font>

1. **<font style="color:rgb(15, 17, 21);">无法连接</font>**
    - <font style="color:rgb(15, 17, 21);">检查BOOT0/BOOT1引脚设置是否正确</font>
    - <font style="color:rgb(15, 17, 21);">检查串口线是否完好（RX/TX交叉连接）</font>
    - <font style="color:rgb(15, 17, 21);">尝试降低波特率（如57600）</font>
2. **<font style="color:rgb(15, 17, 21);">芯片无法启动用户程序</font>**
    - <font style="color:rgb(15, 17, 21);">烧录完成后需将BOOT0切回0，然后复位</font>

<font style="color:rgb(15, 17, 21);">ST-LINK常见问题</font>

1. **<font style="color:rgb(15, 17, 21);">无法识别芯片</font>**
    - <font style="color:rgb(15, 17, 21);">检查SWD连接是否正常</font>
    - <font style="color:rgb(15, 17, 21);">检查目标板是否供电</font>
    - <font style="color:rgb(15, 17, 21);">尝试按住复位键再点击连接，然后释放复位键</font>
2. **<font style="color:rgb(15, 17, 21);">选项字节锁住芯片</font>**
    - <font style="color:rgb(15, 17, 21);">可通过ST-LINK Utility的“选项字节”功能解除读保护</font>

---

<font style="color:rgb(15, 17, 21);">五、现代替代方案推荐</font>

<font style="color:rgb(15, 17, 21);">目前ST官方推荐使用</font><font style="color:rgb(15, 17, 21);"> </font>**<font style="color:rgb(15, 17, 21);">STM32CubeProgrammer</font>**<font style="color:rgb(15, 17, 21);">，它整合了：</font>

+ <font style="color:rgb(15, 17, 21);">串口编程（类似FlyMcu功能）</font>
+ <font style="color:rgb(15, 17, 21);">ST-LINK编程（替代STLINK Utility）</font>
+ <font style="color:rgb(15, 17, 21);">USB DFU、I2C、SPI等多种编程方式</font>
+ <font style="color:rgb(15, 17, 21);">跨平台（Windows、Linux、macOS）</font>

**<font style="color:rgb(15, 17, 21);">建议</font>**<font style="color:rgb(15, 17, 21);">：对于新项目，直接使用 </font>**<font style="color:rgb(15, 17, 21);">STM32CubeProgrammer</font>**<font style="color:rgb(15, 17, 21);"> 更全面、更方便。</font>
