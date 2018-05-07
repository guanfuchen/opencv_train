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
## Canny边缘检测

Canny边缘检测是一种非常流行的边缘检测算法，是John在1986年提出的，实现可参考[CannyDetection](./python/notebook/CannyDetection.ipynb)，使用numpy对每一步进行了实现。

[Wasnik_01_01.ipynb](https://github.com/ranriy/Canny-Edge-Detector/blob/master/Wasnik_01_01.ipynb)

[Canny边缘检测算法的实现](https://www.cnblogs.com/mightycode/p/6394810.html)

[Canny算法 边缘检测](http://www.cnblogs.com/Black-Small/p/3258463.html)

---
## 图像金字塔
一般情况下，我们要处理一副具有固定分辨率的图像，但是在有些情况下，我们需要对同一图像的不同分辨率的子图像进行处理。比如，我们要在一副图像中查找某个目标，比如脸，我们不知道目标在图像中的尺寸大小。这种情况下，我们需要创建一组图像，这些图像是具有不同分辨率的原始图像，这些图像构成了图像金字塔（同一图像的不同分辨率的子图集合），实现可参考[Pyramid](./python/notebook/Pyramid.ipynb)。


---
## 图像特征与描述
角点corner是一个好的图像特征。找到图像特征的技术被称为特征检测。特征匹配使用特征描述。

---
## Harris角点检测
角点特性：像任何方向移动变化都很大。其中Harris角点是Harris和Mike在1988年提出的，他将这个特性转换为数学形式，即窗口想各个方向移动(u,v)然后计算所有差异的总和，公式如下：
$$E(u,v)=\sum_{x,y}{w(x,y)[I(x+u, y+v)-I(x,y)]^2}$$

---
## SIFT特征提取
介绍SIFT特征提取。

---
## 常用函数

### RGB2BGR

```python
def bgr_to_rgb(bgr):
    rgb = cv2.cvtColor(bgr, cv2.COLOR_BGR2RGB)
    return rgb
def rgb_to_bgr(rgb):
    bgr = cv2.cvtColor(rgb, cv2.COLOR_RGB2BGR)
    return bgr
```

---
## 参考资料

[CAP 5415 - Computer Vision](http://crcv.ucf.edu/courses/CAP5415/Fall2012/) 按照公开课学习。
