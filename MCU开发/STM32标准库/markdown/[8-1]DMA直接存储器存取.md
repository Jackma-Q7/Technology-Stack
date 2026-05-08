# 第八章 DMA直接存储器存取
## [8-1] DMA直接存储器存取
### DMA简介
DMA（Direct Memory Access）直接存储器存取

DMA可以提供外设和存储器或者存储器和存储器之间的高速数据传输，无须CPU干预，节省了CPU的资源

12个独立可配置的通道： DMA1（7个通道）， DMA2（5个通道）

每个通道都支持软件触发和<font style="color:#DF2A3F;">特定</font>的硬件触发

STM32F103C8T6 DMA资源：DMA1（7个通道）

### 存储器映像
<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2025/png/57223890/1766711158922-8d9978cd-38de-474b-94ca-648094b6f351.png)

### DMA框图
<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2025/png/57223890/1766711180652-721f0df0-3bdb-420b-8477-68b332174d51.png)

### DMA基本结构
<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2025/png/57223890/1766711203809-483e1a43-be82-49df-b468-64b197ecc647.png)

### DMA请求
<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2025/png/57223890/1766711236039-bc78352b-f066-43a8-9499-4bbbca652dff.png)

### 数据宽度与对齐
<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2025/png/57223890/1766711254756-f7cfb282-ac40-4df4-b464-f7ab1e8424ac.png)

### 数据转运+DMA
<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2025/png/57223890/1766711282068-fadde19d-3223-4178-8a82-96aa6dd15b8d.png)

### ADC扫描模式+DMA
<!-- 这是一张图片，ocr 内容为： -->
![](https://cdn.nlark.com/yuque/0/2025/png/57223890/1766711311337-176c40cf-2338-4aad-b929-eff42f038735.png)