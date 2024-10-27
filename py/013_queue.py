class MyCircularQueue:

    def __init__(self, k: int):
        self.left: int = 0
        self.right: int = 0
        self.size: int = 0
        self.limit: int = k

        self._arr: list[int] = [i for i in range(k)]


    def enQueue(self, value: int) -> bool:
        if self.size >= self.limit: return False

        self._arr[self.right] = value

        self.right = 0 if self.right + 1 == self.limit else self.right + 1
        self.size += 1
        return True


    def deQueue(self) -> bool:
        if self.size <= 0: return False

        self.left = 0 if self.left + 1 == self.limit else self.left + 1
        self.size -= 1
        return True

    def isEmpty(self) -> bool:
        return self.size == 0

    def Front(self) -> int:
        if self.isEmpty(): return -1
        return self._arr[self.left]


    def Rear(self) -> int:
        if self.isEmpty(): return -1
        _index = self.right - 1 if self.right != 0 else self.limit - 1
        return self._arr[_index]


    def isFull(self) -> bool:
        return self.size == self.limit

if __name__ == "__main__":
    my_queue = MyCircularQueue(3)
    print(my_queue.enQueue(1))
    print(my_queue.enQueue(2))
    print(my_queue.enQueue(3))
    print(my_queue.enQueue(4))