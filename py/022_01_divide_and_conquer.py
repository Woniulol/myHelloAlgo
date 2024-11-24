# small sum
"""
# 0 + 1 + 4 + 1 + 6 + 15 = 27
# 所有的和等于左右两边的和相加，同时左侧的数会影响到右侧的小和。
# 同时考虑，如果左右各自有序是否可以提高计算效率。

# 7 7 6 2, 4 5 6 9
# -> 2 6 7 7, 4 5 6 9

# right cur 在 5 位置时，可以从right cur 在 4 位置的结束位置继续。

# f(l， r) 需要让数组在 l 到 r 上有序，且返回 l 到 r 上的小和

"""


def small_sum(l: int, r: int):
    global ARR, HELPER

    # small sum does not include the number itself
    if l == r:
        return 0

    m = int(l / 2 + r / 2)
    return small_sum(l=l, r=m) + small_sum(l=m+1, r=r) + small_sum_merge(l=l, m=m, r=r)


def small_sum_merge(l: int, m: int, r: int):
    global ARR, HELPER

    # l and r is already sorted sparely, but before any merge
    i = l
    j = m + 1
    small_sum: int = 0
    partial_sum = 0

    while j <= r:

        while i <= m and ARR[i] <= ARR[j]:
            partial_sum += ARR[i]
            i += 1

        # *** i will not be reset to l ***

        small_sum += partial_sum
        j += 1

    l_cur = l
    helper_cur = l
    r_cur = m + 1

    while l_cur <= m and r_cur <= r:
        if ARR[l_cur] < ARR[r_cur]:
            HELPER[helper_cur] = ARR[l_cur]
            l_cur += 1
            helper_cur += 1
        else:
            HELPER[helper_cur] = ARR[r_cur]
            r_cur += 1
            helper_cur += 1

    if l_cur > m:
        while r_cur <= r:
            HELPER[helper_cur] = ARR[r_cur]
            helper_cur += 1
            r_cur += 1

    if r_cur > r:
        while l_cur <= m:
            HELPER[helper_cur] = ARR[l_cur]
            helper_cur += 1
            l_cur += 1

    for i in range(l, r+1):
        ARR[i] = HELPER[i]

    return small_sum


def main():
    global ARR, HELPER
    print(ARR)
    print(HELPER)
    print(small_sum(0, len(ARR)-1))


if __name__ == "__main__":
    # ARR = [7, 7, 6, 2, 4, 5, 6, 9]
    ARR = [1, 2, 3]
    HELPER = [_ for _ in range(len(ARR))]
    main()
