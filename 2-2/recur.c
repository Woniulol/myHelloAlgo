#include <stdio.h>

int recur(int n)
{

    // Termination condition
    if (n == 0)
    {
        return 0;
    }

    // Calling
    int res = recur(n-1);

    // Returning
    return n + res;
}

int main(void)
{
    printf("Res: %i", recur(5));
}