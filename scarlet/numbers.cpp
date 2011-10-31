/*CERC 2007 numbers */
#include<iostream>
#include<string>
using namespace std;

int ndig , n ;
bool type ;//0 x to oct , 1 oct to x 

bool init()
{
  string dig;
  cin>>dig;
  if( dig == "end" ) return false ;
  int tn ;
  tn = dig.size();
  if( dig[ 0 ] == 't' )
    {
      type = true ;
      int i = 1 ;
    }
  else
    {
      type = false;
    }
  
  cin>>n;
  return true ;
}

void work()
{
  if( type )
    {

    }
  else
    {}
  return ;
}

int main()
{
  while( init() > 0 )
    work();
  return 0 ;
}
