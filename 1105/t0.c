//#define LOCAL
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
int main()
{
#ifdef LOCAL
  printf("defined\n");
#endif
  return 0;
}
