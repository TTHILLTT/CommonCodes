#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    LL n;
    cin>>n;
    vector<vector<LL>> A(n, vector<LL>(n, 0));
    for (LL i = 0; i < n - 1; ++i) {
        for (LL j = i + 1; j < n; ++j) {
            LL val;
            cin >> val;
            A[i][j] = A[j][i] = val;
        }
    }
    vector<LL> min_edge(n, INF), parent(n, -1);
    vector<bool> vis(n, false);
    min_edge[0] = 0;
    for (LL i = 0; i < n; i++) {
        LL u = -1;
        for (LL v = 0; v < n; v++) {
            if (!vis[v] && (u == -1 || min_edge[v] < min_edge[u])) {
                u = v;
            }
        }
        if (u == -1) {
            break;
        }
        vis[u] = true;
        for (LL v = 0; v < n; v++) {
            if (!vis[v] && A[u][v] < min_edge[v]) {
                min_edge[v] = A[u][v];
                parent[v] = u;
            }
        }
    }
    vector<vector<pair<LL, LL>>> adj(n);
    for (LL i = 1; i < n; i++) {
        if (parent[i] != -1) {
            adj[i].push_back({parent[i], A[i][parent[i]]});
            adj[parent[i]].push_back({i, A[i][parent[i]]});
        }
    }
    for (LL i = 0; i < n; i++) {
        vector<LL> d(n, -1);
        queue<LL> q;
        q.push(i);
        d[i] = 0;
        while (!q.empty()) {
            LL u = q.front();
            q.pop();
            if (d[u] != (LL)A[i][u]) {
                cout << "No";
                return 0;
            }
            for (auto &edge : adj[u]) {
                LL v = edge.first;
                LL w = edge.second;
                if (d[v] == -1) {
                    d[v] = d[u] + (LL)w;
                    q.push(v);
                }
            }
        }
    }
    cout << "Yes";
    return 0;
}

/*
=====================================================================
                              TTHILLTT                              |
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
                      Google Gemini Generation                      |
=====================================================================
*/