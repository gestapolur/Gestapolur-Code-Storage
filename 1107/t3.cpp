#include<iostream>
using namespace std;

int a[ 502 ] , n , m ;

int main()
{
 int i , t , j , tmin , k ;
 while(cin>>n>>m)
   {
 for( i = 1 ; i <= n ; ++ i )
     cin>>a[ i ];
 for( i = 1 ; i <= n ; ++ i )
   {
     tmin = 1002; k = 0 ;
     for( j = 1 ; j <= n ; ++ j )
       if(a[ j ] not_eq -1 and a[ j ] > m and tmin > a[ j ] ) tmin = a[ j ] , k = j ; 
     if( k == 0 )
      {
       for( j = 1 ; j <= n ; ++ j )
          if( a[ j ] not_eq -1 )
            ++ m;
       goto end;
      }
     else 
       m += 2 , a[ k ] = -1;
   }

  end:cout<<m<<"\n";
   }
 return 0;
}
