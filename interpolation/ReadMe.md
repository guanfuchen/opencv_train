# 插值算法（Interpolation）

主要介绍双线性插值算法。

---
## 线性插值算法（Linear Interpolation）

已知坐标$(x_0,y_0)$和$(x_1,y_1)$，求得在$[x_0,x_1]$区间内某一位置x在直线上的点$(x,y)$，那么：
$$\frac{y-y_0}{x-x_0}=\frac{y_1-y_0}{x_1-x_0}$$

---
## 双线性插值算法（Bilinear Interpolation）
双线性插值是由两个变量的插值函数的线性插值扩展，其核心思想是在两个方向分别进行一次线性插值。
假设目标得到未知函数$f$在点$P=(x,y)$处的值，已知函数$f$在$Q_{11}=(x_1,y_1)$、$Q_{12}=(x_2,y_2)$、$Q_{21}=(x_2,y_1)$和$Q_{22}=(x_2,y_2)$四个点的值，记为$f(Q_{11})$、$f(Q_{12})$、$f(Q_{21})$和$f(Q_{22})$。
首先在$x$方向进行插值，得到：
$$f(R_1)=\frac{x-x_1}{x_2-x_1}f(Q_{11})+\frac{x_2-x}{x_2-x_1}f(Q_{21})，其中R_1=(x,y_1)$$
$$f(R_2)=\frac{x-x_1}{x_2-x_1}f(Q_{12})+\frac{x_2-x}{x_2-x_1}f(Q_{22})，其中R_2=(x,y_2)$$
然后在$y$方向进行线性插值，得到：
$$f(P)=\frac{y-y_1}{y_2-y_1}f(R_{1})+\frac{y_2-y}{y_2-y_1}f(R_{2})$$
通过以上可求得$f(x,y)$

---
## 三线性插值
双线性插值在三维空间的延伸是三线性插值，在更高维度的延伸是高阶插值。


![](http://chenguanfuqq.gitee.io/tuquan2/img_2018_5/Bilinear_interpolation.png)

---
## 使用相关

scipy misc中的插值算法思路是将numpy image转换为PIL Image然后使用PIL的插值算法。

```python
# 其中插值算法默认是双线性bilinear
# ('nearest', 'lanczos', 'bilinear', 'bicubic' or 'cubic').
def imresize(arr, size, interp='bilinear', mode=None)
```

[misc pilutil.py](https://github.com/scipy/scipy/blob/v0.18.1/scipy/misc/pilutil.py#L446-L489)

[PIL Image.py](https://github.com/python-pillow/Pillow/blob/3.1.x/PIL/Image.py)

---
## 查考资料

[双线性插值(Bilinear Interpolation)](http://www.cnblogs.com/xpvincent/archive/2013/03/15/2961448.html) 本篇博客介绍了双线性插值，很直观。

[Comparison of OpenCV Interpolation Algorithms](http://tanbakuchi.com/posts/comparison-of-openv-interpolation-algorithms/) 比较了OpenCV中线性插值算法的清晰度和速度。
