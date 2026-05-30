#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const LL N = 300005, mod = 998244353;
vector<LL> g[N];
LL fa[N][20], dep[N], a[55][N];
LL qpow(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void dfs(LL u, LL father) {
    fa[u][0] = father;
    dep[u] = dep[father] + 1;
    for (LL k = 1; k <= 50; k++) {
        a[k][u] = (a[k][father] + qpow(dep[u], k) + mod) % mod;
    }
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
    if (dep[u] < dep[v]) {
        swap(u, v);
    }
    for (LL i = 19; i >= 0; i--) {
        if (dep[fa[u][i]] >= dep[v]) {
            u = fa[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (LL i = 19; i >= 0; i--) {
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
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    LL n, m;
    cin >> n;
    for (LL i = 1; i < n; i++) {
        LL x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dep[0] = -1;
    dfs(1, 0);
    cin >> m;
    while (m--) {
        LL i, j, k;
        cin >> i >> j >> k;
        LL c1 = lca(i, j);
        LL ans = ((a[k][i] + a[k][j] + mod) % mod - (a[k][c1] + a[k][fa[c1][0]] + mod) % mod + mod) % mod;
        cout << ans << endl;
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