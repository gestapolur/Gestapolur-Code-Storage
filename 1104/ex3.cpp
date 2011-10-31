#include<fstream>
#include<string>

using namespace std;

ifstream cin("B-large-practice.in");
ofstream cout("ans.out");

int main()
{
  int n,k,m,i,j;
  string tmp,rev;

  cin>>n;
  //cout<<n<<"\n";
  getline(cin,tmp);
  k = 1;
  while(k <= n )
    {
      getline(cin,tmp);
      //cout<<tmp<<" out \n";
      m = tmp.size();
      cout<<"Case #"<<k<<": ";
      for(i = m - 1 ; i >= 0 ; -- i)
	if(tmp[ i ] == ' ')
	  {
	    for(j = rev.size() - 1 ; j >= 0 ; -- j)
	      cout<<rev[ j ];
	    cout<<" ";
	    rev = "";
	  }
	else
	  {
	    rev += tmp[ i ];
	    if(i == 0)
	      {
		for(j = rev.size() - 1 ; j >= 0 ; -- j)
		  cout<<rev[ j ];
		rev = "";
	      }
	  }
      cout<<"\n";
      ++k;
    }

  return 0;
}
