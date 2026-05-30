#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL num[1000005], vis[1000005], n, u, v;
vector<LL> g[1000005];
void dfs(LL x, LL walk) {
    if (walk % 2 == 0) {
        num[2]++;
        vis[x] = 2;
    }
    else {
        num[1]++;
        vis[x] = 1;
    }
    for (LL i = 0; i < g[x].size(); i++) {
        if (!vis[g[x][i]]) {
            dfs(g[x][i], walk + 1);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (LL i = 1; i <= n - 1; i ++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (LL i = 1; i <= n; i ++) {
        cout << num[vis[i]] << ' ';
    }
    return 0;
}

/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/