from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if (not list1) or (not list2):
            return list1 or list2

        head = list1 if list1.val < list2.val else list2
        list1, list2 = (list1.next, list2) if head == list1 else (list1, list2.next)
        cur_head = head

        while list1 and list2:
            if list1.val < list2.val:
                cur_head.next = list1
                list1 = list1.next
            else:
                cur_head.next = list2
                list2 = list2.next

            cur_head = cur_head.next

        cur_head.next = list1 if list1 else list2

        return head



if __name__ == "__main__":
    print(Solution().mergeTwoLists(list1=None, list2=None))
    print(Solution().mergeTwoLists(list1=None, list2=ListNode(val=1)))
    print(Solution().mergeTwoLists(list1=ListNode(val=1), list2=None))

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

    new_head = Solution().mergeTwoLists(list1=node1, list2=node6)
    while new_head:
        print(new_head.val)
        new_head = new_head.next