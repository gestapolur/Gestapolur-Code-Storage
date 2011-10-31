/*
Class:
MatrixShiftings
Method:
minimumShifts
Parameters:
vector <string>, int
Returns:
int
Method signature:
int minimumShifts(vector <string> matrix, int value)
(be sure your method is public)
*/

#include<iostream>
#include<vector>
using namespace std;

const int INF = 2141483647;
const int MAXN = 52;
int mat[MAXN][MAXN];
int miw[MAXN][MAXN];
int ans = INF,n,m;

class MatrixShiftings
{
public:
  void search(int x,int y,int p)
  {
    if(x == n) x = 0 ; if(y == m) y = 0;
    if(x < 0) x = n; if(y < 0) y = m;
    if(p >= miw[x][y]) return ;
    else
      miw[x][y] = p;
    if(x==0 and y==0) return;
    search(x+1,y,p+1);
    search(x-1,y,p+1);
    search(x,y+1,p+1);
    search(x,y-1,p+1);
    return ;
  }

  int minimumShifts(vector <string> matrix,int value)
  {
    int i,j,x,y;
    n = matrix.size();
    m = matrix[0].size();
    cout<<n<<""<<m<<"\n";
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
	mat[i][j] = matrix[i][j] - 48;

    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
	if(mat[i][j] == value)
	  {
	    search(i,j,0);
	    if(ans > miw[0][0]) ans = miw[0][0];
	    for(x=0;x<n;x++)
	      for(y=0;y<m;y++)
		miw[x][y] = INF;
	  }
    if(ans == INF) return -1;
    return ans;
  }
};

MatrixShiftings test;

int main()
{
  int r;
  //vector <string> t;
  //t = {"1,3,6","4,2,7","5,6,8","3,0,9"};
  r = test('136,427,568,309',2);
  //r = test(t,2);
  cout<<r<<"\n";
  return 0;
}
