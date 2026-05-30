#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
bool vis[505][25];
LL n, m, k;
vector<LL> g[505];
void dfs(LL u, LL stp) {
    if (vis[u][stp] == 1) {
        return;
    }
    vis[u][stp] = 1;
    if (stp == k) {
        return;
    }
    stp++;
    for (LL i = 0; i < g[u].size(); i++) {
        dfs(g[u][i], stp);
    }
}
int main() {
    cin >> n >> m >> k;
    for (LL j = 0; j < m; j++) {
        LL u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (LL i = 1; i <= n; i++) {
        for (LL j = 1; j <= n; j++) {
            for (LL k2 = 0; k2 <= k; k2++) {
                vis[j][k2] = 0;
            }
        }
        dfs(i, 0);
        for (LL j = 1; j <= k; j++) {
            LL ans = 0;
            for (LL k2 = 1; k2 <= n; k2++) {
                ans += vis[k2][j];
            }
            cout << ans << " ";
        }
        cout << endl;
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