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
const LL N = 1e5+10, inf = 1e9+10;
LL n, to[2 * N], nxt[2 * N], ver[N], c[N], idx, ans, dp[N][2];
void add(LL x, LL y) {
    to[++idx] = y, nxt[idx] = ver[x], ver[x] = idx;
}
void dfs(LL x, LL fa) {
    dp[x][0] = dp[x][1] = -inf;
    dp[x][c[x]] = 0;
    for (LL i = ver[x]; i; i = nxt[i]) {
        if (to[i] == fa)continue;
        LL y = to[i]; dfs(y, x);
        ans = max(ans, max(dp[x][1] + dp[y][0], dp[x][0] + dp[y][1]) + 1);
        dp[x][0] = max(dp[x][0], dp[y][0] + 1);
        dp[x][1] = max(dp[x][1], dp[y][1] + 1);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);scanf("%d",&n);
    scanf("%lld", &n);
    for (LL i = 1; i <= n; i++) {
        scanf("%lld", c + i);
    }
    for (LL i = 1, u, v; i < n; i++) {
        scanf("%lld %lld", &u, &v);
        add(u, v), add(v, u);
    }
    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}
/*
===============================================================================
                              TTHILLTT.github.io                              |
                              Visual Studio Code                              |
===============================================================================
*/