#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL h[100005], f[100005];
vector<LL> t[100005];
LL dfs(LL u, LL fa) {
    if (f[u]) {
        return f[u];
    }
    f[u] = 1;

    for (auto v : t[u]) {
        if (v == fa) {
            continue;
        }
        if (h[v] >= h[u]) {
            continue;
        }
        f[u] += dfs(v, u);
    }
    return f[u];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    LL n;
    cin >> n;
    for(LL i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (LL i = 1; i < n; i++) {
        LL u, v;
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    LL ans = 0;
    for (LL i = 1; i <= n; i++) {
        dfs(i, 0);
        ans = max(ans, f[i]);
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