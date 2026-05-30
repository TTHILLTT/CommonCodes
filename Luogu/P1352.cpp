#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 6e3 + 5;
vector<LL> g[N];
LL n, ans = -0x3f3f3f3f3f3f3f3f, a[N], dp[N][2];
bool st[N];
void dfs(LL u) {
    dp[u][0] = 0;
    dp[u][1] = a[u];
    for (LL i = 0; i < g[u].size(); i++) {
        LL v = g[u][i];
        dfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}
int main() {
    cin >> n;
    for (LL i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (LL i = 1; i < n; i++) {
        LL u, v;
        cin >> u >> v;
        g[v].push_back(u);
        st[u] = 1;
    }
    LL root = 1;
    for (LL i = 1; i <= n; i++) {
        if (!st[i]) {
            root = i;
        }
    }
    dfs(root);
    for (LL i = 1; i <= n; i++) {
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans;
    return 0;
}
/*
=====================================================================
                              TTHILLTT                              |
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/