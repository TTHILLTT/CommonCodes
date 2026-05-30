#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define pii pair<LL,LL>
#define arr array<LL, 3>
LL n, m, fa[10005][20], f[10005], d[10005], w[10005][20], ans;
bool st[10005];
vector<pii> e[10005];
vector<arr> g;
LL find(LL x)
{
    if(f[x] == x)
        return x;
    return f[x] = find(f[x]);
}
bool cmp(arr a, arr b) {
    return a[2] > b[2];
}
void kkk() {
    for (LL i = 1;i <= n;i++) {
        f[i] = i;
    }
    sort(g.begin(), g.end(), cmp);
    for (LL i = 0; i < g.size(); i++) {
        LL fx = find(g[i][0]), fy = find(g[i][1]);
        if (fx != fy) {
            f[fy] = fx;
            e[g[i][0]].push_back({g[i][1], g[i][2]});
            e[g[i][1]].push_back({g[i][0], g[i][2]});
        }
    }
}
void dfs(LL x, LL father, LL o) {
    st[x] = 1;
    d[x] = d[father] + 1;
    w[x][0] = o;
    fa[x][0] = father;
    for (LL i = 1;i <= 19;i++) {
        w[x][i] = min(w[x][i - 1], w[fa[x][i - 1]][i - 1]);
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    }
    for (auto y : e[x]) {
        LL v = y.first;
        if (v != father)
            dfs(v, x, y.second);
    }
}
LL lca(LL x, LL y) {
    if (find(x) != find(y))
        return -1;
    LL ans = LLONG_MAX;
    if (d[x] < d[y])
        swap(x, y);
    for (LL i = 19;i >= 0;i--)
        if (d[fa[x][i]] >= d[y]) {
            ans = min(ans, w[x][i]);
            x = fa[x][i];
        }
    if (x == y)
        return ans;
    for (LL i = 19;i >= 0;i--)
        if (fa[x][i] != fa[y][i]) {
            ans = min({ans, w[x][i], w[y][i]});
            x = fa[x][i], y = fa[y][i];
        }
    return ans = min({ans, w[x][0], w[y][0]});
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(w, 0x3f, sizeof w);
    cin >> n >> m;
    for(LL i = 1;i <= m;i++)
    {
        LL x, y, z;
        cin >> x >> y >> z;
        g.push_back({x, y, z});
        g.push_back({y, x, z});
    }
    kkk();
    for (LL i = 1;i <= n;i++) {
        if (!st[i]) {
            dfs(i, 0, LLONG_MAX);
        }
    }
    LL q;
    cin >> q;
    while (q--) {
        LL x, y;
        cin >> x >> y;
        LL l = lca(x, y);
        cout << l << endl;
    }
    return 0;
}
/*
=====================================================================
                              TTHILLTT                              |
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/