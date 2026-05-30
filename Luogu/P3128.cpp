#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 50005;
vector<LL> g[N];
LL fa[N][19], dep[N], a[N], ans;
void dfs(LL u, LL father) {
    fa[u][0] = father;
    dep[u] = dep[father] + 1;
    for (LL i = 1; i < 19; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (LL v : g[u]) {
        if (v != father) {
            dfs(v, u);
        }
    }
}
void dfs2(LL u, LL father) {
    for (LL v : g[u]) {
        if (v != father) {
            dfs2(v, u);
            a[u] += a[v];
        }
    }
    ans = max(ans, a[u]);
}
LL lca(LL u, LL v) {
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
    for (LL i = 18; i >= 0; i--) {
        if (dep[fa[u][i]] >= dep[v]) {
            u = fa[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (LL i = 18; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n, k;
    cin >> n >> k;
    for (LL i = 1; i < n; i++) {
        LL x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dep[1] = 0;
    dfs(1, 0);
    while (k--) {
        LL s, t;
        cin >> s >> t;
        LL c1 = lca(s, t);
        a[s]++, a[t]++, a[c1]--;
        if (fa[c1][0]) {
            a[fa[c1][0]]--;
        }
    }
    dfs2(1, 0);
    cout << ans;
    return 0;
}
/*
=====================================================================
                              TTHILLTT                              |
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/