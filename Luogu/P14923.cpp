#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 1e5+5;
LL n, m, a, b, u, v;
LL ans, w, c[N], dis1[N], dis2[N];
bool vis1[N], vis2[N];
struct graph {
    LL to;
    LL w;
    bool operator <(const graph &x) const {
        return x.w < w;
    }
};
vector<graph>g[N];
priority_queue<graph>q;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> a >> b;
    for (LL i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (LL i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (LL i = 1; i <= n; i++) {
        dis1[i] = dis2[i] = 0x3f3f3f3f3f3f3f3f;
    }
    //cat
    dis1[a] = 0;
    q.push({a, 0});
    while (!q.empty()) {
        graph k = q.top();
        q.pop();
        if (vis1[k.to]) {
            continue;
        }
        vis1[k.to] = 1;
        for (graph i : g[k.to]) {
            if (dis1[k.to] + i.w < dis1[i.to]) {
                dis1[i.to] = dis1[k.to] + i.w;
                q.push({i.to, dis1[i.to]});
            }
        }
    }
    //mouse
    dis2[b] = 0;
    q.push({b, 0});
    while (!q.empty()) {
        graph k = q.top();
        q.pop();
        if (vis2[k.to]) {
            continue;
        }
        vis2[k.to] = 1;
        for (graph i : g[k.to]) {
            if (dis2[k.to] + i.w < dis2[i.to]) {
                dis2[i.to] = dis2[k.to] + i.w;
                q.push({i.to, dis2[i.to]});
            }
        }
    }
    for (LL i = 1; i <= n; i++) {
        if (dis1[b] > dis2[i]) {
            ans += c[i];
        }
    }
    cout << ans;
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/