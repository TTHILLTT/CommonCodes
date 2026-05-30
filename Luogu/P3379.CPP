#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAXN = 500005;
const LL LOGN = 21;
vector<LL> tree[MAXN];
LL fa[MAXN][LOGN], depth[MAXN];
void dfs(LL u, LL father) {
    fa[u][0] = father;
    depth[u] = depth[father] + 1;
    for (LL i = 1; i < LOGN; ++i)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (LL v : tree[u]) {
        if (v != father)
            dfs(v, u);
    }
}
LL lca(LL u, LL v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (LL i = LOGN - 1; i >= 0; --i)
        if (depth[fa[u][i]] >= depth[v])
            u = fa[u][i];
    if (u == v) return u;
    for (LL i = LOGN - 1; i >= 0; --i)
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    return fa[u][0];
}
int main() {
    LL n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    for (LL i = 1; i < n; ++i) {
        LL x, y;
        scanf("%d%d", &x, &y);
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(s, 0);
    while (m--) {
        LL a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}