#include <stdio.h>
#include <string.h>

char a[1010], b[10000];
int ac[1010][26], min[2][1010][2];

void init_AC(char *p) 
{
  int pi[1010], k = -1, len = strlen(p);
  pi[0] = -1;
  memset(ac, 0, sizeof(ac));
  ac[0][*p - 'a'] = 1;
  for(int i = 1; i < len; ++i) 
    {
      //从0开始与自身错位匹配的信息（KMP的过程）
      while(k >= 0 && p[k + 1] != p[i]) k = pi[k];
      if(p[k + 1] == p[i]) ++k;
      pi[i] = k;
      //ac[ i , x ] = ac[ pi[ i - 1 ] + 1 , x ] x = 1..26
      //pi[ i - 1 ] + 1 , 
      memcpy(ac[i], ac[pi[i - 1] + 1], sizeof(ac[0]));
      //不匹配i的时候，匹配之前的？
      ac[i][p[i] - 'a'] = i + 1;
    }
  return ;
}


int solve() 
{
    int i, j, l, k, re = -1;
    memset(min, -1, sizeof(min));
    min[0][0][0] = 0; min[0][0][1] = -1;
    min[1][0][0] = 0; min[1][0][1] = -1;

    for(i = 0; b[i]; ++i) 
      {
        printf( "%d\n" , i );
        l = b[i] - 'a';
        //状态 a[ j ] equal to j < m( length of a )
        //j -> ac[ j , b[ i ] - 'a' ] or now pattern at i
        for(j = 0; a[j] && min[0][j][0] != -1; ++j) {
            k = ac[j][l];
            if(min[1][k][0] == -1 || min[1][k][0] - min[1][k][1] > min[0][j][0] - min[0][j][1] - 1) {
                    min[1][k][0] = min[0][j][0] + i - min[0][j][1] - 1;
                    min[1][k][1] = i;
            }
            printf( "%d %d %d %d %d\n" , i , j , k , min[ 1 ][ k ][ 0 ] , min[ 1 ][ k ][ 1 ] );
        }
        memcpy(min[0], min[1], sizeof(min[0]));
    }
                                                        
    for(j = 0; a[j] && min[0][j][0] != -1; ++j) {
      printf( "%d %d:%d " , i , min[ 0 ][ j ][ 0 ] , min[ 0 ][ j ][ 1 ] );
      if(re == -1 || min[0][j][0] + i - min[0][j][1] - 1 < re) {
        re = min[0][j][0] + i - min[0][j][1] - 1;
        }
        //printf( "\n" );
    }
    return re;
}

int main() {
while(gets(b)) {
        gets(a);
        init_AC(a);
        printf("%d\n", solve());
}
return 0;
}
