#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
vector<vector<LL>> g;
LL n, dp[100005];
void dfs(LL u) {
    vector<LL> h;
    for (LL v : g[u]) {
        dfs(v);
        h.push_back(dp[v]);
    }
    sort(h.rbegin(), h.rend());
    dp[u] = 0;
    for (LL i = 0; i < h.size(); i++) {
        dp[u] = max(dp[u], (LL)(h[i] + h.size()));
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    // cout << 111;
    cin >> n;
    g.resize(n + 1);
    for (LL i = 2; i <= n; i++) {
        LL x;
        cin >> x;
        g[x].push_back(i);
    }
    dfs(1);
    cout << dp[1];
    return 0;
}
/*
=====================================================================
                              TTHILLTT                              |
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/