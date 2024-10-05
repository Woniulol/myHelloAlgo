"""
Decimal:
123 = 1 * 10 ** 2 + 2 * 10 ** 1 + 3 * 10 ** 0
Binary:
101 = 1 * 2 ** 2 + 0 * 2 ** 1 + 1 * 2 ** 0
"""

"""
For a n digit unsigned binary number, it can represent [0, (2**n - 1)]
"""

"""
For singed binary number

0: 0000
1: 0001
2: 0010
7: 0111 (this is the maximum of a four digit binary number)

-1:
First check the positive of -1 -> 1, which is 0001
Second minus 1, which is 0000
Third take bitwise NOT of 0000, which is 1111
Thus 1111 represents -1

去掉减号，转二进制，减一，取反。

-2:
-2 -> 2 -> 0010 -> 0001 -> 1110

Given a signed binary number, convert it back (reverse the operation above)

1001:
1001 -> 0110 -> 0111 -> decimal 7 -> -7
(At the first glimpse we can already know this is a negative number)

取反，加一，转十进制，加上减号。

So for a four digit number, it can represent -2**(n-1) to 2**(n-1) - 1
"""

def convert_unsigned_binary_to_decimal_int(s: str, base: int = 2) -> int:
    pointer = 0
    decimal = 0
    while pointer < len(s):
        decimal += int(s[pointer], base=base) * base**(len(s) - 1 - pointer)
        pointer += 1
    return decimal

def convert_signed_binary_to_decimal_int(s: str) -> int:
    pointer = 0
    decimal = 0
    bitwise_not_s = ""
    if s[0] == str(1):
        while pointer < len(s):
            bitwise_not_s += str(int(not bool(int(s[pointer]))))
            pointer += 1
        # This is essentially a bitwise + 1
        decimal = -( convert_unsigned_binary_to_decimal_int(bitwise_not_s) + 1 )
        return decimal
    else:
        return convert_unsigned_binary_to_decimal_int(s)

def main() -> int:

    print(bin(5)[2:])  # 101
    print(0b101)  # 5

    print(bin(-1))  # return "-0b1"
    print(type(bin(-1)))  # str
    print(0b01 + 1)  # 2

    print(convert_unsigned_binary_to_decimal_int("1110"))
    # 0x4e equals to 0100 (4) with 1110 (e) -> 01001110
    print(convert_unsigned_binary_to_decimal_int("4e", base=16))
    print(convert_unsigned_binary_to_decimal_int("01001110", base=2))
    print(convert_signed_binary_to_decimal_int("10000001"))

    # In python, it seems every thing is singed
    # 00000001 -> 11111110 -> 00000001 -> 000000010 -> 2 -> -2
    print(~1)

    # Opposite number (for a signed integer)
    # Why this is important: the smallest negative number will not be able to be converted to positive
    # E.g. in 4 digits binary, -8 cannot be converted to 8 (4 digits only include -8 to 7)
    # Thus, in the 4 digits binary, - - 8 is still -8
    print(~7 + 1)

    a = 0b0001010
    b = 0b0001100
    print(bin(a | b))
    print(bin(a & b))
    print(bin(a ^ b))

    # You should distinguish bitwise and/or with logic and/or
    # Logic operation is lazy, but bitwise operation is greedy.

    # Why binary operation is designed in such a complex and intuitive way?

    # To ensure the add operation is in the same logic.
        # E.g. in a four digit binary number
        # For the positive number, to add logic is supper certain and predictable
        # 1 + 3 = 0001 + 0011 = 0100 -> 4

        # For negative number
        # -5 + 2 = 1011 + 0010 = 1101 -> 0010 + 1 -> 0011 -> -3
        # Magically, the representation is correct!

        # Even when there is a overflow, the result is still correct.
        # -5 + 7 = 1011 + 0111 = 0010 -> 2

    # Then why it is so important to ensure the add logic?
        # Add logic is the most fundamental operation.
        # It is the basic operation for the rest operation.

    c = 0b11010
    print(bin(c << 1))  # 110100
    print(bin(c << 2))  # 1101000
    print(bin(c << 3))  # 11010000

    # Python sucks
    # Cannot test the negative number.
    d = -0b11010
    print(bin(d << 1))  # 110100
    print(bin(d << 2))  # 1101000
    print(bin(d << 3))  # 11010000

    return 0

if __name__ == "__main__":
    main()
