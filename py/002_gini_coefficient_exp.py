import random
from typing import List

def cal_gini(wealth: List[int]) -> float:
    """
    Calculate the gini coefficient for the give int list.
    """

    sum_absolute_difference: int = 0
    sum_wealth: int = 0

    for i in wealth:
        sum_wealth += i
        for j in wealth:
            sum_absolute_difference += abs(j - i)

    return sum_absolute_difference / (2 * len(wealth) * sum_wealth)


def gini_exp(n: int, t: int) -> float:
    """
    Gini coefficient is a float number between 0 and 1 to evaluate the distribution of wealth in the society.

    0 Gini coefficient means the a evenly distributed wealth.

    This experiment assumes for n population, in each round every person shall
    give 1 unit of wealth to randomly another person when the person has a positive wealth.

    Person with 0 wealth can received but cannot give.
    """

    wealth = [100] * n

    for i in range(t):
        has_wealth = [individual > 0 for individual in wealth]

        for j in range(len(has_wealth)):
            if has_wealth[j]:
                give_to = j
                while give_to == j:
                    give_to = random.randint(0, len(has_wealth)-1)

                wealth[j] -= 1
                wealth[give_to] += 1

    return cal_gini(wealth)


def main() -> int:
    print(gini_exp(100, 10))
    print(gini_exp(100, 100))
    print(gini_exp(100, 1_000))
    print(gini_exp(100, 1_000_000))
    return 0


if __name__ == "__main__":
    main()