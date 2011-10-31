/*
A very simple stack
很傻X的栈演示程序
注意元素的存储从0开始
write by gestapolur
2010-8-28
*/
#include<iostream>
#define MAX_STACK_SIZE 1000/*栈能容纳的最多元素个数*/
using namespace std;

int stack[MAX_STACK_SIZE];
int top = -1;/*初始化栈顶指针*/

/*栈顶元素出栈*/
void pop()
{
  if(top >= 0)/*至少栈不为空*/
    stack[top--] = 0;
  return ;
}

/*元素入栈*/
void push(int add_data)
{
  stack[++top] = add_data;
  return ;
}

/*显示栈中元素*/
void display()
{
  for(int tmp = top ; tmp >= 0 ; -- tmp)
    cout<<stack[tmp]<<" ";
  cout<<"\n";
  return ;
}

/*main()里面演示一下栈的功能*/
int main()
{
  int ins,data;
  while(cin>>ins)
  switch(ins)
    {
    case 1 :
      cout<<"please insert a value :";
      cin>>data;
      push(data);
      break;
    case 2 :
      cout<<"a value poped\n";
      pop();
      break;
    case 3 :
      cout<<"what in the stack :";
      display();
      break;
    default :
      return 0;
    }
  return 0;
}
