#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char a[100];

int main()
{
  int i;
  i = 0 ; 
  while( scanf("%c", &a[ i ++ ]) && a[ i - 1 ] != '\n');//{putchar(a[ i - 1 ]);}
  //a[i]='\0';
  printf("%d\n",a[ i ]);
    puts(a);
  return 0;
}
