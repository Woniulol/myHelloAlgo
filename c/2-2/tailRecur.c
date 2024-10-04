#include <stdio.h>

int tailRecur(int n, int res)
{
    if (n == 0)
    {
        return res;
    }
    return tailRecur(n - 1, res + n);
}

int fibRecur(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fibRecur(n-1) + fibRecur(n-2);
}

int main(void)
{
    printf("Res: %i \n", tailRecur(5, 0));
    printf("Res: %i \n", fibRecur(3));
}