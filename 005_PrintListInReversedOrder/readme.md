## 1. 题目
输入一个链表的头结点，从尾到头反过来打印出每个节点的值。
链表节点定义如下：
```cpp
struct ListNode{
    int m_nKey;
    ListNode* m_pNext;
};
```

## 2. 解题思路
### 2.1 思路1 --- 栈（先进后出的原则）
`通常，这种情况下，不希望修改原链表的结构`。返回一个反序的链表，这就是经典的“后进先出”，可以使用栈实现这种顺序。每经过一个结点的时候，把该结点放到一个栈中。当遍历完整个链表后，再从栈顶开始逐个输出结点的值，给一个新的链表结构，这样链表就实现了反转。

### 2.2 思路2 --- 库函数
用库函数，每次扫描一个节点，将该结点数据存入vector中，如果该节点有下一节点，将下一节点数据直接插入vector最前面，直至遍历完，或者直接加在最后，最后调用reverse。

### 2.3 思路3 --- 递归
递归在本质上就是一个栈结构，于是很自然地想到用递归来实现。要实现反过来输出链表，每访问到一个结点的时候，先递归输出它后面的结点，再输出该结点自身，这样链表的输出结构就反过来了。
算法流程如下：
- 只要当前节点不为NULL，也就是链表没到头，就一直递归
- 在递归结束时，将元素压入

这样当递归结束进行返回时，会将递归栈中的数据依次压入vector中，而压入的顺序就是栈中的顺序，即从尾到头