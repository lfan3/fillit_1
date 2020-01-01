#include <stdio.h>

int main()
{
    int a = 123;
    printf("1 im %.5.4d entier\n", a);//warning not to handle
    printf("2 im %.5d entier\n", a);//afficher avec espace
    printf("3 im %.*d entier\n",5, a);//afficher avec espace
    printf("4 im %0    ..6d entier\n", a);//warning
    printf("im %0    .6d entier\n", a);//warning
    printf("im %0     6d entier\n", a);//afficher avec espace
    printf("im %0 .    6d entier\n", a);//warning, not correct, do not need to handle
    printf("im %0d entier\n", a);//afficher avec espace
}