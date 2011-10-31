#include<iostream>
#define MAXN 1000
#define INF 2141483647
using std::cin;
using std::cout;
//line | cross -
int w[MAXN][MAXN],ml[MAXN],mc[MAXN],sl[MAXN],sc[MAXN];
// ml/c = mark line/cross; sl/c whether scaned
int n,m,ans;
bool st[MAXN][MAXN];
//w[cross][line]
/*
void dis()
{
  int i,j;
  cout<<"ans: "<<ans<<"\n";
  cout<<"  ";
  for(i=1;i<=n;i++) cout<<ml[i]<<" ";cout<<"\n";
  for(i=1;i<=n;i++)
    {
      cout<<mc[i]<<" ";
      for(j=1;j<=n;j++)
	cout<<st[i][j]<<" ";
      cout<<"\n";
    }
  for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
	cout<<w[i][j]<<" ";
      cout<<"\n";
    }
  
  return ;
}
*/
void independent_set()
{
  int i,j,fl=-1,fc=-1;
  bool sign,mark;
  //sign : a marked line without a star;
  //mark : every marked line & cross scaned;

  //process 1 : mark the no star line 
  for(i=1;i<=n;i++)
    {
      ml[i]=0,mc[i]=0,sl[i]=0,sc[i]=0;
      sign = false;
      for(j=1;j<=n;j++)
	if(st[j][i]) {sign = true;break;}
      if(!sign)
	ml[i] = -1;
    }
  
  //process 2 : scan & mark
  do{
    mark = false;
    for(i=1;i<=n;i++)
      if(ml[i] and sl[i]==0)
	{
	  for(j=1;j<=n;j++)
	    if(!st[j][i] and w[j][i]==0 and mc[j]==0)
	      mc[j]=i;
	  mark = true;
	  sl[i] = 1;
	}
    sign = false;
    for(i=1;i<=n;i++)
      if(mc[i] and sc[i]==0)
	{
	  for(j=1;j<=n;j++)
	    if(st[i][j])
	      {ml[j]=i;sign = true;}
	  mark = true;	
	  sc[i] = 1;
	}
  }while(sign and mark);
  
  if(!sign)// process 3 : enlarge the set
    {
      //find the first line without star
      for(i=1;i<=n;i++)
	if(mc[i])
	  {
	    for(j=1;j<=n;j++)
	      if(st[i][j])
		break;
	    if(j > n)
	      {fc = i;break;}
	  }
      if(fc == -1) return;
      fl = mc[fc];
      //trace back
      mark = true;
      do{
	if(mark)
	  {
	    st[fc][fl] = true,ans++;
	    fc = ml[fl];
	    mark = false;
	  }
	else
	  {
	    st[fc][fl] = false,ans--;
	    fl = mc[fc];
	    mark = true;
	  }
      }while(fc not_eq -1);
    }
  return ;
}

void hungry()
{
  int i,j,k,min;
  //find the minus line and cross
  for(i=1;i<=n;i++)
    {
      min = INF;
      for(j=1;j<=n;j++)
	if(min > w[i][j])
	  min = w[i][j];
      if(min)
	for(j=1;j<=n;j++)
	  w[i][j]-=min;
    }
  for(i=1;i<=n;i++)
    {
      min = INF;
      for(j=1;j<=n;j++)
	if(min > w[j][i])
	  min = w[j][i];
      if(min)
	for(j=1;j<=n;j++)
	  w[j][i]-=min;
    }

  //find the 0 set max independent set 
  while(ans < n)
    {      
      //find max independent set
      do{
	k=ans;
	independent_set();
      }while(ans not_eq k);
      
      k=INF;
      for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	  if((!mc[i] and ml[j]) and k > w[i][j])
	    k = w[i][j];
      //k is the minium value no in cover
      for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	  if(mc[i] and !ml[j])//w(i,j) on the point of cover line & cross
	    w[i][j]+=k;
	  else if(!mc[i] and ml[j])//w(i,j) not in the cover
	    w[i][j]-=k;
    }

  //out put the set num & set
  cout<<ans<<"\n";
  for(i=1;i<=n;i++)
    {
      for(j=1;j<=m;j++)
	cout<<st[i][j]<<" ";
      cout<<"\n";
    }
  return ;
}

int main()
{
  int i,j;
  cin>>n>>m;
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      cin>>w[i][j];
  //max sum solution
  /*
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
      w[i][j]=-w[i][j];
  */
  n=n<m?m:n;//unequal set;
  cout<<n<<"\n";
  hungry();

  return 0;
}
