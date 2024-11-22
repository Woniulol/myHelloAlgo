"""
Find the max int within [4, 2, 6, 1]

Logic is to get the max from both side of the arr.
For each side, repeat the logic.

Recursive operation is done by system stack.

All recursive operation can be implemented by non recursive.
E.g. use your our stack rather than the system stack.

Generally, no recursive operation in project.

Master Formula:
1. T(n) = a * T(n/b) + O(n^C)
处理一个数据量为n的问题，子过程的数据量变小（n -> n/b)，一共需要处理a次子问题。O(n^C)是解决问题过程中除去递归行为的操作的时间复杂度。

在寻找最大值的过程中，初始问题的规模是T(N)，初始问题分解成了两个子问题，即寻找左侧的最大值和右侧的最大值，数据量分别为T(N/2)，a=2，
其他过程的时间复杂度是O(1)，O(1)相当于N的0次方，所以c是0.

任意满足该公式的算法逻辑都可以使用master公式来确定时间复杂度。

2. 只有所有子问题规模相等的情况下才能使用master公式。子问题规模相等要求在每一次递归的时候每个子问题的n/b必须相等。

3. if log(b, a) < c, O(N ^ c)
4. if log(b, a) > c, O(N ^ log(b,a))
5. if log(b, a) == c, O(N^c * logN)

6. 对于T(N) = 2 * T(N/2) + O(N * logN）不符合master公式，但是因为常见，可以记忆其时间复杂度为O(N*((logN)^2))
"""


def get_max_recursive(arr: list[int], left: int, right: int) -> int:
    if left == right:
        # base case of the recursive operation or the condition to end the recursive operation.
        return arr[left]
    middle = int(left / 2 + right / 2)
    left_max = get_max_recursive(arr, left=left, right=middle)
    right_max = get_max_recursive(arr, left=middle + 1, right=right)
    return max(left_max, right_max)

if __name__ == "__main__":
    print(get_max_recursive([4, 2, 6, 1], 0, 3))
    print(get_max_recursive([4, 2, 6, 1, 2, 0, 100, -10, 0], 0, 8))
    print(int(3.5), int(2.8), int(4.99))  # always round down
