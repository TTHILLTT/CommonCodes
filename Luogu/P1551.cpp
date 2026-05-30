#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<vector<LL>> g(5005);
bool dfs(LL u, LL tgt, vector<bool>& vis) {
    if (u == tgt) {
        return true;
    }
    vis[u] = true;
    for (LL v : g[u]) {
        if (!vis[v] && dfs(v, tgt, vis)) {
            return true;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n, m, p;
    cin >> n >> m >> p;
    for (LL i = 0; i < m; i++) {
        LL a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (LL i = 0; i < p; i++) {
        LL a, b;
        cin >> a >> b;
        vector<bool> vis(n + 5, false);
        if (dfs(a, b, vis)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}
/*
===========================================================================
                        Programed by TTHILLTT                            /
                         TTHILLTT.github.io                             /
========================================================================
*/