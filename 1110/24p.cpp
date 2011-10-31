#include<stdio.h>
#include<string.h>
#include<math.h>
int a[10], A[10], b[10];
int dfs(int cur, double ans)
{
    int i;
    double temp;
    if(cur == 4)
    {
        if(fabs(ans - 24) < 1e-9)
            return 1;
        return 0;
    }
    for(i = 0; i < 4; i ++)
    {
        if(cur == 0)
        {
            if(i)
                break;
            temp = b[cur];
        }
        else
        {
            if(i == 0)
                temp = ans + b[cur];
            else if(i == 1)
                temp = ans - b[cur];
            else if(i == 2)
                temp = ans * b[cur];
            else
                temp = ans / b[cur];
        }
        if(dfs(cur + 1, temp))
            return 1;
    }
    return 0;
}
int judge(int cur)
{
    int i;
    if(cur == 4)
    {
        if(dfs(0, 0.0))
            return 1;
        return 0;

    }
    for(i = 0; i < 4; i ++)
        if(!A[i])
        {
            A[i] = 1;
            b[cur] = a[i];
            if(judge(cur + 1))
                return 1;
            A[i] = 0;
        }
    return 0;
}
void solve()
{
    for(a[0] = 1; a[0] <= 13; a[0] ++)
        for(a[1] = a[0]; a[1] <= 13; a[1] ++)
            for(a[2] = a[1]; a[2] <= 13; a[2] ++)
                for(a[3] = a[2]; a[3] <= 13; a[3] ++)
                {
                    memset(A, 0, sizeof(A));
                    if(!judge(0))
                        printf("%d %d %d %d\n", a[0], a[1], a[2], a[3]);
                }
}
int main()
{
    solve();
    getchar();
    return 0;
}
