# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def FindKthToTail(self, head, k):
        # write code here
        if not head or k < 1:
            return None

        pRight = head
        pLeft = head

        for i in range(k - 1):
            if pRight.next:
                pRight = pRight.next
            else:
                return None

        while pRight.next:
            pLeft = pLeft.next
            pRight = pRight.next

        return pLeft
