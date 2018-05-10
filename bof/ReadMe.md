# BOF

词袋模型，bag of feature，目标检测和图像分类任务中由于摄像头位姿，光照和内参存在可变性，因此处理难度较大，表现为类内区别，类间相似，具体图示如下所示：

![](http://chenguanfuqq.gitee.io/tuquan2/img_2018_5/screen_2018-05-10_09.29.11.png)

词袋模型最初被应用在纹理识别中，另外视觉词袋模型首先将图像分割为不同的小的本地Patches，然后使用SIFT或者SURF特征提取器生成描述子，在对不同的描述子进行聚类，最后聚类的类别表示为不同的视觉单词，这些视觉单词也就是所谓的视觉词典，然后一张图像可以通过直方图或者视觉词袋表示出来。Bag of features起源于bag of words（文本），无序的文本表示：来自于一个词典的frequencies of words字频率，然后分类为特定的文本类别。

bag of features应用在图像分类上，表现为检测特征点、计算描述子、描述子聚类（K-means）、SVM分类器训练并计算混淆矩阵。每一张图像通过一个向量（典型1000-4000）表示，分类器输入为图像bag of features的表示，输出为不同的类别（标签）。


---
## 参考资料

[经典论文学习bag of feature（二）](https://www.cnblogs.com/oudan/p/4169021.html)
