//VK CUP 2012 C
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 400002
using namespace std;

int n , m ;
string dir[ MAXN ];

void work()
{
  string cmd , path;
  int ps ;

  cin>>n;
  for( int i = 1 ; i <= n ; ++ i )
    {
      cin>>cmd;
      if( cmd == "pwd" )
        {
          cout<<"/";
          for( int j = 1 ; j <= m ; ++ j )
            cout<<dir[ j ]<<"/";
          cout<<"\n";
        }
      else
        {
          string tmp = "";
          cin>>path;
          ps = path.size();
          int j = 0 ; 
          if( path[ 0 ] == '/' ) { m = 0; j = 1  ; }

          while( j < ps )
            {
              if( path[ j ] not_eq '/' )
                tmp.push_back( path[ j ] );
              if( path[ j ] == '/' or j == ps - 1 )
                {
                  //cout<<tmp<<"\n";
                  if( tmp == ".." )
                    {
                      if( m > 0 )
                        -- m;
                    }
                  else
                    dir[ ++ m ] = tmp ;
                  tmp = "";
                }
              ++ j; 
            }
        }
    }
  return ;
}

/*
void work()
{
  int m ;
  string ins , tdir ;

  cin>>n;

  for( int i = 1 ; i <= n ; ++ i )
    {
      cin>>ins;
      if( ins == "pwd" )
        {
          cout<<"/"<<dir;
          if( dir.size() > 0 ) cout<<"/";
          cout<<"\n";
        }
      else
        {
          cin>>tdir;
          int j = 0 ;
          m = tdir.size();
          //cout<<m<<"\n";
          if( tdir[ j ] == '/' )
            { ++ j ; dir= ""; }
          else if( tdir[ j ] not_eq '.' and dir.size() > 0 ) dir.push_back( '/' );

          while( j < m )
            {
              if ( tdir[ j ] == '.' and tdir[ j + 1 ] == '.' )
                {
                  if( dir.size() > 0 )
                    do{
                      dir.erase( dir.size() - 1 , 1 );
                    }while( dir[ dir.size() - 1 ] not_eq '/' and dir.size() > 0 );
                  if( dir.size() > 0 )
                    dir.erase( dir.size() - 1 , 1 );
                  j += 2 ;
                }
              else
                dir.push_back( tdir[ j ++ ] );
              //cout<<j<<"\n";
            }
          //cout<<j<<" "<<dir<<"\n";
        }
      //cout<<dir<<"\n";
    }
  return ;
}
*/

int main()
{
  work();
  
  return 0;
}
