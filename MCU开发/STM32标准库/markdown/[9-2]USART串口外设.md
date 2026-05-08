## [9-2] USART串口外设
### USART简介
USART（Universal Synchronous/Asynchronous Receiver/Transmitter）通用同步/异步收发器

USART是STM32内部集成的硬件外设，可根据数据寄存器的一个字节数据自动生成数据帧时序，从TX引脚发送出去，也可自动接收RX引脚的数据帧时序，拼接为一个字节数据，存放在数据寄存器里

自带波特率发生器，最高达4.5Mbits/s

可配置数据位长度（8/9）、停止位长度（0.5/1/1.5/2）

可选校验位（无校验/奇校验/偶校验）

支持同步模式、硬件流控制、DMA、智能卡、IrDA、LIN



STM32F103C8T6 USART资源： USART1、 USART2、 USART3

### USART框图
<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2025/png/57223890/1766815805557-fec2a9f4-fd92-4dfd-91b6-f0a2dc6c402c.png)

APB1总线时钟为PCLK1,是AHB总线时钟在APB1分频器二分频得到,因此为36MHz

### USART基本结构
<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2025/png/57223890/1766816442157-509af0a1-62e2-45fb-b405-2fc8990bc944.png)

### 数据帧
<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2025/png/57223890/1766816464034-f61c2c4a-9662-40c9-b3d5-493899e7d8bc.png)

<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2025/png/57223890/1766816498254-14e9fb65-9524-4843-ac88-28b2422f49bc.png)

### 起始位侦测
<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2025/png/57223890/1766816572928-cd9570e3-ff82-430c-925a-2d6dce04351c.png)

### 数据采样
<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2025/png/57223890/1766816606794-89027252-1631-4e7d-81a9-2e2cd179a1ac.png)

### 波特率发生器
发送器和接收器的波特率由波特率寄存器BRR里的DIV确定

计算公式：波特率 = fPCLK2/1 / (16 * DIV)

<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2025/png/57223890/1766816651772-6cfd649d-eed2-4293-a55c-edd2336d7c32.png)

### ch340
<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2025/png/57223890/1766817084544-6b1f0eb9-3ec9-4897-90af-e3a27e59f5c3.png)