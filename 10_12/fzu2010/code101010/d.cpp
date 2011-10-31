//prob D
#include<iostream>
#define MAXN 2001
using namespace std;

int n;
int k[MAXN],m[MAXN];

void sort(int i,int j,int *a)
{
    if(i >= j) return ;
    int m,n,t,k;
    m = i,n = j,k =a[i + j >> 1];
    while(m<=n)
        {
            while(a[m] < k)
               m++;
            while(a[n] > k)
               n--;   
            if(m <= n)
              {
                t = a[m];      
                a[m] = a[n];
                a[n] = t;
                m++;
                n--;   
              }
        }
        
    sort(i,n,a);
    sort(m,j,a);
        
    return ;
}

void work(int x)
{
    int mp =1 ,kp =1 ,ans = 0;
    
    sort(1,n,k);
    sort(1,n,m);
    //for(int i=1;i<=n;i++) cout<<k[i]<<" ";cout<<"\n";
    //for(int i=1;i<=n;i++) cout<<m[i]<<" ";cout<<"\n";
    while(kp <=n and mp <= n)
      {
        while(k[kp] < m[mp] and kp <= n)
            kp++;
        if(kp <= n)
           {
              kp++;
              mp++;
              ans++;     
           }
      }
      
    cout<<"Case "<<x<<": "<<ans<<"\n";
    
    return ;    
}

int main()
{
    int i,j,t;
    cin>>t;
    for(i=1;i<=t;i++)
        {
          cin>>n;
          
          for(j=1;j<=n;j++)
            cin>>k[j];
          for(j=1;j<=n;j++)
            cin>>m[j]; 
            
          work(i);
        }

    return 0;
}
