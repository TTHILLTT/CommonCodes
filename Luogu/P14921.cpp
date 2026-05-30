#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n, m, r[2005];
vector<LL> g[2005];
void bfs(LL s) {
    queue<LL> q;
    q.push(s);
    while (!q.empty()) {
        LL u = q.front();
        q.pop();
        for (LL v : g[u]) {
            if (r[v] == 0 && v != s) {
                r[v] = r[u] + 1;
                q.push(v);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (LL i = 1; i <= m; i++) {
        LL u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    LL ans = 0, cnt = 0x3f3f3f3f3f3f3f3f;
    for (LL i = 1; i <= n; i++) {
        memset(r, 0, sizeof r);
        bfs(i);
        LL res = 0;
        // cout << i << ": ";
        for (LL j = 1; j <= n; j++) {
            // cout << r[j] << " ";
            res = max(res, r[j]);
        }
        // cout << endl;
        if (res < cnt) {
            cnt = res, ans = i;
        }
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