#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 1e18;
struct Edge {
    LL u, v;
    LL w, b;
};
LL n, m;
vector<Edge> edges;
vector<pair<LL, LL>> g[5005];
LL dijkstra(LL s, LL t) {
    vector<LL> dist(n + 1, INF);
    priority_queue<pair<LL, LL>, vector<pair<LL, LL>>, greater<>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) {
            continue;
        }
        for (auto [v, w] : g[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[t];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    edges.resize(m);
    for (LL i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w >> edges[i].b;
    }
    LL ans = INF;
    for (LL i = 0; i < m; i++) {
        for (LL j = 1; j <= n; j++) {
            g[j].clear();
        }
        for (LL j = 0; j < m; j++) {
            if (edges[j].b > edges[i].b) {
                continue;
            }
            LL cost = edges[j].w;
            if (j == i) {
                cost = 0;
            }
            g[edges[j].u].emplace_back(edges[j].v, cost);
            g[edges[j].v].emplace_back(edges[j].u, cost);
        }
        LL res = dijkstra(1, n);
        ans = min(ans, res);
    }
    if (ans == INF) {
        cout << -1;
    }
    else {
        cout << ans;
    }
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/