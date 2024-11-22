class MyCircularDeque:

    def __init__(self, k: int):
        self.size = 0
        self.limit = k  # len()

        self.left = 0  # index of the head
        self.right = 0 # index to append
        self._data = [-1 for _ in range(self.limit)]


    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False

        if self.left == 0:
            self.left = self.limit - 1
        else:
            self.left -= 1
        self._data[self.left] = value
        self.size += 1

        return True


    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False

        self._data[self.right] = value
        if self.right + 1 == self.limit:
            self.right = 0
        else:
            self.right += 1

        self.size += 1

        return True


    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False

        if self.left + 1 == self.limit:
            self.left = 0
        else:
            self.left += 1

        self.size -= 1

        return True


    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False

        if self.right - 1 < 0:
            self.right = self.limit - 1
        else:
            self.right -= 1

        self.size -= 1

        return True


    def getFront(self) -> int:
        if self.isEmpty():
            return -1
        return self._data[self.left]


    def getRear(self) -> int:
        if self.isEmpty():
            return -1
        if self.right - 1 < 0:
            return self._data[self.limit - 1]
        return self._data[self.right - 1]


    def isEmpty(self) -> bool:
        return self.size == 0

    def isFull(self) -> bool:
        return self.size == self.limit

# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)