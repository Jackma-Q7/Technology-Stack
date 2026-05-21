# 第八章 DMA直接存储器存取
## [8-1] DMA直接存储器存取
### DMA简介
DMA（Direct Memory Access）直接存储器存取

DMA可以提供外设和存储器或者存储器和存储器之间的高速数据传输，无须CPU干预，节省了CPU的资源

12个独立可配置的通道： DMA1（7个通道）， DMA2（5个通道）

每个通道都支持软件触发和<font style="color:#DF2A3F;">特定</font>的硬件触发

STM32F103C8T6 DMA资源：DMA1（7个通道）

### 存储器映像

<img src="../graph/810.png" style="max-width:100%;height:auto;"/>

### DMA框图

<img src="../graph/811.png" style="max-width:100%;height:auto;"/>

### DMA基本结构

<img src="../graph/812.png" style="max-width:100%;height:auto;"/>

### DMA请求

<img src="../graph/813.png" style="max-width:100%;height:auto;"/>

### 数据宽度与对齐

<img src="../graph/814.png" style="max-width:100%;height:auto;"/>

### 数据转运+DMA

<img src="../graph/815.png" style="max-width:100%;height:auto;"/>

### ADC扫描模式+DMA

<img src="../graph/816.png" style="max-width:100%;height:auto;"/>