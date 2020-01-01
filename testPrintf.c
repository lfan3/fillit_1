#include <stdio.h>
/*************************SOURCE*******************************/
//http://www.linux-france.org/prj/embedded/sdcc/sdcc_course.formatted_io.html
//type table
//c s 
//d u o x X
//f e E g G
//p
int main()
{
    /*************************char****************************/
    char ch = 'A';
    printf("impression %3c caracter\n", ch);
    //printf("impression %+3c caracter\n", ch); the signe + is just used for numerique value
    printf("impression %-3c caracter\n", ch);
    char *s = "hello, world";
    /*************************string****************************/
    printf("%s\n", s);
    printf("%10s\n", s); //minimum caracters to print
    printf("%-10s\n", s);
    printf("%.10s\n", s);//maximum caracters to print
    printf("%-15s\n", s);//print at least 15 width
    printf("%15.10s end\n", s);//minimum width is 15 , right ,and maximum 10 caracters to print
    printf("%-15.10s end\n", s); //minimum width is 15 , left,and maximum 10 caracters to print
    printf("%%\n"); //print out %
    
    printf("\n");
    printf("\n");
 
    /***************************entier************************/
    int a = 12;
    int aa = +12;
    float b = 12.345;
    int c = -12;
    int m=  printf("%i\n", 15);
    printf("m is %d\n", m);
    printf("im %d entier\n", a);
    printf("im % d entier\n", a);//if the nomber is possitif, un espace 
    printf("im % d +entier\n", aa);//if the nomber is possitif, un espace 
    printf("im % d entier\n", c);//if the nomber is negetif, the - replace the espace.
    printf("im %05d entier\n", a);//afficher avec 0 ; difference behavior with floating
    printf("im %.5d entier\n", a);//same with %05, for floating, it precises the number after .
    printf("im %*d *entier\n", 5, a);
    printf("im %5d entier\n", a);//afficher avec espace
    printf("im %+5d entier\n", a); //the signe "+" is printed
    printf("im %+5d entier\n", c); //the signe "-" is printed
    printf("im %-5d entier\n", a);
    
    
    //# force l'affichage précédé de 0, 0x ou 0X avec les types
    //respectifs %o %x %X
    printf ("Differentes bases : %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
    printf("%o\n", a); // nombre entier en octal
    printf("%x\n", a); // nombre entier en hexadécimal
    printf("%X\n", a);
    printf("%u\n", a); //no signé en decimal
    printf("%u\n", c); //no signé en decimal, in case of c=-12

    printf("\n");
    printf("\n");
 
    /*****************************float**************************/
    //# force l'affichage du point décimal avec les types e, E et f, meme si la partie décimal ne contient que des zéro
    //# force l'affichage du point décimal avec le types g et G sans supprimer les zéros inutiles
    printf("%e %#e\n", b, b);// expecting double
    printf("%E %#E\n", b, b);// expecting double
    // nombre reel sour la forme la plus court entre les types %E et %f
    printf("%g %#g\n", b, b);
    printf("%f %#f\n", b, b);
    printf("%.2f\n", b);
    // three ways to define precition
    printf("%15.6f float\n", b);
    printf("%06f float06\n", b);
    printf("%*f float*f\n", 6, b);
    printf("%-15f -float\n", b);
    printf("%+15f +float\n", b);

    printf("\n");
    printf("\n");

    //precision in details .nombre
    //pour type entier, it is the minimum number to show
    int k = 50;
    double j = 3.1415926;
    char *str = "abcde";
    printf("%.8d\n", k);
    printf("%.8u\n", k);
    printf("%.8x\n", k);
    printf("%.8o\n", k);
    //pour e f: nombre de chiffre apres le point decimal
    printf("%.8e\n", j);
    printf("%.8f\n", j);
    //pour g: nombre maximum de chiffres significatifs a afficher
    printf("%.8g\n", j);
    //pour s, nombre maximum de caracteres a afficher.
    printf("%.8s\n", str);


    /****************defaut largeur*****************/

    /***************modification*******************/
    //char == one octet 
    //int == from deux octets to four bytes
    //short == deux octets
    //long == four bytes
    //long long == 8 bytes
  
    /**************************operation****************************/
    printf("%d | ", 3 + 2);
    printf("%d | ", 3 + 2 * 3);
    printf("%f | ", -1. + 2 * 4. / 3);
    printf("%f | \n", -1. + 2 * 4 / 3); //the result is different from the one on top
    
    /******************special cases to test**********************/
    printf("%g | ", 1.);
    printf("%#g | ", 1.);
    printf("%e | ", 1.);
    printf("%f | \n", 1.);
    printf("Texte ecrit \
            lignes dans \
            et également dans la console\n");
    //printf("%f\n", 1); this is wrong, so need . to recognise if it is floating

    int m;
    m = printf("%d\n", 150);
    m = printf("%d\n", 1500);
    m = printf("%d\n", 1);
    m = printf("%s\n", "AB");
    //m = printf("%d\n", "Ab"); wrong
    m = printf("%.2f\n", 12.34);
    m = printf("%8.2f\n", 12.34);
    printf("m is %d\n", m);

    /**************special caracters *************************
    
    Séquence d'échappement 	signification
    %% 	affichage du caractère '%'
    \0 	caractère null ; valeur 0, délimiteur de fin de chaîne de caractères
    \a 	alerte ; beep système
    \b 	backspace ; déplacement du curseur d'un caractère en arrière
    \f 	form feed ; saut de page
    \n 	new line ; saut de ligne
    \r 	carriage return ; retour chariot
    \t 	tabulation horizontale
    \v 	tabulation verticale
    \\ 	affichage du caractère '\'
    \' 	affichage du caractère '''
    \" 	affichage du caractère '"'
    \Onn 	affichage de la valeur nn en octal
    \Xnn 	affichage de la valeur nn en hexadécimal
    ***********************************************************/

    /***************************indicateur d'affichage*******************
    [indicateur] 	signification
    - 	alignement à gauche pour la largeur donnée
    + 	affichage forcé du signe de la valeur numérique -12 or +12//!!!!!!!!!!!!!!!***
    espace 	insertion d'un caractère d'espacement si la valeur numérique est positive
    # 	affichage précédé de 0, 0x ou 0X avec les types respectifs o, x ou X
    force l'affichage du point décimal avec les types e, E et f même si la partie décimale ne contient que des zéros
    force l'affichage du point décimal avec les types g et G sans supprimer les zéros inut
    *************************************************************************/
    //flottante

}