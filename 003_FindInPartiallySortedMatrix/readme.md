## 1. 题目
题目：二维数组中的查找
问题：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

举例：
例如下面的二维数组就是每行、每列都递增排序。如果在数组中找到数字7，则返回true，如果查找数字5，由于数组不含该数字，则返回false。

![在这里插入图片描述](https://img-blog.csdnimg.cn/2020082211264858.png#pic_center)

## 2. 解题思路
**算法思想**：我们知道每一行都是递增排序的，每一列也是从上到下递增排序的，所以左上角的数是最小的，而右下角的数是最大的
1. 选取右上角的数（也可以从左下角开始，`但是不能从左上角或者右下角开始`）；
2. 判断比较右上角的数和传入的数值的大小，如果等于该参数的值，查找结束；
3. 如果大于参数，则可以把这一列剔除；
4. 如果小于参数，就剔除该数值所在的行

也就是说如果要查找的数字不在数组右上角，则每次都在数组的查找范围中剔除一行或者一列，这样每一步都可以缩小查找范围，直到找到要查找的数字，或者查找范围为空。
查找过程如下：

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200822112826966.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2pvaG5fYmg=,size_16,color_FFFFFF,t_70#pic_center)
