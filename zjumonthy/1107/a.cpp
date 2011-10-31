#include<cstdlib>
#include<cstdio>

long long n;

int main()
{
  while ( scanf("%lld" , &n ) not_eq EOF )
    printf("%lld\n" , ( n >> 1 ) * ( n - ( n >> 1 )) );
  return 0;
}
