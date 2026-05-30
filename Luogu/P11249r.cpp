#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int a[N];
vector<int>e[N];
int f[N];
int maxx;
void dfs(int x, int fa)
{
    f[x] = a[x];
    int maxxx = 0;
    int ans = 0;
    for (int i = 0; i < e[x].size(); i++)
    {
        int v = e[x][i];
        if (v != fa)
        {
            dfs(v, x);
            if (ans < f[v])
            {
                ans = f[v];
                maxxx = v;
            }
            f[x] = max(f[x], f[v] + a[x]);
        }
    }
    int maxxxx = 0;
    int ans1 = 0;
    for (int i = 0; i < e[x].size(); i++)
    {
        int v = e[x][i];
        if (v != fa)
        {
            if (ans1 < f[v] && v != maxxx)
            {
                ans1 = f[v];
                maxxxx = v;
            }
        }
    }
    maxx = max(maxx, max(f[x], ans + ans1 + a[x]));
}
int main()
{
    int _;
    scanf("%d", &_);
    while (_--)
    {
        memset(f, 0, sizeof(f));
        int num = 0;
        int flag = 0;
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            e[i].clear();
            scanf("%d", &a[i]);
            if (a[i])
            {
                num++;
            }
        }
        for (int i = 1; i < n; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        maxx = 0;
        dfs(1, 0);
        printf("%s\n", maxx >= num ? "Yes" : "No");
    }
    return 0;
}

/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/