#include <stdio.h>

int main()
{
    printf("%d\n", 2147483647);
    printf("%d\n", 2147483648);
    printf("%ld\n", 9223372036854775807);
    printf("%ld\n", 9223372036854775808);
    printf("%lld\n", 18446744073709551615);
    printf("%ld\n", 18446744073709551615);
    printf("%llu\n", 18446744073709551615);
/*
- ushort : 0-65 535
- %d = int: 4 bytes (32 bits). The minimal value is -2 147 483 648, the maximal one is 2 147 483 647.
- uint: from 0 to 4 294 967 295.
- %ld = %lld = long: 8 bytes (64 bits). The minimum value is -9 223 372 036 854 775 808, the maximum value is 9 223 372 036 854 775 807.
- ulong: from 0 to 18 446 744 073 709 551 615.
*/
}