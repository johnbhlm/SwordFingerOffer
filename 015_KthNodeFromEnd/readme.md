## 1. 题目
输入一个链表，输出该链表中倒数第k个结点。
>为了符合大多数人的习惯，该题目从1开始计数，即链表的尾点是倒数第一个节点。
>例如：一个链表有6个节点，从头节点开始它们的的值一次是1，2，3，4，5，6。链表倒数第三个节点的值为4的节点。

```cpp
struct ListNode{
    int m_nValue;
    ListNode* m_pNext;
};
```

## 2. 解题思路
### 2.1 思路1
暴力遍历两遍链表：第一次统计出表中节点的个数，第二次就可以找到倒数第k个节点。
### 2.2 思路2
遍历一遍：
1. 可以定义两个指针：第一个指针从链表的头指针开始遍历向前走k-1，第二个指针保持不动；
2. 从第k步开始，第二个指针也开始从链表的头指针开始遍历。
3. 由于两个指针的距离保持在k-1，当第一个（走在前面的）指针到达链表的尾结点时，第二个指针（走在后面的）指针正好是倒数第k个结点。
效果示意图，以链表总共6个结点，求倒数第3个结点为例：

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200915112925264.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2pvaG5fYmg=,size_16,color_FFFFFF,t_70#pic_center)

>（a）第一个指针在链表上走两步。
（b）把第二个指针指向链表的头结点。
（c）两个指针一同沿着链表向前轴。当第一个指针指向链表的尾节点时，第二个指针指向倒数第3个节点。
