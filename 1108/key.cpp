#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int a[2] = {1, -1};
int main()
{
	int n, i, j, k, l, t = 10000;
	srand((unsigned)time(NULL));
	//freopen("test.in", "w", stdout);
	printf("%d\n", t);
	while(t --)
	{
		n = rand()%18;
		k = n == 0 ? 0 : (rand()%n);
		printf("%d %d\n", n, k);
		while(n --)
		{
			for(i = 0;i < 10000;i ++);
			printf("%d %d\n", rand()%1001 * a[rand()%2], rand()%1001 * a[rand()%2]);
		}
	}
	return 0;
}
