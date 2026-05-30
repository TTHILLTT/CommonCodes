#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, m;
vector<LL> g[100005];
bool vis[100005];
void dfs(LL now) {
    if (vis[now]) {
        return;
    }
    vis[now] = true;
    for (auto v : g[now]) {
        dfs(v);
    }
}
int main() {
    cin >> n >> m;
    for (LL i = 1; i <= m; i++) {
        LL u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    LL ans = 0;
    for (LL i = 1; i <= n; i++) {
        if (!vis[i]) {
            ans++;
            dfs(i);
        }
    }
    cout << ans - 1;
    return 0;
}

/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/