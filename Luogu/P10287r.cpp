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
LL a[100005], in[100005], dp[100005][15];
vector<LL> g[100005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    LL n, m;
    n = read(), m = read();
    for (LL i = 1; i <= n; i++) {
        a[i] = read();
    }
    for (LL i = 1; i <= m; i++) {
        LL u, v;
        u = read(), v = read();
        g[u].push_back(v);
        in[v]++;
    }
    queue<LL> q;
    for (LL i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
        dp[i][a[i]] = 1;
    }
    while (!q.empty()) {
        LL u = q.front();
        q.pop();
        for (LL v : g[u]) {
            for (LL x = 1; x <= 10; x++) {
                dp[v][x] = max(dp[v][x], dp[u][x]);
            }
            for (LL x = 1; x <= a[v]; x++) {
                dp[v][a[v]] = max(dp[v][a[v]], dp[u][x] + 1);
            }
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
    LL ans = 0;
    for (LL i = 1; i <= n; i++) {
        for (LL j = 1; j <= 10; j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/