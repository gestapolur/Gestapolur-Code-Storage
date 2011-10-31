#include<iostream>
#include<string>
using namespace std;

string cur;

int main()
{
  cin>>cur;
  while( not ( cur[ 0 ] == '2' and cur[ 1 ] == '4' and cur[ 3 ] == '0' and cur[ 4 ] == '0' ) )
    {
      
      cur[ 4 ] ++ ;
      
      if( cur[ 4 ] > '9' ) 
	{
	  cur[ 4 ] = '0' ; 
	  cur[ 3 ]+=1;
	  if( cur[ 3 ] == '6' ) 
	    {
	      cur[ 3 ] = '0' , cur[ 1 ] +=1 ;
	      if( cur[ 1 ] > '9' ) cur[ 1 ] = '0' , cur[ 0 ] +=1;
	    }
	}
     
      if( cur[ 0 ] == cur[ 4 ] and cur[ 1 ] == cur[ 3 ] ) break;
    }

  if( cur[ 0 ] == '2' and cur[ 1 ] == '4' ) cur[ 0 ] = '0' , cur[ 1 ] = '0';
  cout<<cur<<"\n";
  return 0;
}
