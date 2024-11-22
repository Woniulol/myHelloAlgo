"""
From l to r with N. Time complexity is O(N) for merge operation.

T(N) = 2 * T(N/2) + O(N)
a = 2, b = 2, c = 1
Thus the time complexity for merge sort is O(NlogN) with master formula.

Why merge sort is faster than those naive sort?
Key point: the comparison operation is not wasted.

"""


import random

def merge_sort(arr: list[int]) -> list[int]:
    """
    1. 左右分别排好序，然后merge到一起。
    2. merge：比较左右两边下一个排序结果，哪一个小就放哪个
    3. 可以使用递归或非递归实现。
    4. 时间复杂度为O(NlogN)，额外空间复杂度为O(N)。
    """
    return _merge_sort_recur(arr, 0, len(arr)-1)

def _merge_sort_recur(arr: list[int], left: int, right: int) -> list[int]:
    if left == right:
        return arr[left: right+1]

    middle = int(left / 2  + right / 2)
    sorted_left = _merge_sort_recur(arr, left=left, right=middle)
    sorted_right = _merge_sort_recur(arr, left=middle+1, right=right)

    sorted_arr: list[int] = []
    while sorted_left or sorted_right:

        if sorted_left and sorted_right:
            left_next = sorted_left[0]
            right_next = sorted_right[0]
            if left_next > right_next:
                sorted_arr.append(right_next)
                sorted_right = sorted_right[1:]
            else:
                sorted_arr.append(left_next)
                sorted_left = sorted_left[1:]
            continue

        if sorted_left:
            sorted_arr.extend(sorted_left)
        else:
            sorted_arr.extend(sorted_right)
        break

    return sorted_arr

def merge(l: int, m: int, r:int) -> None:
    """
    """
    global ARR, HELP

    cur_left = l
    cur_right = m + 1

    cur_HELP = l

    while (cur_left <= m) and (cur_right <= r):
        if ARR[cur_left] < ARR[cur_right]:
            HELP[cur_HELP] = ARR[cur_left]
            cur_left += 1
            cur_HELP += 1
        else:
            HELP[cur_HELP] = ARR[cur_right]
            cur_right += 1
            cur_HELP += 1

    # Only one while will be triggered.
    while cur_right <= r:
        HELP[cur_HELP] = ARR[cur_right]
        cur_right += 1
        cur_HELP += 1

    while cur_left <= m:
        HELP[cur_HELP] = ARR[cur_left]
        cur_left += 1
        cur_HELP += 1

    # 因为每次取数都是从ARR中直接取，需要确保ARR本身在每次递归中被更新。
    # 让额ARR在区间上有序。
    while l <= r:
        ARR[l] = HELP[l]
        l += 1


def mergeSortRecur(l: int, r: int) -> None:
    """
    """
    global ARR, HELP

    if l == r:
        return

    m = int(l / 2 + r / 2)
    mergeSortRecur(l=l, r=m)
    mergeSortRecur(l=m+1, r=r)
    merge(l, m, r)

def mergeSortNonRecur() -> None:
    """
    Non-recur implementation of merge sort.

    step represent how many numbers that one side is taking.
    """

    step = 1
    # O(logN)
    while step < len(ARR):
        l = 0
        while l < len(ARR):
            # O(N)
            m = l + step - 1
            if m >= len(ARR) - 1:
                # right side is empty already
                break
            r = min((l + (step << 1) - 1), (len(ARR)-1))
            merge(l, m, r)
            l = r + 1
        step = step << 1


if __name__ == "__main__":
    arr = [9, 4, 3, 2, 0, 5, 7, 6, 8, 1]
    sorted_arr = merge_sort(arr=arr)
    print(sorted_arr)

    arr = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
    sorted_arr = merge_sort(arr=arr)
    print(sorted_arr)

    arr = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 9, 9, 8, 7, 6, 9]
    sorted_arr = merge_sort(arr=arr)
    print(sorted_arr)

    arr = [random.randint(0, 9) for _ in range(100)]
    sorted_arr = merge_sort(arr=arr)
    print(sorted_arr)

    # ARR: list[int] = [random.randint(0, 9) for _ in range(10)]
    ARR: list[int] = [6, 2, 3, 3, 4, 6, 9, 3, 1]
    HELP: list[int] = [_ for _ in range(9)]
    print(ARR)
    print(HELP)
    # mergeSortRecur(0, len(ARR)-1)
    mergeSortNonRecur()
    print(HELP)


