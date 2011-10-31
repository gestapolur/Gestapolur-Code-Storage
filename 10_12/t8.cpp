#include<iostream>
#include<cstdio>
#define MAXN 100001
using namespace std;
/*
ifstream cin("frac1.in");
ofstream cout("frac1.out");
*/
class fra
{
public:
  unsigned short int a,b;
  fra *next;
};

class save
{
public:
  unsigned short int a,b;
  double f;    
};

save s[MAXN];
fra *res[MAXN]={NULL};
int n,tot;

void out(int pos)
{
  fra *p;
  cout<<"test\n";
    if(res[pos] != NULL)
      {
	p = res[pos];
	do{
	  cout<<p->a<<"/"<<p->b<<" ";
	  p = p->next;
	}while(p != NULL);
	cout<<"\n";   
      }
  return ;
}

void sort(int i,int j)
{
    if(i>=j)
        return ;
    int m = i,n = j;
    double k = s[i+j>>1].f;
    save t;
    while(m<=n)
        {
             while(s[m].f < k)
                m++; 
             while(s[n].f > k)
                n--;
             if(m<=n)
               {
                 t = s[n];     
                 s[n] = s[m];
                 s[m] = t;
                 m++;
                 n--;   
               }
        }
    sort(i,n);
    sort(m,j);    
    return ;    
}

bool add(int pos ,int a , int b)
{
  if(res[pos] == NULL)
   {
      res[pos] = new fra;
      res[pos]->a = a;
      res[pos]->b = b;
      res[pos]->next = NULL;
   }
  else
   {
      fra *p = res[pos],*ins;
      do{
          if(p->a == a && p->b == b)
             return false;  
          p = p->next;
      }while(p != NULL);
      ins = new fra;
      ins->next = NULL;
      ins->a = a;
      ins->b = b;
      p = res[pos];    
      while(p->next != NULL)
           p = p->next;
      p->next =  ins;  
   }    
  return true;
}

void create(int l , int r)
{
  fra *L,*R;
  if(l == 2)
    {
      cout<<l<<" "<<r<<"pos\n";
      cout<<res[l]->a<<"/"<<res[l]->b<<" LEFT\n";
      cout<<res[r]->a<<"/"<<res[r]->b<<" RIGHT\n";
      cout<<res[l]->a+res[r]->a<<"/"<<res[l]->b+res[r]->b<<"\n";getchar();
    }
  L = res[l];
  while(L->next != NULL)
    L = L->next;
  R = res[r];  
  while(R->next != NULL)
    R = R->next;
  if(L->b + R->b <= n )
    {
      int mid = l + r >> 1;
      if(l+1 not_eq r and add(mid , L->a + R->a , L->b + R->b))
	{
	  create(l,mid);
	  create(mid,r);
	}
      
      else if(l+1 == r and add(r , L->a + R->a , L->b + R->b))
	       create(l,r);
      
    }
  return ;
}



int main()
{
  cin>>n;
  //cin.close();
  int i;
  fra *p; 
  res[1] = new fra;res[MAXN - 1] = new fra;
  res[1]->a = 0,res[1]->b = 1,res[1]->next = NULL;
  res[MAXN - 1]->a = 1,res[MAXN - 1]->b = 1,res[MAXN - 1]->next = NULL;

  create(1, MAXN - 1);

  for(i=1;i<MAXN;i++)
    if(res[i] != NULL)
       {
         p = res[i];
         do{
            //cout<<p->a<<"/"<<p->b<<"\n";
            s[++tot].a = p->a;
            s[tot].b = p->b;
            s[tot].f = double(p->a) / double(p->b);
            p = p->next;
         }while(p != NULL);
       }
  sort(1,tot);
  /*
  for(i=1;i<=tot;i++)
    cout<<s[i].a<<"/"<<s[i].b<<"\n";
  */
  //cout.close();
  return 0;
}
