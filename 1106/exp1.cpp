//5
#include<iostream>
#include<string>
#define MAXN 1000//最多容纳的学生数目
#define MAXM 1000//最多容纳的课程数目
using namespace std;

class student
{
public:
  string name;
  int id;
  int totc;
  string cl[ MAXM ];
  int score[ MAXM ];
};

student stu[ MAXN ];
int stot;//学生总数

void count( )
{
  int val[ 6 ];//各个分数段的人数
  int i , j ;
  for( i = 1 ; i <= stot ; ++ i )
    for( j = 1 ; j <= stu[ i ].totc ; ++ j )
      if( stu[ i ].score[ j ] > 89 )
	++val[ 1 ];
      else if( stu[ i ].score[ j ] > 79)
	++val[ 2 ];
      else if( stu[ i ].score[ j ] > 69)
	++val[ 3 ];
      else if( stu[ i ].score[ j ] > 59)
	++val[ 4 ];
      else
	++val[ 5 ];

      
  cout<<"优秀 "<<val[ 1 ]<<"人,占总人数的 "<<double(val[ 1 ])/double(stot);
  cout<<"良好"<<val[ 2 ]<<"人,占总人数的 "<<double(val[ 2 ])/double(stot);
  cout<<"中等"<<val[ 3 ]<<"人,占总人数的 "<<double(val[ 3 ])/double(stot);
  cout<<"及格"<<val[ 4 ]<<"人,占总人数的 "<<double(val[ 4 ])/double(stot);
  cout<<"不及格"<<val[ 5 ]<<"人,占总人数的 "<<double(val[ 5 ])/double(stot);
  return ;
}

int main()
{
  int n , i , j , k , ins = 1 , stid , id;
  string m,name;

  while( ins ){
    cout<<" 1.输入数据\n 2.显示所有输入数据\n 3.查询学生成绩\n 4.统计成绩分布\n 其他:退出 \n";
    cin>>ins;
    if( ins == 1 )//输入某门课的学生数据
      {
	cout<<"输入课程名称m和该课程n个学生的成绩: \n";
	cin>>m>>n;
	for( i = 1 ; i <= n ; ++ i )
	  {
	    cout<<"输入学生ID和学生名字\n";
	    cin>>stid>>name;//学生id,名字
	    for( i = 1 ; i <= stot ; ++ i )//在所有学生中查找该学生并添加该门课的成绩
	      if( stid == stu[ i ].id )
		{
		  ++stu[ i ].totc;
		  cin>>stu[ i ].score[ stu[ i ].totc ];//输入成绩
		  stu[ i ].cl[ stu[ i ].totc ] = m;
		  break;
		}
	    if( i == stot + 1 )//如果没有这个学生，则增加该学生
	      {
		++stot;
		stu[ stot ].name = name;
		++stu[ stot ].totc;
		cin>>stu[ stot ].score[ stu[ stot ].totc ];
		stu[ stot ].cl[ stu[ stot ].totc ] = m ;
	      }
	  }
      }
    else if( ins == 2 )//显示所有输入数据
      {
	for( i = 1 ; i <= stot ; ++ i )
	  {
	    cout<<stu[ i ].name<<" "<<stu[ i ].id<<"\n";
	    for( j = 1 ; j <= stu[ i ].totc ; ++ j )
	      cout<<stu[ i ].cl[ j ]<<" "<<stu[ i ].score[ j ]<<"\n";
	  }
	    
      }
    else if( ins == 3 )//search
      {
	cout<<"输入 1 + 学生ID 或 2 + 学生名字 查找学生\n";
	cin>>ins;
	if( ins == 1 )
	  {
	    cin>>id;
	    for( i = 1 ; i <= stot ; ++ i )
	      if( stu[ i ].id == id )
		{
		  cout<<stu[ i ].name<<" "<<stu[ i ].id<<"\n";
		  for( j = 1 ; j <= stu[ i ].totc ; ++ j )
		    cout<<stu[ i ].cl[ j ]<<" "<<stu[ i ].score[ j ]<<"\n";
		  break;
		}
	    if( i == stot + 1 ) cout<<"没有找到\n";
	  }
	else
	  {
	    cin>>name;
	    for( i = 1 ; i <= stot ; ++ i )
	      if( stu[ i ].name == name )
		{
		  cout<<stu[ i ].name<<" "<<stu[ i ].id<<"\n";
		  for( j = 1 ; j <= stu[ i ].totc ; ++ j )
		    cout<<stu[ i ].cl[ j ]<<" "<<stu[ i ].score[ j ]<<"\n";
		  break;
		}
	    if( i == stot + 1 ) cout<<"没有找到\n";
	  }
      }
    else if( ins == 4 )//统计成绩分布
	count();
    else break;
  }
  
  return 0;
}
