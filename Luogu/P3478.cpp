#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 1000005;
vector<LL> g[N];
LL sum[N], dp[N], n;
void dfs1(LL u, LL fa, LL dep) {
    sum[u] = 1;
    dp[1] += dep;
    for (LL v : g[u]) {
        if (v == fa) {
            continue;
        }
        dfs1(v, u, dep + 1);
        sum[u] += sum[v];
    }
}
void dfs2(LL u, LL fa) {
    for (LL v : g[u]) {
        if (v == fa) {
            continue;
        }
        dp[v] = dp[u] + n - 2 * sum[v];
        dfs2(v, u);
    }
}
int main() {
    scanf("%lld", &n);
    for (LL i = 1; i < n; i++) {
        LL u, v;
        scanf("%lld %lld", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0, 0);
    dfs2(1, 0);
    LL ans = 1;
    for (LL i = 2; i <= n; i++) {
        if (dp[i] > dp[ans]) {
            ans = i;
        }
    }
    printf("%lld", ans);
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/