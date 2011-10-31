//SRM498 DIV2 500
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class FoxSequence
{
public:

string isValid(vector <int> seq)
  {
    int a,b,c,d,n;
    int i,j,k,v;
    int d1,d2;

    n = seq.size();
    d1 = seq[ 1 ] - seq[ 0 ];
    d2 = seq[ n - 1 ] - seq[ n - 2 ];
    if(d1 < 0 or d2 > 0)
      return "NO";
    else
      for(i = 1 ; i < n - 2; ++ i)
	for(j = i + 1 ; j < n - 2 ; ++ j)
	  for(k = j ; k < n - 1; ++ k )
	    for(v = k + 1 ; v < n; ++ v)
	      {
		int w,tmp;
		bool sign = true;

		for(w = 1 ; w < i ; ++ w)//p1
		  if(seq[ w + 1 ] - seq[ w ] not_eq d1)
		    sign = false;

		if(sign)
		  for(w = n - 2 ; w >= v ; -- w)//p5
		    if(seq[ w + 1 ] - seq[ w ] not_eq d2)
		      sign = false;
		   
		if(sign)
		  {
		    tmp = seq[ i + 1 ] - seq[ i ];//p2
		    if(tmp > 0 ) {sign = false;break;}
		    for(w = i + 2 ; w <= j ; ++ w)
		      if(seq[ w ] - seq[ w - 1] not_eq tmp)
			sign = false;
		  }

		if( sign )
		  for(w = j  ; w < k ; ++ w)//p3
		    if(seq[ w ] not_eq seq[ w + 1 ])
		      {sign = false;break;}

		if( sign )
		  {		
		    tmp = seq[ k + 1 ] - seq[ k];
		    if(tmp < 0 ) sign = false;
		    else
		      for(w = k + 2 ; w <= v ; ++ w)
			if(seq[ w ] - seq[ w - 1 ] not_eq tmp)
			  {sign = false;break;}
		  }
		
		
		if( sign )
		  return "YES";
		  
	      }
    return "NO";
  }  
};

FoxSequence test;
/*
  1,3,5,7,5,3,1,1,1,3,5,7,5,3,1
  1,3,4,3,1,1,1,1,3,4,3,1
  1,2,3,2,1,2,3,2,1,2,3,2,1
  3,6,9,1,9,5,1
*/
int main()
{
  vector <int> a;
  int i,n,tmp;

  cin>>n;
  for(i = 1;i <= n ; ++ i)
    {
      cin>>tmp;
      a.push_back(tmp);
    }

  cout<<test.isValid(a)<<"\n";
  return 0;
}
