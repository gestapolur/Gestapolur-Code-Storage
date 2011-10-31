/*
 * Author: momodi
 * Created Time:  2009/9/6 0:05:51
 * File Name: WHUgirls.cpp
 * Description: 
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define out(x) fprintf(stderr, "%s: %I64d\n", #x, (long long)(x))
#define SZ(v) ((int)(v).size())
const int maxint=-1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
const int maxn = 1010;
int x[maxn], y[maxn], c[maxn];
int f[maxn][maxn];
int n, X, Y;

int main() {
    int ca;
    scanf("%d", &ca);
    while (ca--) {
        scanf("%d %d %d", &n, &X, &Y);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d", x + i, y + i, c + i);
        }
        for (int i = 0; i <= X; ++i) {
            for (int j = 0; j <= Y; ++j) {
                int &ans = f[i][j];
                ans = 0;
                for (int k = 0; k < n; ++k) {
                    if (x[k] <= i && y[k] <= j) {
                        get_max(ans, c[k] + f[i - x[k]][j] + f[x[k]][j - y[k]]);
                        get_max(ans, c[k] + f[i][j - y[k]] + f[i - x[k]][y[k]]);
                    }
                    swap(x[k], y[k]);
                    if (x[k] <= i && y[k] <= j) {
                        get_max(ans, c[k] + f[i - x[k]][j] + f[x[k]][j - y[k]]);
                        get_max(ans, c[k] + f[i][j - y[k]] + f[i - x[k]][y[k]]);
                    }
                }
            }
        }
        printf("%d\n", f[X][Y]);
    }
    return 0;
}

