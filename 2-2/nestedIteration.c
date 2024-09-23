#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *nestedForLoop(int n)
{
    // "(i, j), (i, j), (i, j)"
    int size = n * n * 8 - 2 + 1;
    char *res = malloc(size * sizeof(char));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char tmp[9]; // 8 + 1
            snprintf(tmp, sizeof(tmp), "(%i, %i), ", i, j);

            // strlen does not include the null terminator.
            printf("String: %s \n", res);
            printf("Len String: %lu \n", strlen(res));

            strncat(res, tmp, size - strlen(res) - 1);
        }
    }

    return res;
}

int main(void)
{
    printf("String: %s", nestedForLoop(2));
}