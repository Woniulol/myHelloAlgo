class Node:
    def __init__(self, val: int, pre: "Node" = None, next: "Node" = None):
        self.val = val
        self.pre = pre
        self.next = next


class MyCircularDeque:

    def __init__(self, k: int):
        self.limit = k
        self.size = 0
        self.head = None
        self.tail = None


    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False

        node = Node(value)

        if self.isEmpty():
            self.tail = node
        else:
            node.next = self.head
            self.head.pre = node

        self.head = node

        self.size += 1

        return True


    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False

        node = Node(value)

        if self.isEmpty():
            self.head = node
        else:
            self.tail.next = node
            node.pre = self.tail

        self.tail = node

        self.size += 1

        return True

    def deleteFront(self) -> bool:

        if self.isEmpty():
            return False

        self.head = self.head.next

        self.size -= 1

        return True


    def deleteLast(self) -> bool:

        if self.isEmpty():
            return False

        self.tail = self.tail.pre
        self.size -= 1

        return True


    def getFront(self) -> int:
        if self.isEmpty():
            return -1
        return self.head.val


    def getRear(self) -> int:
        if self.isEmpty():
            return -1
        return self.tail.val


    def isEmpty(self) -> bool:
        return self.size == 0

    def isFull(self) -> bool:
        return self.size >= self.limit



# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()