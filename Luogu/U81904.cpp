#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 500005;
LL n, d, dp[N];
vector<pair<LL, LL>> g[N];
void dfs(LL u, LL fa) {
    LL l = g[u].size();
    for (LL i = 0; i < l; i++) {
        LL v = g[u][i].first;
        if (v == fa) {
            continue;
        }
        dfs(v, u);
        d = max(d, dp[u] + dp[v] + g[u][i].second);
        dp[u] = max(dp[u], dp[v] + g[u][i].second);
    }
}
int main() {
    cin >> n;
    for (LL i = 1; i < n; i++) {
        LL u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    dfs(1, 0);
    cout << d;
    return 0;
}
/*
=====================================================================
                              TTHILLTT                              |
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/