#include <iostream>
#include<cstdlib>
#include<cstdio>
#include <time.h>
using namespace std;

struct Node
{
	int left;
	int right;
	char state;
};
Node tree[300000];

void createTree(const int &root, const int &l, const int &r)
{
	tree[root].left = l;
	tree[root].right = r;
	tree[root].state = 0;
	if(l == r)	return;
	int mid = l + r >> 1;
	createTree(root<<1, l, mid);
	createTree(root<<1|1, mid+1, r);
}

int add(const int &root, const int &l, const int &r)
{
	if(tree[root].left == l && tree[root].right == r && tree[root].state != 2)
	{
		if(tree[root].state == 0)
		{
			tree[root].state = 1;
			return 0;
		}
		else
			return r-l+1;

	}
	if(tree[root].state == 1)
	{
		tree[root<<1].state = 1;
		tree[root<<1|1].state = 1;	
	}
	else
		tree[root].state = 2;

	int mid = tree[root].left + tree[root].right >> 1;
	int cnt;
	if(r <= mid)
		cnt = add(root<<1, l, r);
	else if(l > mid)
		cnt = add(root<<1|1, l, r);
	else
		cnt = add(root<<1, l, mid) + add(root<<1|1, mid+1, r);
	if(tree[root<<1].state == tree[root<<1|1].state)
		tree[root].state = tree[root<<1].state;
	return cnt;
}

int main()
{
	//----------------------------------------
	time_t start = clock();
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//----------------------------------------
	int N, M;
	int a, b;
	
	while(scanf("%d%d", &N, &M) == 2)
	{
		createTree(1, 1, N);
		for(int i=0; i<M; i++)
		{
			scanf("%d%d", &a, &b);
			printf("%d\n", add(1, a, b));	
		}
		printf("\n");	
	}
	//----------------------------------------
	time_t end = clock();
	//cout << "time: " << end - start << endl;
	//----------------------------------------
	return 0;
}
