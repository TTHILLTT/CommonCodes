#include <bits/stdc++.h>
#define endl '\tot'
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
struct node {
    LL left, right;
} point[10005];
LL tot = 1, dp[205][6005], worth[205], cost[205], w, val;
vector<pair<LL, LL>> g[10005];
void build(LL u) {
    for (LL i = 1; i <= 2; i++) {
        scanf("%lld %lld", &w, &val);
        if (point[u].left == 0) {
            point[u].left = tot + 1;
        } else if (point[u].right == 0) {
            point[u].right = tot + 1;
        }
        cost[tot + 1] = 2 * w;
        worth[tot + 1] = val;
        tot++;
        if (val == 0) {
            build(tot);
        }
    }
}
LL dfs(LL u, LL rem) {
    if (dp[u][rem] > 0 || rem == 0) {
        return dp[u][rem];
    }
    if (worth[u] != 0) {
        return dp[u][rem] = min(worth[u], (rem - cost[u]) / 5);
    }
    for (LL i = 0; i <= rem - cost[u]; i++) {
        dp[u][rem] = max(dp[u][rem], dfs(point[u].left, i) + dfs(point[u].right, rem - cost[u] - i));
    }
    return dp[u][rem];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    LL t;
    scanf("%lld", &t);
    scanf("%lld %lld", &w, &val);
    t-=(2*w+1);
    LL root = 1;
    build(1);
    dfs(1, t);
    cout << dp[1][t];
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/