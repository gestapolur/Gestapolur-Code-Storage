/*
  Hunan collegiate contest 2011 E
  write by gestapolur
  20110920
  Hint : Dare To Win !
*/
#include<cstdio>

int main()
{
  int n ;
  while( scanf( "%d" , &n ) ) 
    {
      if( n == 0 ) return 0;
      //printf("%d\n" , ( n & 1 ) );
      if( ( n & 1 ) == 0 )
        printf("Alice\n");
      else
        {
          int tmp = n ;
          while( tmp > 3 )
            {
              tmp >>= 1;
              if( ( tmp & 1 ) == 0 ) {printf("Alice\n");break;}
            }
          if( ( tmp & 1 ) == 1 ) printf("Bob\n");
        }
    }
  return 0;
}
