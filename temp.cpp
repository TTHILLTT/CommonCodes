#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
inline LL read() {
    LL s = 0, w = 1;
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
const int N = 1000005, LOGN = 21;
LL n, a, u[100005], v[100005], bu, bv;
vector<int> g[N];
int dep[N], fa[N][LOGN];
int cover[N];
bool on_bad_path[N];

void dfs(int u, int f) {
    fa[u][0] = f;
    dep[u] = dep[f] + 1;
    for (int i = 1; i < LOGN; ++i) {
        fa[u][i] = fa[fa[u][i-1]][i-1];
    }
    for (int v : g[u]) {
        if (v == f) continue;
        dfs(v, u);
    }
}

int LCA(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = LOGN-1; k >= 0; --k) {
        if (dep[fa[u][k]] >= dep[v]) u = fa[u][k];
    }
    if (u == v) return u;
    for (int k = LOGN-1; k >= 0; --k) {
        if (fa[u][k] != fa[v][k]) {
            u = fa[u][k]; v = fa[v][k];
        }
    }
    return fa[u][0];
}

void add_path(int u, int v) {
    int l = LCA(u, v);
    cover[u]++;
    cover[v]++;
    cover[l] -= 2;
}

void dfs_cover(int u, int f) {
    for (int v : g[u]) {
        if (v == f) continue;
        dfs_cover(v, u);
        cover[u] += cover[v];
    }
}

void mark_bad_path(int u, int v) {
    int l = LCA(u, v);
    auto mark = [&](int x, int stop) {
        while (x != stop) {
            on_bad_path[x] = true;
            x = fa[x][0];
        }
    };
    mark(u, l);
    mark(v, l);
    on_bad_path[l] = true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> a;
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 1; i <= a; ++i) {
        cin >> u[i] >> v[i];
        add_path(u[i], v[i]);
    }
    dfs_cover(1, 0);
    cin >> bu >> bv;
    mark_bad_path(bu, bv);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == bu || i == bv) continue;
        if (cover[i] == 0 && on_bad_path[i]) ++ans;
    }
    cout << ans << '\n';
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/