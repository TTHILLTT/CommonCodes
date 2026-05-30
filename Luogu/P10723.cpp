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
LL n, a[100005];
vector<LL> g[100005];
LL cnt[100005];
bool steiner[100005];
LL total_black = 0;
LL ans = 0;

void dfs(LL u, LL p) {
    cnt[u] = a[u];
    LL adj_black = 0;
    for (LL v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        cnt[u] += cnt[v];
        if (cnt[v] > 0) adj_black++;
    }
    if (total_black - cnt[u] > 0) adj_black++;
    if (adj_black >= 2 || a[u] == 1) {
        steiner[u] = true;
        if (a[u] == 0) ans++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    n = read();
    for (LL i = 1; i <= n; i++) {
        a[i] = read();
        total_black += a[i];
    }
    for (LL i = 1; i < n; i++) {
        LL u, v;
        u = read(), v = read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (total_black == 0) {
        cout << 1 << endl;
        return 0;
    }
    if (total_black == 1) {
        cout << 0 << endl;
        return 0;
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/