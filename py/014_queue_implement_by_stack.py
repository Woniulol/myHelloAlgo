class MyQueue:

    def __init__(self) -> None:
        self.in_stack: list[int] = []
        self.out_stack: list[int] = []

    def push(self, x: int) -> None:
        self.in_stack.append(x)

    def pop(self) -> int:
        self.try_transfer()
        return self.out_stack.pop()

    def peek(self) -> int:
        self.try_transfer()
        return self.out_stack[-1]

    def empty(self) -> bool:
        return ((not self.in_stack) and (not self.out_stack))

    def try_transfer(self) -> None:
        if not self.out_stack:
            for i in self.in_stack[::-1]:
                self.out_stack.append(i)
            self.in_stack = []
        return


