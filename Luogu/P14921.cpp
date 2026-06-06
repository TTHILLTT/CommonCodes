#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n, m;
    cin >> n >> m;
    vector<vector<LL>> adj(n + 1);
    for (LL i = 0; i < m; i++) {
        LL u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    LL ans = 1, min_ecc = n;
    for (LL start = 1; start <= n; start++) {
        vector<LL> dist(n + 1, -1);
        queue<LL> q;
        dist[start] = 0;
        q.push(start);
        LL ecc = 0;
        while (!q.empty()) {
            LL u = q.front();
            q.pop();
            ecc = max(ecc, dist[u]);
            for (LL v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        if (ecc < min_ecc) {
            min_ecc = ecc;
            ans = start;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/
