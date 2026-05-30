#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAXN = 300005;
vector<LL> G[MAXN];
LL n, a[MAXN];
LL fa[MAXN][21], dep[MAXN];
LL cnt[MAXN];

void dfs(LL u, LL f) {
    fa[u][0] = f;
    dep[u] = dep[f] + 1;
    for (LL i = 1; i <= 20; ++i)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (LL v : G[u]) {
        if (v != f) dfs(v, u);
    }
}

LL lca(LL u, LL v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (LL i = 20; i >= 0; --i)
        if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
    if (u == v) return u;
    for (LL i = 20; i >= 0; --i)
        if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

void dfs2(LL u, LL f) {
    for (LL v : G[u]) {
        if (v != f) {
            dfs2(v, u);
            cnt[u] += cnt[v];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (LL i = 1; i <= n; ++i) cin >> a[i];
    for (LL i = 1; i < n; ++i) {
        LL x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1, 0);
    for (LL i = 1; i < n; ++i) {
        LL u = a[i], v = a[i + 1];
        LL anc = lca(u, v);
        LL fa_anc = fa[anc][0];
        cnt[u]++;
        cnt[v]++;
        cnt[anc]--;
        cnt[fa_anc]--;
    }
    dfs2(1, 0);
    for (LL i = 1; i <= n; ++i) {
        LL ans = cnt[i];
        if (i != a[1]) {
            ans--;
        }
        cout << ans << '\n';
    }
    return 0;
}