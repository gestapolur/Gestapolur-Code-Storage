//SRM #486 DIV 2 500
#include<iostream>
#include<string>
#include<vector>
#include<bitset>
#define MAXN 2141483647
#define MAXH 20000
#define HX 19993

using namespace std;

class OneRegister
{
public:
  unsigned long long dt;
  string ans;
  vector <unsigned long long> hash[MAXH];
  vector <unsigned long long> hl[MAXH];

  void h(unsigned long long x,unsigned long long p)
  {
    hash[x % HX].push_back(p);
    hl[x % HX].push_back(x);
    return ;
  }

  unsigned long long rh(int x)
  {
    int t = x % HX,s;
    s = hl[t].size();
    for(int i = 0;i < s ;++ i)
      if(hl[t][i] == x)
	return hash[t][i];
    return MAXN;
  }

  void bfs(string p ,unsigned long long num )
  {
    //cout<<p<<" "<<num<<" "<<p.size()<<"\n";
    //cin.get();
    if(num == dt)
      {
	if(ans == "" or p.size() < ans.size())
	  ans = p;
	return ;
      }
    else if(num > dt) return ;
    
    if((num * num) <= dt and rh(num*num) > p.size() )
      {
	h(num*num,p.size()+1);
	bfs(p + "*",num * num);
      }
    
    if((num<<1) <= dt and rh(num<<1) > p.size())
      {	
	h(num<<1,p.size()+1);
	bfs(p + "+",( num << 1 ));
      }

    return ;
  }
  
  string getProgram(unsigned long long s,unsigned long long t)
  {
    dt = t;
    ans = "";

    h(s,0);

    if(s not_eq t)
      {
	bfs("",s);
	if(s not_eq 0)
	  bfs("/",1);
	bfs("-",0);
	if(ans == "")
	  ans = ":-(";
      }
    cout<<ans<<"\n";

    return ans;
  }
  
};

int main()
{
  int s,t;
  OneRegister test;
  cin>>s>>t;
  test.getProgram(s,t);
  return 0;
}
