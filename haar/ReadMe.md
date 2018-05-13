# Haar

---
## 概述
以Haar特征分类器为基础的对象检测技术是一种非常有效的对象检测技术。它是基于机器学习的，通过使用大量的正负样本图像训练得到一个级联函数，最后再用它来做对象检测。

具体到面部检测中，首先算法需要大量的正样本图像（面部图像）和负样本图像（不含面部的图像）来训练分类器。具体的Haar特征如下所示，该特征作用和卷积核类似，每一个特征是一个值，这个值等于黑色矩形中的像素值减去白色矩形中的像素值之和。

但是在我们计算得到的所有的这些特征中，大多数是不相关的，那么我们怎样从大量的特征中选取最好的特征？（使用Adaboost）

为了达到这个目的，我们将每一个特征应用于所有的训练图像。对于每一个特征，我们要找到它能够区分出正样本和负样本的最佳阈值。但是很明显，这回产生错误或者错误分类。我们要选取错误率最低的特征，这说明它们是检测面部和非面部图像最好的特征。

---
## 使用

## OpenCV中使用
使用OpenCV中提供的haar cascades检测人脸，更多的人脸检测可参考[haarcascades](https://github.com/opencv/opencv/tree/master/data/haarcascades)。

[Face Detection using Haar Cascades](https://docs.opencv.org/3.4/d7/d8b/tutorial_py_face_detection.html)

---
## 参考资料

[Viola Jones face detection and tracking explained](https://www.youtube.com/watch?v=WfdYYNamHZ8) 这个视频对Haar、Adaboost和级联Cascading在人脸检测中的应用做了详细的解释，PPT Ramsri_Face_detection_and_tracking.pdf同样值得参考，后面还有人脸跟踪算法暂定。

[OpenCV-Python-Series](https://github.com/codingforentrepreneurs/OpenCV-Python-Series) 最近新出的一个关于opencv python的视频教程。

[哈尔特征](https://zh.wikipedia.org/wiki/%E5%93%88%E5%B0%94%E7%89%B9%E5%BE%81) 维基百科。

[图像特征提取三大法宝：HOG特征，LBP特征，Haar特征](http://dataunion.org/20584.html) 其中对这三个特征的说明较为生动。

[基于haar Like特征的人脸识别](http://kakack.github.io/2017/08/%E5%9F%BA%E4%BA%8EHaar-Like%E7%89%B9%E5%BE%81%E7%9A%84%E4%BA%BA%E8%84%B8%E8%AF%86%E5%88%AB/)

[图像特征提取之Haar特征](https://senitco.github.io/2017/06/15/image-feature-haar/)

[Haar-like feature descriptor](http://scikit-image.org/docs/dev/auto_examples/features_detection/plot_haar.html) skimage中关于haar特征计算。

[Faces recognition example using eigenfaces and SVMs](http://scikit-learn.org/stable/auto_examples/applications/plot_face_recognition.html#sphx-glr-auto-examples-applications-plot-face-recognition-py)

[5.6.4. The Labeled Faces in the Wild face recognition dataset](http://scikit-learn.org/stable/datasets/labeled_faces.html)

[Viola-Jones](https://github.com/Simon-Hohberg/Viola-Jones/blob/master/Viola-Jones%20Example.ipynb) VJ Haar AdaBoost人脸检测框架实现。

[Making faces with Haar cascades and mixed integer linear programming](https://matthewearl.github.io/2016/01/14/inverse-haar/)

[Face-Detection-OpenCV](https://github.com/informramiz/Face-Detection-OpenCV) 本仓库比较了LBP和Haar特征级联分类器。
