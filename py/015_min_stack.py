"""
因为数据压入栈之后的顺序是不会变化的，所以每次压入和弹出数据后的最小值的状态是不会变化的。

准备两个栈，一个负责存储数据，另一个负责存储在当前压入和弹出状态下的最小值。

最小栈与数据栈同时压入和弹出数据，但只保留最小的。
"""

class MinStack:

    def __init__(self):
        self._data = []
        self._min = []

    def push(self, val: int) -> None:

        self._data.append(val)

        if self._min:
            if self._min[-1] > val:
                self._min.append(val)
            else:
                self._min.append(self._min[-1])
        else:
            self._min.append(val)


    def pop(self) -> None:
        self._data = self._data[:-1]
        self._min = self._min[:-1]


    def is_empty(self) -> bool:
        return len(self._data) == 0

    def top(self) -> int:
        return self._data[-1]

    def getMin(self) -> int:
        return self._min[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()