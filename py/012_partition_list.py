"""
Given the head of a linked list and a value x,
partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.
"""

from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:

        if not head: return head

        head_lt = None
        head_gte = None
        cur_head = head

        while cur_head:

            if cur_head.val < x:

                if not head_lt:
                    head_lt = cur_head
                else:
                    cur_head_lt.next = cur_head
                cur_head_lt = cur_head

            else:

                if not head_gte:
                    head_gte = cur_head
                else:
                    cur_head_gte.next = cur_head
                cur_head_gte = cur_head

            cur_head = cur_head.next

        if head_lt:
            cur_head_lt.next = head_gte
        else:
            head_lt = head_gte

        if head_gte:
            cur_head_gte.next = None

        return head_lt

if __name__ == "__main__":

    node1 = ListNode(val=1)
    node2 = ListNode(val=4)
    node3 = ListNode(val=3)
    node4 = ListNode(val=2)
    node5 = ListNode(val=5)
    node6 = ListNode(val=2)
    node1.next = node2
    node2.next = node3
    node3.next = node4
    node4.next = node5
    node5.next = node6

    new_head = Solution().partition(head=node1, x=3)
    while new_head:
        print(new_head.val)
        new_head = new_head.next

    node1 = ListNode(val=1)
    new_head = Solution().partition(head=node1, x=2)
    while new_head:
        print(new_head.val)
        new_head = new_head.next
