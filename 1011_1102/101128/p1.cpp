#include<iostream>
#define MAXN 1002
using namespace std;

bool w[MAXN][MAXN];

class RobotSimulation
{
public:
  int cellsVisited(string program, int times)
  {
    int rec = 0,prec,ans = 1,n,i,rx = 500,ry = 500;
    
    n = program.size();
    w[rx][ry] = true;
    do{
      
      --times;
      prec = rec;
      //cout<<"ans : "<<rec<<" "<<prec<<"\n"<<rx<<" "<<ry<<"\n";cin.get();
      rec = 0;

      for(i = 0 ; i < n ; ++ i)
	{
	  switch (program[i])
	    {
	    case 'U' :
	      ++ry;
	      break;
	    case 'D' :
	      --ry;
	      break;
	    case 'L' :
	      --rx;
	      break;
	    case 'R' :
	      ++rx;
	      break;
	    default :
	      break;
	    }
	  //cout<<"   "<<rx<<" "<<ry<<"\n";
	  if(not w[rx][ry])
	    {w[rx][ry] = true;++rec;}
	}
      ans+=rec;
      cout<<ans<<" "<<times<<"\n";cin.get();
    }while(rec not_eq prec and times > 0);
    
    ans = ans + prec*times;
    
    return ans;
  }  
};

RobotSimulation test;

int main()
{
  string a;
  int b;
  cin>>a>>b;
  cout<<test.cellsVisited(a,b)<<"\n";
  return 0;
}
