# 图像金字塔
图像金字塔是图像的一种较好的表示，从$NxN$到$1x1$的图像构成的一种类似金字塔的表示，并不是仅仅从$l$层下采样到$l+1$即可，因为单单使用下采样，导致采样频率过低，不能较好的捕捉信号，造成了锯齿效应。于是在下采样之前需要使用平滑操作，平滑操作相当于去除了原信号中的高频部分，变化较快的部分。

---
## 高斯图像金字塔

高斯图像金字塔构建构成为REDUCE过程，该过程结合了平滑操作和下采样操作。

![](http://chenguanfuqq.gitee.io/tuquan2/img_2018_5/image_pyramid.png)

---
## 拉普拉斯图像金字塔

拉普拉斯图像金字塔构建构成称为EXPAND过程。

---
## 参考资料

[Gaussian Laplacian pyramid](http://www.cs.toronto.edu/~mangas/teaching/320/slides/CSC320L10.pdf) 该PPT从浅入深介绍了高斯金字塔和拉普拉斯金字塔，以及在图像融合上的应用。

[Pyramid (image processing)](https://en.wikipedia.org/wiki/Pyramid_(image_processing)) 维基百科上介绍的图像金字塔。

[pyramids.py](https://github.com/scikit-image/scikit-image/blob/master/skimage/transform/pyramids.py) skimage上实现的图像金字塔模型，较大程度还原了论文中的思路。

[assignment5.py](https://github.com/syjk129/Blending/blob/master/assignment5.py) github上实现的一个demo。
