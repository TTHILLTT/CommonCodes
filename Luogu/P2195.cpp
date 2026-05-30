#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLLLL;
LL n, m, q, f[300005], a[300005], dp[300005], d;
vector<LL> e[300005];
LL find(LL x) {
    if (x == f[x]) {
        return x;
    }
    return f[x] = find(f[x]);
}
void unite(LL x, LL y) {
    LL fx = find(x), fy = find(y);
    if (fx == fy){
        return;
    }
    f[fx] = fy;
    a[find(fx)] = max({(a[fx] + 1) / 2 + (a[fy] + 1) / 2 + 1, a[fx], a[fy]});
}
void dfs(LL x, LL f) {
    for (auto y : e[x]) {
        if (y == f){
            continue;
        }
        dfs(y, x);
        d = max(d, dp[x] + dp[y] + 1);
        dp[x] = max(dp[x], dp[y] + 1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    cin >> n >> m >> q;
    for (LL i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (LL i = 1; i <= m; i++) {
        LL x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
        f[find(x)] = find(y);
    }
    for (LL i = 1; i <= n; i++) {
        if (f[i] == i) {
            dfs(i, 0);
            a[i] = d;
            d = 0;
        }
    }
    while (q--) {
        LL o;
        cin >> o;
        if (o == 1) {
            LL x;
            cin >> x;
            cout << a[find(x)] << endl;
        }
        else {
            LL x, y;
            cin >> x >> y;
            unite(x, y);
        }
    }
    return 0;
}
/*
=====================================================================
                              TTHILLTT                              |
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/