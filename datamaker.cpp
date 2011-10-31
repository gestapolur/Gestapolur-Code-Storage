//Author: dwx_x
//Time: 2010.11.18
//For getting data from topcoder page
//Version 2.2

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#define MaterialFileName "1.txt"
#define MaxFileNameLength 30
#define ProblemName "TopFive"

using namespace std;

//make the file
class MakeFile
{
public:
	void output(string s, string Tfname);
	string makefName(int No, bool is_in)
	{
		stringstream strs;
		strs << No << ( is_in ? ".in" : ".out" );
		return ( ProblemName + strs.str() );
	};
	void work(string s, int No, bool is_in)
	{
		output(s, makefName(No, is_in));
		return;
	};
};
void MakeFile::output(string s, string Tfname)
{
	char Fname[ MaxFileNameLength ];
	int i, L = Tfname.size();
	for( i = 0; i != L; ++ i )
		Fname[ i ] = Tfname[ i ];
	Fname[ L ] = '\0';
	ofstream f(Fname);
	for( i = 0; i < s.size(); ++ i )
	{
		if( s[ i ] == '~' )
			f << endl;
		else
			f << s[ i ];
	}
	return;
}

//modify a content
class Modify
{
public:
	string Ts;
	int Length_of_Ts;
	string work(string Ts);
	string MakeString(int start, int end, int type);
	int FindType(int p);
	int FindEnd(int p);
	bool is_figure(int p)
	{
		return ( ( Ts[ p ] >= '0' && Ts[ p ] <= '9' ) || Ts[ p ] == '.' );
	}
	//find "ch" in "s" from "st" to end
};
int Modify::FindEnd(int p)
{
	int Tch = ( Ts[ p ] == '{' ) ? '}' : Ts[ p ];
	if( Tch == '\'' || Tch == '\"' || Tch == '}' )
		for( int i = p + 1; i < Length_of_Ts; ++ i )
			if( Ts[ i ] == Tch )
				return i;
	if( Tch >= '0' && Tch <= '9' || Tch == '-' || Tch == '.' )
	{
		for( int i = p + 1; i < Length_of_Ts; ++ i )
			if( !is_figure(i) )
				return i - 1;
		return Length_of_Ts - 1;
	}
	return 0;
}
//1 for ( int | double ), 2 for char, 3 for string
//4 for vector <( int | double )>, 5 for vector <char>, 6 for vector <string>
int Modify::FindType(int p)
{
	if( is_figure( p ) || Ts[ p ] == '-' )
		return 1;
	if( Ts[ p ] == '\'' )
		return 2;
	if( Ts[ p ] == '\"' )
		return 3;
	if( Ts[ p ] == '{' )
	{
		if( is_figure(p + 1) || Ts[ p + 1 ] == '-' )
			return 4;
		if( Ts[ p + 1 ] == '\'' )
			return 5;
		if( Ts[ p + 1 ] == '\"' )
			return 6;
	}
	return 0;
}
string Modify::MakeString(int start, int end, int type)
{
	string part;
	int i, L, R;
	switch( type )
	{
	case 1:
		for( i = start; i <= end; ++ i )
			part += Ts[ i ];
		break;
	case 2:
		part += Ts[ start + 1 ];
		break;
	case 3:
		for( i = start + 1; i != end; ++ i )
			part += Ts[ i ];
		break;
	case 4:
		for( i = start + 1; i != end; ++ i )
			if( Ts[ i ] != ',' )
				part += Ts[ i ];
		break;
	case 5:
		for( i = start + 1; i != end; ++ i )
			if( Ts[ i ] != ',' && Ts[ i ] != '\'' )
				part += Ts[ i ];
		break;
	case 6:
		L = start + 1;
		while( L < end )
		{
			R = FindEnd( L );
			for( i = L + 1; i != R; ++ i )
				part += Ts[ i ];
			part += '~';
			L = R + 3;
		}
		break;
	default:
		break;
	}
	return part;
}
string Modify::work(string Xs)
{
	Ts = Xs, Length_of_Ts = Xs.size();
	string S;
	for( int start = 0; start < Length_of_Ts; )
    {
		int end = FindEnd(start);
		S += MakeString(start, end, FindType(start)) + "~";
		start = end + 3;//skip the "}, {" (except the "\"")
    }
	return S;
}

class Init
{
public:
	vector <string> work(string Line);
};
vector <string> Init::work(string Line)
{
    int L = Line.size(), start = 0, end;
	vector <string> semiFs;
    if( L > 0 )
	{
		string temp;
		while( Line[ start ] == ' ' )
			++ start;
		for( end = start; end != L; ++ end )
			if( Line[ end ] == ' ' && Line[ end + 1 ] == ' ' )
			{
				for( int i = start; i < end; ++ i )
					temp += Line[ i ];
				break;
			}
		semiFs.push_back(temp);
		temp = "";
		start = end + 2;
		for( end = start; end < L; ++ end )
			if( Line[ end ] == ' ' && Line[ end + 1 ] == ' ' )
			{
				for( int i = start; i < end; ++ i )
					temp += Line[ i ];
				break;
			}
		semiFs.push_back(temp);
	}
	return semiFs;
}

int main()
{
	ifstream f(MaterialFileName);
    
	if( f )
	{
		int No = 0;
		string line;
		while( getline(f, line) )
			if( line.size() > 8 )//check is it a useful line
			{
				Init x;
				vector <string> semiFs = x.work(line);
				Modify y;
				string forin = y.work(semiFs[ 0 ]);
				string forout = y.work(semiFs[ 1 ]);
				MakeFile z;
				z.work(forin, No, true);
				z.work(forout, No, false);
				++ No;
			}
	}
	f.close();
	return 0;
}
