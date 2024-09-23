#include <stdio.h>

int forLoop(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += i;
    }
    return sum;
}

int whileLoop(int n)
{
    int sum = 0;
    int i = 0;
    while (i < n)
    {
        sum += i;
        i++;
    }
    return sum;
}

int main(void)
{
    printf("Iteration sum: %i \n", forLoop(5));
    printf("Iteration sum: %i \n", whileLoop(5));
    return 0;
}