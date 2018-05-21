# LBP

LBP特征介绍。

---
## 参考资料

[Local Binary Pattern for texture classification](http://scikit-image.org/docs/dev/auto_examples/features_detection/plot_local_binary_pattern.html) sklearn上关于使用LBP特征的相关介绍。

[局部二值模式](https://zh.wikipedia.org/wiki/%E5%B1%80%E9%83%A8%E4%BA%8C%E5%80%BC%E6%A8%A1%E5%BC%8F) 维基百科中关于LBP的介绍。

[目标检测的图像特征提取之（二）LBP特征](https://blog.csdn.net/zouxy09/article/details/7929531) zouxy09大神对LBP特征描述子的总结，非常有价值。

[Local Binary Patterns with Python & OpenCV](https://www.pyimagesearch.com/2015/12/07/local-binary-patterns-with-python-opencv/) pyimgage中介绍的LBP相关知识，其中使用了hist计算出了LBP的直方图用来作为分类器的输入。

[lbpcascades](https://github.com/opencv/opencv/tree/master/data/lbpcascades) opencv中提供了lbp级联人脸检测器的训练特征。

[LBP NumPy Performance](https://www.bytefish.de/blog/numpy_performance/) 探索了加速计算LBP。

[texture.py](https://github.com/scikit-image/scikit-image/blob/master/skimage/feature/texture.py) 和 [_texture.pyx](https://github.com/scikit-image/scikit-image/blob/master/skimage/feature/_texture.pyx) 中有lbp代码实现，其中用到了Cython加速计算LBP。
