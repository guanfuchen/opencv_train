# opencv_train

记录图像处理常用算法及其opencv实现。

---
## 颜色空间转换

参考opencv函数cvtColor，实现RGB、BGR、GRAY等颜色空间转换，示例代码可以参考[ColorChange](./python/notebook/ColorChange.ipynb)。

- RGB2GRAY
$$gray = 0.299*r + 0.587*g + 0.114*b$$
RGB颜色空间转换为灰度图。
- BGR2HSV
HSV颜色空间为亮度、饱和度和对比度，可以用来捕捉某些特定颜色的物体（H）。

[cvtColor](https://docs.opencv.org/2.4/modules/imgproc/doc/miscellaneous_transformations.html#cvtcolor)

---
## 图形绘制

在图像中绘制直线、圆、椭圆、矩形、文字等，实现可参考[ImageDraw](./python/notebook/ImageDraw.ipynb)。

---
## 图像滤波
介绍中值滤波、双线性滤波、高斯滤波等常用图像滤波算法，实现可参考[ImageFilter](./python/notebook/ImageFilter.ipynb)。

---
## 图像算术
介绍常用图像算术操作，包括add、sub等，实现可参考[ImageOperate](./python/notebook/ImageOperate.ipynb)。

---
## 图像梯度
介绍常用图像梯度计算操作，包括sobel、laplacian等，实现可参考[ImageGradient](./python/notebook/ImageGradient.ipynb)。

---
## 几何变换
介绍图像常用几何变换，包括图像平移、图像旋转、图像缩放等，实现可参考[ImageTransform](./python/notebook/ImageTransform.ipynb)。

---
## 视频操作
介绍OpenCV中常用视频操作，包括read帧，write帧等，实现可参考[VideoOperate](./python/notebook/VideoOperate.ipynb)。

---
## 参考资料

[CAP 5415 - Computer Vision](http://crcv.ucf.edu/courses/CAP5415/Fall2012/) 按照公开课学习。
