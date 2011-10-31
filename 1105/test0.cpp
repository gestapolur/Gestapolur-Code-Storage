#include<cstdlib>
#include<cstdio>

using namespace std;

FILE *in,*out;

int main()
{
  //in = fopen("test.in","r");
  out = fopen("test.out","w");
  fprintf(out , "hello\n");
  fclose( out );
  return 0;
}
