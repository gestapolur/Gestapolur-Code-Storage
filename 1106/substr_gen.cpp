#include<cstdlib>
#include<cstdio>
using namespace std;

FILE *out;

int main()
{
  out = fopen("substr.in","w");
  char t = '!';
  fprintf(out,"1\n");
   
  for(int i = 1 ; i <= 1000 ; ++ i)
    {
      fprintf(out,"%c",t);
      printf("%d ",t);
      t = t + 1 ;
      if( t == 126 ) t = '!';
    }
  printf("\n");
  fprintf(out,"\n");
  
  return 0;
}
