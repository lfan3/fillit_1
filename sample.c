#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

int ma_printf(char *p,...)
{
  unsigned int i=0,j=0;
  va_list ap;//création de la liste
  va_start(ap,p);//intialisation de la liste ap
    char v[30];
    int n;
  
  while(*(p+i)!='\0')//
  {
  switch(*(p+i))//
  {
  case '%':
  { i++;
  if(*(p+i)=='c')
  {
  fputc(va_arg(ap,int),stdout);
  }
  
  if(*(p+i)=='d')
  { n=va_arg(ap,int);
  itoa(n,v,10);
  
  for(j=0;j<strlen(v);j++){
  fputc(v[j],stdout);
  }
  
  if(*(p+i)=='s')
  { strcpy(v,va_arg(ap,char *));
  
  for(j=0;j<strlen(v);j++)
  
  fputc(v[j],stdout);
  }
  }
  break;
  
default :fputc(*(p+i),stdout); break;
}

i++;
}

va_end(ap);
}


int main()
{
char nom[]="Leo";
int age=21;
ma_printf("\n--->Je m'appelle %s, j'ai %d ans\n",nom,age);
return 0;
}






