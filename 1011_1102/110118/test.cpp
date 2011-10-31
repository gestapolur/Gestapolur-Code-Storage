#include<iostream>
using namespace std;
const int MAXN=102;
int n,q,value[MAXN][MAXN],ans[MAXN][MAXN];
struct node
{
  int l,r;
}nd[MAXN];
 
void build_tree(int p)
{
   int flg=0;
   for (int i=1;i<=n;++i)
     if (value[p][i] && (!nd[i].l))
       {
     flg=1;
     if (nd[p].l==0) nd[p].l=i;
     else
       {nd[p].r=i; break;}
       }
   if (!flg) return;
   if (nd[p].l) build_tree(nd[p].l);
   if (nd[p].r) build_tree(nd[p].r);
 }
 
 void calc(int p)
 {
   if (!nd[p].l) return;
   int l=nd[p].l,r=nd[p].r;
   calc(l);
   calc(r);
   ans[p][1]=max(value[l][p],value[r][p]);
 
   int d=value[l][p]+value[r][p];
   for (int i=2;i<=q;++i)
   {  
     ans[p][i]=max(ans[l][i-1]+value[l][p],ans[r][i-1]+value[r][p]);
     for (int j=0;j<=i-2;++j)
       ans[p][i]=max(ans[p][i],ans[l][j]+ans[r][i-j-2]+d);
   }
 }
 
 
 int main()
 {
   //freopen("data.in","r",stdin);
   //freopen("data.out","w",stdout);
   cin >> n >> q;
   memset(value,0,sizeof(value));
   for (int i=1;i<n;++i)
     {
       int a,b,c;
       cin >> a >> b >> c;
       value[a][b]=c;
       value[b][a]=c;
     }
   memset(nd,0,sizeof(nd));
   build_tree(1);
   calc(1);
   cout << ans[1][q] << endl;
   return 0;
 }
