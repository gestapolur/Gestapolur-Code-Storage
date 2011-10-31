//ugc_stat
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

string T;
vector <string> P;

int KMP(string T,string P)
 {
   int n,m,q,i,k;   
   int res = 0;
   n=T.size() - 1;
   m=P.size() - 1;

   vector <int> pie(m + 1);
   pie[1]=0; 
   k=0;      
   for(q=2;q<=m;++q)     
     {
       while(k>0 && P[k+1] != P[q])                   
	 k=pie[k];
       if(P[k+1] == P[q])
	 ++k;                   
       pie[q]=k;
     }

   q=0; 
   for(i=1;i<=n;++i)      
     {
     while(q>0 && P[q+1] != T[i])
       q=pie[q];
     if(P[q+1]==T[i])
       ++q;
     if(q == m)
       {
	 ++res;
	 q = pie[q];                            
       }
     }
   return res;
 }

int main(int argc , char *argv[])
{
  ifstream din(argv[1]);
  ifstream fin(argv[2]);
  string tmp;
  int n,ans,i;

  while(getline(din,tmp))
    P.push_back(" " + tmp);
  n = P.size();

  while(getline(fin,T))
    {
      i = 0;
      while(T[i] != ' ' or T[i] != '	')
	cout<<T[i++];
      cout<<" ";
      T.erase(1,i - 1);
      ans = 0;
      for(i = 0;i < n ; ++ i)
	ans+=KMP(T,P[i]);
      cout<<ans<<"\n";
    }
  return 0;          
}
