//GCJ 2011 QR a
#include<fstream>
#define MAXN 205
using namespace std;

ifstream cin("A-large.in");
ofstream cout("ans.out");

int n,t;
int s[ MAXN ],turn[ MAXN ];
int pa,pb,na,nb,tot;

int main()
{
  int i,tt;
  bool ea , eb;
  char ch;
  cin>>t;
  tt = t;
  while(t > 0)
    {
      cin>>n;
      tot = 0 ;pa = pb = na = nb = 0 ;
      for(i = 1 ;i <= n; ++ i)
	{
	  cin>>ch>>s[i];
	  if(ch == 'O')
	    turn[ i ] = 0 ;
	  else
	    turn[ i ] = 1;
	}
      
      pa = 1 , pb = 1 , i = 1;
      while(i <= n )
	{
	  if(turn[ i ] == 0 )
	    {na = i ; break;}
	  ++i;
	}
      i = 1 ;
      while(i <= n )
	{
	  if(turn[ i ] == 1 )
	    {nb = i ; break;}
	  ++i;
	}
      //cout<<na<<" "<<nb<<"\n";
      i = 1;ea = false ; eb = false;
      bool psa,psb;
      while(i <= n )
	{
	  //cout<<na<<" "<<nb<<" "<<i<<" pos "<<pa<<" "<<pb<<"\n";
	  //a
	  if(s[ na ] == pa and na == i)
	    {
	      //cout<<"push a \n";
	      ++i;
	      do{ ++ na ; }while(turn[ na ] == 1 and na <= n );
	      if(na > n ) ea = true;
	      psa = true;
	    }
	  else if(s[ nb ] == pb and nb == i)
	    {
	      //cout<<"push b \n";
	      ++i;
	      do{ ++nb; }while(turn[ nb ] == 0 and nb <= n );
	      if(nb > n ) eb = true;
	      psb = true;
	    }
	  
	  if(pb not_eq s[nb] and not psb)
	    {
	      if(pb > s[nb]) --pb;
	      else if(pb < s[ nb ] )++pb;
	    }	 
	  if(pa not_eq s[na] and not psa)
	    {
	      if( pa > s[na] ) --pa;
	      else if(pa < s[ na ] )++pa;
	    }
	  psa = psb = false;
	  ++tot;
	  if(ea and eb ) break;
	}
      cout<<"Case #"<<tt-t+1<<": "<<tot<<"\n";
      --t;
    }
    
  return 0;
}
