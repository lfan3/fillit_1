#include <stdio.h>

int main()
{
    int m;
    m = printf("%d\n", 150);
    m = printf("%d\n", 1500);
    m = printf("%d\n", 1);
    m = printf("%s\n", "AB");
    //m = printf("%d\n", "Ab"); wrong
    m = printf("%.2f\n", 12.34);
     m = printf("%8.2f\n", 12.34);
    printf("m is %d\n", m);

}
