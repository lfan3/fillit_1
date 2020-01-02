# ft_printf documentation

**steps**
- learning stdarg.h
- verify format

***verify format***
case one : %d
wrong format: return -1  
- format like %%d is wrong

ignoring format:  
1, space 
- format like % d depend the possitif and negtif number, and only one space is count  
    - if it is negtif number, - occuped the empty space, otherwise, one empty space
2, + signe
- format like %++d, only one + is consided

**length**
 printf("im %hhd entier\n", 1585); hh will product only one octet so the result is 49
- char 1 bytes (8bits); -128--127
- uchar : 0-255
- short 2 bytes: -32768 - 32767
- ushort : 0-65 535
- %d = int: 4 bytes (32 bits). The minimal value is -2 147 483 648, the maximal one is 2 147 483 647.
- uint: from 0 to 4 294 967 295.
- %ld = %lld = long: 8 bytes (64 bits). The minimum value is -9 223 372 036 854 775 808, the maximum value is 9 223 372 036 854 775 807.
- ulong: from 0 to 18 446 744 073 709 551 615.
bug
* * -2, 5 take -5
* * 2, -5, take -5
presition return = -1 when it is * in my get_presition();
to do the d conversion!
cleaning the flags table!
to ask about get out put length, the lengh of j and z
need to free
**source**
http://www.pixelbeat.org/programming/gcc/format_specs.html
https://www.gnu.org/software/libc/manual/html_node/Integer-Conversions.html
https://man.developpez.com/man3/printf/
