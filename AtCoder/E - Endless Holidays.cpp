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
void dfs(LL day, LL w, LL n, vector<LL> &path, vector<vector<LL>> &g, vector<string> &s, bool& ok) {
    if (ok) {
        return;
    }
    if (day == w) {
        ok = true;
        return;
    }
    LL u = path[day - 1];
    for (LL v = 0; v < n; v++) {
        if (s[v][day] != 'o') {
            continue;
        }
        if (v == u || g[u][v]) {
            path[day] = v;
            dfs(day + 1, w, n, path, g, s, ok);
        }
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("E - Endless Holidays - counterexample.in","r",stdin);
    // freopen(".out","w",stdout);
    LL T;
    cin >> T;
    while (T--) {
        LL n, m;
        cin >> n >> m;
        vector<vector<LL>> g(n, vector<LL>(n, 0));
        for (LL i = 0; i < m; i++) {
            LL u, v;
            cin >> u >> v;
            u--, v--;
            g[u][v] = g[v][u] = 1;
        }
        LL w;
        cin >> w;
        vector<string> s(n);
        for (LL i = 0; i < n; i++) {
            cin >> s[i];
        }
        bool ok = false;
        for (LL start = 0; start < n; start++) {
            if (s[start][0] != 'o') continue;
            vector<LL> path(w);
            path[0] = start;
            dfs(1, w, n, path, g, s, ok);
            if (ok) {
                break;
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/