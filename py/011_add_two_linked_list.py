"""
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
"""

from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:

        res: Optional[ListNode] = None

        cur1 = l1
        cur2 = l2
        carry = 0

        while cur1 or cur2 or carry:
            val1 = cur1.val if cur1 else 0
            val2 = cur2.val if cur2 else 0

            cur_sum = val1 + val2 + carry
            val_res = cur_sum % 10
            carry =  cur_sum // 10

            if not res:
                res = ListNode(val=val_res)
                cur = res
            else:
                cur.next = ListNode(val=val_res)
                cur = cur.next

            cur1 = cur1.next if cur1 else cur1
            cur2 = cur2.next if cur2 else cur2

        return res

if __name__ == "__main__":

    node1 = ListNode(val=1)
    node2 = ListNode(val=3)
    node3 = ListNode(val=5)
    node4 = ListNode(val=7)
    node5 = ListNode(val=9)
    node1.next = node2
    node2.next = node3
    node3.next = node4
    node4.next = node5

    node6 = ListNode(val=0)
    node7 = ListNode(val=1)
    node8 = ListNode(val=6)
    node6.next = node7
    node7.next = node8

    new_head = Solution().addTwoNumbers(l1=node1, l2=node6)
    while new_head:
        print(new_head.val)
        new_head = new_head.next
