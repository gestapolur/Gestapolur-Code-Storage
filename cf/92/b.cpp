#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define MAXN 10
#define INF 2141483647
using namespace std;

int con[MAXN],org[ MAXN ][MAXN] , n , k ;
int ans ; 

void init()
{
  ans = INF;
  char ch;
  cin>>k>>n;getchar();
  for( int i = 1 ; i <= k ; ++ i )
    {
      for( int j = 1 ; j <= n ; ++ j )
        {
          ch = getchar();
          org[ i ][ j ] = ch - 48;
        }
      getchar();
    }
  /*
  for( int i = 1 ; i <= k ; ++ i )
    {
      for( int j = 1 ; j <= n ; ++ j )
        cout<<org[ i ][ j ]<<" ";
      cout<<"\n";
    }
  */
  return ;
}

bool check(int k)
 {
  int i;
  for(i=1;i<k;i++)
    if(con[i]==con[k])
       return false;
  return true;         
 }
 
void dfspara()
{
  int tmp , tmin , tmax;
  int i,j,p=1,tot=0,pa=1;
  bool mark=false;
  /*
  cin>>n;
  for(i=1;i<=n;i++)
    {
      cin>>org[ i ];
      con[i]=1;
      pa*=i;              
    }    
  */
  for( i = 1 ; i <= n ; ++ i ) {con[ i ] = 1 ; pa *= i;}
  while(tot<pa)
    {
      if(p>n)
        {
          tmin = INF , tmax = 0 ;
          for( j = 1 ; j <= k ; ++ j )
            {
              tmp = 0 ;
              for( i = 1 ; i <= n ; ++ i )
                tmp = tmp * 10 + org[ j ][ con[ i ] ]; 
              tmin = tmp < tmin ? tmp : tmin;
              tmax = tmp > tmax ? tmp : tmax;
            }
          ans = ans < ( tmax - tmin ) ? ans : ( tmax - tmin );
          p--;
          tot++;
          mark=true;     
        }             
      else
        {
          if(!mark)
            {
              while(!check(p))
                con[p]++;
              p++;          
            }
          else
            {
              if(con[p]<n)
                {
                  while(mark and con[p]<n)
                    {          
                      con[p]++;              
                      if(con[p]<=n and check(p))
                        {mark=false;break;}
                    }
                  if(mark)
                    {con[p]=1;p--;}   
                }
              else
                {con[p]=1;p--;}       
            }                             
        }        
    }     
  return ;     
}
 
int main()
 {
   init();
   dfspara();
   cout<<ans<<"\n";
  //system("pause"); 
  return 0;       
 }
