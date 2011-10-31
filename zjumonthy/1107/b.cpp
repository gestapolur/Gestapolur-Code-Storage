#include <stdio.h>
#include <queue>

int n,r,l;

struct PT
{
  int x,y;
};
PT pt[50000];
bool fd[50000];

int main()
{
  
  while(scanf("%d%d%d",&n,&r,&l)!=EOF)
    {
      int i;
      int ans=0;
      for(i=0;i<n;i++)
	{
	  scanf("%d%d",&pt[i].x,&pt[i].y);
	  fd[i]=false;
	}
      std::queue<PT> q;
      PT p;
      long long rr=(long long)r*r;
      scanf("%d%d",&p.x,&p.y);
      q.push(p);
      long long ll2=(long long)l*l;
      long long ll=rr;
      while(!q.empty())
	{
	  p=q.front();
	  q.pop();
	  for(i=0;i<n;i++)
	    {
	      if(fd[i])continue;
	      if((long long)(pt[i].x-p.x)*(pt[i].x-p.x)+(long long)(pt[i].y-p.y)*(pt[i].y-p.y)<=ll)
		{
		  ans++;
		  fd[i]=true;
		  q.push(pt[i]);
		}
	    }
	  ll=ll2;
	}
      printf("%d\n",ans);
    }
  return 0;
}
