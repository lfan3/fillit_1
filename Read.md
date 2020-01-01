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

bug
* * -2, 5 take -5
* * 2, -5, take -5
presition return = -1 when it is * in my get_presition();
next: length, conversion_specifiter, space
**source**
http://www.pixelbeat.org/programming/gcc/format_specs.html
https://www.gnu.org/software/libc/manual/html_node/Integer-Conversions.html
https://man.developpez.com/man3/printf/
