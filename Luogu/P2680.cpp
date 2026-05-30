#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, cnt, s[300005], d[300005], f[300005][20], maxn = 0, ans;
struct edge
{
    int v, w;
};
vector<edge> e[300005];
struct node
{
    int x, y, l, s;
};
inline int read() {
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
//      if(ch=='-')w=-1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        s = s * 10 + ch - '0', ch = getchar();
    }
    return s * w;
}
vector<node> v;
void dfs(int x, int fa) {
    d[x] = d[fa] + 1;
    f[x][0] = fa;
    for (int i = 1;i <= 19;i++)
        f[x][i] = f[f[x][i - 1]][i - 1];
    for (auto res : e[x])
    {
        int y = res.v, w = res.w;
        if (y != fa)
        {
            s[y] = s[x] + w;
            dfs(y, x);
        }
    }
}
void kkk(int x, int fa, int num)
{
    for(auto res : e[x])
    {
        int y = res.v, w = res.w;
        if(y != fa)
        {
            kkk(y, x, num);
            s[x] += s[y];
            if(s[y] == num)
                maxn = max(maxn, w);
        }
    }
}
int lca(int x, int y) {
    if (d[x] < d[y])
        swap(x, y);
    for (int i = 19;i >= 0;i--)
        if (d[f[x][i]] >= d[y])
            x = f[x][i];
    if (x == y)
        return x;
    for (int i = 19;i >= 0;i--)
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    return f[x][0];
}
bool check(int x)
{
    memset(s, 0, sizeof(s));
    maxn = 0;
    int num = 0, maxt = 0;
    for (int i = 0; i < m; i++) {
        if (v[i].s > x) {
            num++;
            s[v[i].x]++, s[v[i].y]++;
            s[v[i].l] -= 2;
        }
        maxt = max(maxt, v[i].s);
    }
    if (num == 0)
        return true;
    kkk(1, 0, num);
    return (maxt - maxn <= x);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    n=read();
    m=read();

    for(int i = 1;i < n;i++)
    {
        int u, v, w;
        u=read();
        v=read();
        w=read();
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs(1, 0);
    
    int l = 0, r = 0;
    for(int i = 0;i < m;i++)
    {
        int a, b;
        a=read();
        b=read();
        int l = lca(a, b);
        v.push_back({a, b, l, s[a] + s[b] - 2 * s[l]});
        r = max(r, s[a] + s[b] - 2 * s[l]);
    }
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(check(mid))
        {
        	ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans;
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/