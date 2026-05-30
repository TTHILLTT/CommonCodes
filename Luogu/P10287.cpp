#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n, m;
    cin >> n >> m;
    vector<LL> a(n + 1);
    for (LL i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<LL>> G(n + 1);
    vector<LL> in(n + 1, 0);
    for (LL i = 0; i < m; i++) {
        LL u, v;
        cin >> u >> v;
        G[u].push_back(v);
        in[v]++;
    }
    queue<LL> q;
    for (LL i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    vector<LL> topo;
    while (!q.empty()) {
        LL u = q.front(); q.pop();
        topo.push_back(u);
        for (LL v : G[u]) {
            if (--in[v] == 0) {
                q.push(v);
            }
        }
    }
    LL maxA = 10;
    vector<vector<LL>> dp(n + 1, vector<LL>(maxA + 1, 0));
    for (LL i = 1; i <= n; i++) {
        dp[i][a[i]] = 1;
    }
    for (LL u : topo) {
        for (LL k = 1; k <= maxA; k++) {
            if (dp[u][k] == 0) {
                continue;
            }
            for (LL v : G[u]) {
                if (a[v] >= k) {
                    dp[v][a[v]] = max(dp[v][a[v]], dp[u][k] + 1);
                }
            }
        }
    }
    LL ans = 0;
    for (LL i = 1; i <= n; i++) {
        for (LL k = 1; k <= maxA; k++) {
            ans = max(ans, dp[i][k]);
        }
    }
    cout << ans;
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/