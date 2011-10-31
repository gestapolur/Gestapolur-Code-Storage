/*
  A very simple circle queue example programm
  很简单的队列演示程序，只演示基本的队列操作
  write by gestapolur
  2010-8-29
*/
#include <fstream>
#define MAX_QUEUE_SIZE 100000 /*队列的最多元素个数*/
using namespace std;

ifstream cin("input.txt");
ofstream cout("output_1.txt");

int queue[MAX_QUEUE_SIZE];
int front = 0;  //队头指针 
int rear = MAX_QUEUE_SIZE - 1 ;   //队尾指针
 
/*在数组没有被加满的情况下将一个元素加入队列*/
void queue_add(int add_data)
{
  int tmp;
  tmp = (rear + 1) % MAX_QUEUE_SIZE;/*计算rear + 1后的位置*/
  
  if(tmp != front || queue[front] == -1)
    /*
      如果tmp == front 就是数组满了(rear 绕了一圈 ),
      检查front的下标是否为空是为了保证在队列为空时元素被加入
    */
    {
      rear = tmp;
      queue[rear] = add_data;
    }    
  return ;       
}

/*在队列不为空的情况下取出队头元素*/
void queue_del()
{
  if(queue[front] != -1)/*判断队列是否为空*/
    {
      queue[front] = -1;/*这里直接删除了队头元素*/
      front = ( front + 1 ) % MAX_QUEUE_SIZE;/*队头向后移动*/
    }
  return ;           
}

/*显示队列里所有的元素*/
void display()
{
  int tmp,edg;

  tmp = front;
  edg = (rear + 1) % MAX_QUEUE_SIZE;
  while(queue[tmp] != -1)/*队列不为空时输出所有队列中的元素*/
    {
      cout<<queue[tmp]<<" ";
      tmp = (tmp + 1) % MAX_QUEUE_SIZE;
    }
  cout<<"\n";
  return ;
}

/*初始化队列，设定空值为-1*/
void init()
{
  for(int i = 0 ;i < MAX_QUEUE_SIZE ; ++ i)
    queue[i] = -1;
  return ;
}

int main()
{
  int select,temp;

  init();

  while(cin>>select)
    switch(select)
      {
      case 1:
	cin>>temp;
	queue_add(temp);
	break;
      case 2:
	queue_del();
	break;
      default:
	return 0;
      }       

  display();

  cin.close();
  cout.close();

  return 0; 

}             
