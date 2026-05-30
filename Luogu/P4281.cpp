#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 500005;
vector<LL> g[N];
LL fa[N][19], dep[N];
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
LL lca(LL u, LL v) {
    if (dep[u] < dep[v]) swap(u, v);
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
    LL n, m;
    cin >> n >> m;
    for (LL i = 1; i < n; i++) {
        LL x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    while (m--) {
        LL u, v, w;
        cin >> u >> v >> w;
        LL uv, vw, uw;
        uv = lca(u, v);
        vw = lca(v, w);
        uw = lca(u, w);
        LL c1 = uv, c2 = vw;
        LL x1 = u, x2 = v, x3 = w;
        if (dep[uw] > dep[c1]) {
            c1 = uw, c2 = uv;
            x1 = v, x2 = w, x3 = u;
        }
        if (dep[vw] > dep[c1]) {
            c1 = vw, c2 = uv;
            x1 = u, x2 = w, x3 = v;
        }
        cout << c1 << " " << dep[x1] + dep[x2] + dep[x3] - dep[c1] - dep[c2] * 2<< endl;
    }
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/