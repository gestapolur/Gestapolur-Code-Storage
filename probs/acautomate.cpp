#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#define MAXN 10002
using namespace std;

char t[ MAXN ] , p[ MAXN ];
int ac[ MAXN ][ 27 ];

void ahocrosick()
{
  int pi[ MAXN ], k = -1, len = strlen(p);

  pi[0] = -1;
  memset(ac, 0, sizeof(ac));

  ac[0][*p - 'a'] = 1;

  for(int i = 1; i < len; ++i ) 
    {
      while(k >= 0 && p[k + 1] != p[i]) k = pi[k];
      if(p[k + 1] == p[i]) ++k;
      pi[i] = k;
      memcpy(ac[i], ac[pi[i - 1] + 1], sizeof(ac[0]));
      printf( "%d %d\n" , i , pi[ i - 1 ] + 1 );
      ac[i][p[i] - 'a'] = i + 1;
    }
  
  for( int i = 0 ; i < len ; ++ i ) cout<<pi[ i ]<<" "; cout<<"\n";

  for( int i = 0 ; i < len ; ++ i )
    {
      for( int j = 0 ; j < 26 ; ++ j )
        cout<<ac[ i ][ j ]<<" ";
      cout<<"\n";
    }
  return ;
}

int main()
{
  cin>>t>>p;

  ahocrosick();

  return 0;
}
