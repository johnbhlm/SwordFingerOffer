# -*- coding:utf-8 -*-

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


# 解法1：栈
def printListFromTailToHead(listNode):
    # write code here
    stack = []
    result = []
    node_p = listNode
    while node_p:
        stack.append(node_p.val)
        node_p = node_p.next
    while stack:
        result.append(stack.pop(-1))
    return result


# 解法2：递归
result = []
def printListFromTailToHead(listNode):
    # write code here
    if listNode:
        printListFromTailToHead(listNode.next)
        result.append(listNode.val)
    return result

# 解法3：头插
class Solution:
    def printListFromTailToHead(self, listNode):
        # write code here
        result = []
        head = listNode
        while head:
            result.insert(0,head.val)
            head =head.next
        return result

# 解法4：利用list 特性
class Solution:
    def printListFromTailToHead(self, listNode):
        # write code here
        if not listNode:
            return []
        result = []
        while listNode.next is not None:
            result.extend([listNode.val])
            listNode = listNode.next
        result.extend([listNode.val])

        return result[::-1]
