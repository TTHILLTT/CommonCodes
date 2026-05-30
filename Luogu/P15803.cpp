#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n, m;
struct Road {
    LL u, v, w, b;
    bool operator<(const Road &other) const {
        return b == other.b ? w < other.w : b < other.b;
    }
};
int main() {
    LL n, m;
    cin >> n >> m;
    vector<Road> roads(m);
    for (auto &road : roads) {
        cin >> road.u >> road.v >> road.w >> road.b;
    }
    sort(roads.begin(), roads.end());
    vector<vector<const Road *>> graph(n + 1);
    const auto relax = [&](vector<LL> &dist, queue<LL> &q) {
        while (!q.empty()) {
            LL u = q.front();
            q.pop();
            for (auto road : graph[u]) {
                LL v = u == road->u ? road->v : road->u;
                if (dist[u] + road->w < dist[v]) {
                    dist[v] = dist[u] + road->w;
                    q.push(v);
                }
            }
        }
    };
    vector<LL> dist1(n + 1, 1e18), distn(n + 1, 1e18);
    dist1[1] = 0, distn[n] = 0;
    queue<LL> q1, qn;
    LL ans = 1e18;
    for (const auto &road : roads) {
        ans = min(ans, min(dist1[road.u] + distn[road.v], dist1[road.v] + distn[road.u]));
        graph[road.u].push_back(&road);
        graph[road.v].push_back(&road);
        q1.push(road.u);
        q1.push(road.v);
        relax(dist1, q1);
        qn.push(road.u);
        qn.push(road.v);
        relax(distn, qn);
    }
    cout << (ans == 1e18 ? -1 : ans) << "\n";
    return 0;
}

/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/