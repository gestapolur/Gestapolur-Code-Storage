#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=160,OO=2147483647;
int w[maxn][maxn];
int lx[maxn],ly[maxn];
int linky[maxn];
int visx[maxn],visy[maxn];
int N;
int slack[maxn];

void input(){
	scanf("%d",&N);
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			scanf("%d",&w[i][j]);
}
bool find(int x){
	visx[x]=true;
	for(int y=0;y<N;++y){
		if(visy[y])continue;
		int t=lx[x]+ly[y]-w[x][y];
		if(t==0){
			visy[y]=true;
			if(linky[y]==-1||find(linky[y])){
				linky[y]=x;
				return true;
			}
		}
		else{
			if(slack[y]>t)
				slack[y]=t;
		}
	}
	return false;
}
void KM(){
	memset(linky,-1,sizeof(linky));
	memset(lx,0,sizeof(lx));
	memset(ly,0,sizeof(ly));
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			if(w[i][j]>lx[i])
				lx[i]=w[i][j];
	for(int x=0;x<N;++x){
		for(int i=0;i<N;++i)
			slack[i]=OO;
		for(;;){
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			if(find(x))break;
			int d=OO;
			for(int i=0;i<N;++i){
				if(!visy[i])
					if(d>slack[i])
						d=slack[i];
			}
			for(int i=0;i<N;++i){
				if(visx[i])
					lx[i]-=d;
			}
			for(int i=0;i<N;++i){
				if(visy[i])
					ly[i]+=d;
				else
					slack[i]-=d;
			}
		}
	}
}
void output(){
	int res=0;
	/*
	for(int i = 0 ; i < N ; ++ i)
	  {
	    for(int j = 0 ; j < N ; ++ j)
	      printf("%d ",w[ i ][ j ]);
	    printf("\n%d %d\n" ,linky[ i ] , w[ linky[ i ] ][ i ]);
	  }
	*/
	for(int j=0;j<N;++j){
		for(int i=0;i<N;++i)
			res+=w[i][j];
		res-=w[linky[j]][j];
	}
	printf("%d\n",res);
}
int main(){
	input();
	KM();
	output();
}
