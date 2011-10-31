#include<iostream>using namespace std;
int fun(int x){	if( not (x%7))		return 1;	while(x>0)	{		if((x%10)==7)			return 1;		x/=10;	}	return 0;}int main(){	int n,i,j,k,r,a,b,d,cou;
	while(cin>>r)	{
		cin>>b>>d>>n;		cou=0;		for(i=d+1;;i++)		{			if(fun(i))				cou++;			if(cou==n)				break;		}
		cout<<((i-d+b+r-1)%r+1)<<"\n";			}	return 0;}
