//ugc_stat
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
using namespace std;

ifstream fin("./code/sns/content.txt");
ifstream din("./code/sns/keyword.txt");

string T;
vector <string> P ;

int* compute_prefix_fun(string P)
 {
  int n,k,q;       
  n = P.size() ;
  int *pie=new int[n+1];
  pie[1]=0;
  k=0;      
  for(q=2;q<=n;++q)     
     {
     while(k>0 and P[k+1] not_eq P[q])                   
         k=pie[k];
     if(P[k+1]==P[q])
         ++k;                   
     pie[q]=k;
     }
  return pie;
 }

int KMP(string T,string P)
 {
  int n,m,q,i,j;   
  int *pie;
  int res = 0;
  n=T.size() ;
  m=P.size() ;
  pie=compute_prefix_fun(P);   
  q=0; 
  for(i=1;i<=n;++i)      
    {
     while(q>0 and P[q+1] not_eq T[i])
        q=pie[q];
     if(P[q+1]==T[i])
        ++q;
     if(q==m)
       {
	 //cout<<"Parttern Shift Occured\n";
	 ++res;
	 q=pie[q];                            
       }
    }
  return res;
 }

int main()
{
  string tmp;
  int n,ans,i;
  tmp ="";
  while(getline(din,tmp))
    {
      P.push_back(tmp);
      tmp = "";
    }
  n = P.size();
  /*
  cout<<n<<"\n";
  for(i = 0;i< n;i++)
    cout<<P[i]<<"\n";
  return 0;
  */
  while(getline(fin,T))
    {
      i = 0;
      while(T[i] not_eq ' ' and T[i] not_eq '	')
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
