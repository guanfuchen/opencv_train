# OpticalFlow

由于目标对象或者摄像机的移动造成的图像对象在连续两帧图像中的移动被称为光流。它是一个2D向量场，可以用来显示一个点从第一帧图像到第二帧图像之间的移动。

光流是基于以下假设的：
- 在连续的两帧之间像素的灰度值不改变；
- 相邻的像素具有相同的运动。

第一帧图像中的像素$I(x,y)$在时间$dt$后移动到第二帧图像的$I(x+dx,y+dy)$处。根据第一条假设：灰度值不变，可以得到：
$$I(x,y,t)=I(x+dx,y+dy,t+dt)$$
对等号后侧进行泰勒级数展开，消去相同项，两边都除以$dt$，得到：
$$I(x,y,t)=I(x+dx,y+dy,t+dt)$$
$$I(x,y,t)=I(x,y,t)+\frac{\partial{I}}{\partial{x}} dx+\frac{\partial{I}}{\partial{y}} dy+\frac{\partial{I}}{\partial{t}} dt$$
$$\frac{\partial{I}}{\partial{x}} dx+\frac{\partial{I}}{\partial{y}} dy+\frac{\partial{I}}{\partial{t}} dt=0$$
$$I_x u+I_y v+I_t=0$$
其中$I_x=\frac{\partial{I}}{\partial{x}}$，$I_y=\frac{\partial{I}}{\partial{y}}$，$I_t=\frac{\partial{I}}{\partial{t}}$，$u=\frac{dx}{dt}$，$v=\frac{dx}{dt}$，上述等式叫做光流方程。其中$I_x$和$I_y$是图像梯度，同样$I_t$是时间方向的梯度。该等式中$(u,v)$是未知量，一个等式无法求解两个未知量，这里可以通过使用Lucas-Kande法。

---
## Lucas-Kande法
光流第二个假设是领域内的所有点具有相同的运动，Lucas-Kande法利用一个3x3邻域中的9个具有相同运动的这个假设，组成9个点的光流方程，用它们组成一个具有两个未知数9个等式的方程，这是一个约束条件过多的方程组。一个好的解决方法就是使用最小二乘拟合。

光流方程$I_x u+I_y v=-I_t$，考虑3x3邻域得到9个光流方程：
$$I_{x1} u+I_{y1} v=-I_{t1}$$
$$I_{x2} u+I_{y2} v=-I_{t2}$$
$$\cdots$$
$$I_{x9} u+I_{y9} v=-I_{t9}$$
向量形式表示为：
$$\left[\begin{matrix}I_{x1} & I_{y2} \\ \vdots & \vdots\\ I_{x9} & I_{y9} \end{matrix}\right] \left[\begin{matrix}u \\ v\end{matrix}\right]=\left[\begin{matrix}-I_{t1}  \\ \vdots \\ -I_{t9}\end{matrix}\right]$$
使用优化的方法求解即：$\min \sum_{i}(I_{xi} u+I_{yi} v+I_{ti})^2$，该问题在对$u$和$v$求导导数为0的前提下取得最小值，得到下述方程：
$$\sum_{i}(I_{xi} u+I_{yi} v+I_{ti})I_{xi}=0$$
$$\sum_{i}(I_{xi} u+I_{yi} v+I_{ti})I_{yi}=0$$
对以上式子展开求解方程即可求得：
$$u=\frac{-\sum{I_{yi}^2}\sum{I_{xi}I_{ti}}+\sum{I_{xi}I_{yi}}\sum{I_{yi}I_{ti}}}{\sum{I_{xi}^2}\sum{I_{yi}^2}-(\sum{I_{xi}I_{yi}})^2}$$

$$v=\frac{\sum{I_{xi}I_{ti}}\sum{I_{xi}I_{yi}}-\sum{I_{xi}^2}\sum{I_{yi}I_{ti}}}{\sum{I_{xi}^2}\sum{I_{yi}^2}-(\sum{I_{xi}I_{yi}})^2}$$

以上求解是在很小的运动下取得光流，对于大的运动，可以使用图像金字塔，此时大的运动变换为小的运动，然后在使用Lucas-Kanade算法就可以得到相应尺度空间上的光流。

---
## 使用注意
上述Lucas-Kanade算法所有过程都被OpenCV打包成了一个函数：cv2.calcOpticalFlowPyrKL()，通过KL金字塔算法计算光流。

---
## 稠密光流
Lucas-Kanade法是计算一些特征点的光流，OpenCV还提供了一种计算稠密光流的方法，它会计算图像中的所有点的光流。这是基于Gunner_Farneback的算法。

---
## 参考资料

[pyoptflow](https://github.com/scivision/pyoptflow) 使用python实现Horn&Schunck算法和Lucas&Kanade算法。

[lk_track.py](https://github.com/opencv/opencv/blob/master/samples/python/lk_track.py) opencv官方lk跟踪示例程序。

[opt_flow.py](https://github.com/opencv/opencv/blob/master/samples/python/opt_flow.py) opencv官方稠密光流示例程序。
