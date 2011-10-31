/*HNU 7TH J */
#include<iostream>
#include<algorithm> 
#include<cstdlib>
#include<cstdio>
#include<queue> 
using namespace std; 
const int maxn=100001;
struct node{ 
    int d,v;
    node(int dd=0,int vv=0){d=dd;v=vv;}    
    }a[maxn]; 
int dp[maxn]; 
bool cmp(node a,node b){return a.d<b.d;} 
priority_queue<int>q; 
int main(){ 
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //double t1=clock();
    int i,j,k,t,n,m,ans,D,V; 
    while(scanf("%d%d",&n,&m)!=EOF){
          int len=0; 
          for(i=0;i<n;i++){
              scanf("%d%d",&D,&V);
              if(D>m)D=m;
              a[len++]=node(D,V); 
	  } 
          n=len;    
          sort(a,a+n,cmp);t=m;
	  for( i = 0 ; i < n ; ++ i ) cout<<a[ i ].d<<" "<<a[ i ].v<<"\n";
          while(!q.empty())q.pop(); 
          for(ans=0,i=n-1;i>=0;i--){ 
              while(t>a[i].d&&!q.empty()){ 
                    ans+=q.top();q.pop(); 
                    t--;                       
                    }          
              q.push(a[i].v);t=a[i].d;                    
              }   
          while(t>0&&!q.empty()){ 
                ans+=q.top();q.pop(); 
                t--;                                   
                }                   
          cout<<ans<<endl;            
          } 
    //printf("%.2lf\n",clock()-t1);      
    return 0; 
    } 
