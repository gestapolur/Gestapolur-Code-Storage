#include<iostream>
#include<cstring>
using namespace std;

//ifstream cin("game.in");
//ofstream cout("game.out");

struct Tmaze
{
  bool m[5][5];
};

int hash[65536];
int queue[10002],step[10002],num[10002];
bool start[5][5];
int Min , S;
int h , t;


void init()
{
  int i,j;
  char ch;
  for (i = 1 ; i <= 4 ; ++ i)
    {
      for (j = 1 ; j <= 4 ; ++j)
	{
	  cin>>ch;
	  start [ i ][ j ] =  ch  -  'A' ;
	}
    }
}

int code ( Tmaze maze)
{
  int i , j , S	;
  S = 0;

  for (i = 1 ;i <= 4 ; ++ i)
    for (j = 1 ;j <= 4 ; ++ j) 
      S = S * 2 + int(maze.m[ i ][ j ]);
  return S;
}

Tmaze decode ( int num)
{
  int i,j;
  Tmaze tmp;
  
  for (i = 4 ; i >= 1 ; --i)
    for (j = 4 ; j >= 1 ; --j)
      {
	tmp.m[ i ][ j ] = num & 1;
	num = num >> 1;
      }
  return tmp;
}

void clear(Tmaze &T)
{
  int i,j;
  for(i = 0 ; i <= 4 ; ++ i)
    for(j = 0 ; j <= 4 ; ++ j)
      T.m[ i ][ j ] = false;
  return ;
}

void BFS()
{
  int i,j,v;
  Tmaze tmp;
  bool sw;
  //tmp = new Tmaze;
  clear(tmp);
  h = 0 ; t = 0;//h is the head of the queue , and the queue is the tail
 
  //create possible condition
  for (i = 1 ; i<= 3 ; ++i)
    for (j = 1 ; j <= 3 ; ++j)
      {
	clear(tmp);

	tmp.m [ i ][ j ] = 1 ;
	tmp.m [ i + 1 ][ j ] = 1;
	tmp.m [ i ][ j + 1 ] = 1;
	tmp.m [ i + 1 ][ j + 1 ] = 1;
	queue [ ++t ] = code ( tmp );
	//cout<<i<<" "<<j<<" "<<queue[ t ]<<" "<<t<<"\n";
	hash [ queue [ t ] ] = t;
	step [ t ] = 0;
	num [ t ] = 1;
      }
  cout<<"head and tail : "<<h<<" "<<t<<"\n";
  //procedure of BFS
  do{
    tmp = decode ( queue [ ++h ] );
    cout<<h<<"\n";
    for(int ii = 1 ; ii <= 4 ; ++ ii)
      {
	for(int kk = 1; kk <= 4 ; ++ kk)
	  cout<<tmp.m[ ii ][ kk ];
	cout<<"\n";
      }
    for (i = 1 ;i <= 4 ; ++i)
      for (j = 1 ;j <= 3 ; ++j)
	{
	  sw = tmp.m[ i ][ j ] ; tmp.m[ i ][ j ] = tmp.m[ i ][ j + 1 ] ;tmp.m[ i ][ j + 1] = sw; 
	  v = code ( tmp );
				
	  if ( (hash [ v ] == 0) or ( step [ h ] + 1 == step [ hash [ v ] ] ))
	    {
	      if (hash [ v ] == 0)
		{
		  queue [ ++t ] = v;
		  hash [ v ] = t;
		  step [ t ] = step [ h ] + 1;
		}
	      num [ hash [ v ] ]+=num[ h ];;
	    };

	  sw = tmp.m [ i ][ j ] ; tmp.m [ i ][ j ] = tmp.m [ i ][ j + 1 ];tmp.m[ i ][ j + 1] = sw;
	}

    for (i = 1 ; i <= 3 ; ++ i)
      for (j = 1 ; j <= 4 ; ++j)
	{
	  sw = tmp.m [ i ][ j ] ; tmp.m [ i ][ j ] = tmp.m[ i + 1 ][ j ];tmp.m[ i + 1 ][ j ] = sw;
	  v = code ( tmp );
				
	  if (( hash [ v ] == 0 ) or ( step [ h ] + 1 == step [ hash [ v ] ] ))
	    {
	      if (hash [ v ] == 0)
		{
		  queue [ ++t ] = v;
		  hash [ v ] = t;
		  step [ t ] = step [ h ] + 1;
		}
	      num [ hash [ v ] ]+=num[ h ];
	    }
	  sw = tmp.m [ i ][ j ] ; tmp.m [ i ][ j ] = tmp.m[ i + 1 ][ j ];tmp.m[ i + 1 ][ j ] =sw;
	}
  }while(h == t);
}

void work()
{	
  int i,j,tmpS,ch;
  Tmaze tmp;
  
  for(i = 0 ; i <= 4 ; ++ i)
    for(j = 0 ; j <= 4 ; ++ j)
      tmp.m[ i ][ j ] = 0;

  Min = 2141483647;

  for (ch = 0 ; ch <= 3 ; ++ch )
    {
      for (i = 1 ;i <= 4 ; ++i )
	{
	  for (j = 1 ;j <= 4 ; ++j) 
	    if (start [ i ][ j ] == ch)
	      tmp.m [ i ][ j ] = 1; 
	    else 
	      tmp.m [ i ][ j ] = 0;
	  tmpS = hash [ code ( tmp ) ];
	  cout<<tmpS<<" "<<code(tmp)<<"\n";
	  for(int ii = 1 ; ii <= 4 ; ++ii)
	    {
	      for(int kk = 1 ; kk <= 4 ;++kk)
		cout<<tmp.m[ ii ][ kk ];
	      cout<<"\n";
	    }
	  if (step [ tmpS ] <= Min)
	    {
	      if (step [ tmpS ] < Min ) S = 0;
	      S += num [ tmpS ];
	      Min = step [ tmpS ];
	    }
	}
    }
}

void out()
{
  cout<<Min<<" "<<S<<"\n";
}

int main()
{
  
  int data ;
  BFS();

  cin>>data;
  while(data > 0)
    {
      init();
      work();
      out();
      --data;
    }
  
  //cin.close();
  //cout.close();
  
  return 0;
}
