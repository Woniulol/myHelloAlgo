#include <stdio.h>

/**
 * 1. Concept and binary and digit.
 * 2. How to represent a positive binary integer.
 * 3. How to represent a negative binary integer.
 * 4. How to print binary integers and define binary / hex variable.
 * 5. Bitwise operation, |, &, ^, ~, <<, >>.
 * 6. Defined function to print binary integer.
 * 7. Difference between bitwise operation and logic operation.
 * 8. How to use bitwise operation to get the opposite number.
 * 9. Why the smallest negative integer cannot get it's opposite number.
 * 10. Why the bitwise operation is designed in such a way.
 * 11. About overflow.
 */

/**
 * For each digit compare 1 with that digit, only if both is 1 that digit is 1.
 * Assume a int32 integer.
 */
void printBinary(int num)
{
    for (int i = 31; i >= 0; i--)
    {
        printf("%s", (num & (1 << i)) == 0 ? "0" : "1");
        /**
         * This condition check must be checked against 0, raher than 1,
         * because the & result is 2**n, which is not 1.
         */
        printf("%s", ((i % 4) == 0 && (i != 0)) ? "_" : "");
    }
    printf("\n");
}

int main(void)
{
    signed int signed_num = -8;
    unsigned int unsigned_num = -8;
    int some_num = -9;
    int some_hex_num = 0x4e;

    printf("Hex number: %x \n", some_hex_num);
    printf("Hex number: %i \n", some_hex_num);

    /**
     * C does not have >>>.
     * >> behavior is different for positive and negative int.
     */

    /**
     * For non-negative number << n equals number * 2**n.
     * For non-negative number >> n equals number / 2**n.
     *
     * For negative number, don't use >> or <<.
     */

    unsigned int positive_int = 8;
    int negative_int = -8;
    printf("Signed num: %d \n", positive_int << 1);
    printf("Signed num: %d \n", positive_int << 2);
    printf("Signed num: %d \n", positive_int >> 1);
    printf("Signed num: %d \n", positive_int >> 2);

    printBinary(positive_int);
    printBinary(negative_int);

    return 0;
}
