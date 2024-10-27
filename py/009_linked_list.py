from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        prev: Optional[ListNode] = None
        while head:
            tmp = head.next
            head.next = prev
            prev = head
            head = tmp

        return prev

if __name__ == "__main__":
    node1 = ListNode(val=1)
    node2 = ListNode(val=2)
    node3 = ListNode(val=3)
    node4 = ListNode(val=4)
    node5 = ListNode(val=5)

    node1.next = node2
    node2.next = node3
    node3.next = node4
    node4.next = node5

    new_head = Solution().reverseList(head=node1)
    while new_head:
        print(new_head.val)
        new_head = new_head.next
