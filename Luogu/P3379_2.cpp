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
    LL n, m, s;
    cin >> n >> m >> s;
    for (LL i = 1; i < n; i++) {
        LL x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(s, 0);
    while (m--) {
        LL a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
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