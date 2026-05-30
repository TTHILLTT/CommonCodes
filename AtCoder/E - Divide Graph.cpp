#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
struct Edge {
    LL u, v, id;
};
struct DSU {
    vector<LL> parent;
    DSU(LL n) {
        parent.resize(n + 1);
        for (LL i = 1; i <= n; i++) {
            parent[i] = i;
        }   
    }
    LL find(LL i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    bool unite(LL i, LL j) {
        LL root_i = find(i);
        LL root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    LL n, m;
    cin >> n >> m;
    vector<Edge> all_edges(m);
    for (LL i = 0; i < m; i++) {
        cin >> all_edges[i].u >> all_edges[i].v;
        all_edges[i].id = i + 1;
    }
    DSU dsu(n);
    vector<vector<LL>> tree_adj(n + 1);
    LL min_tree_edge_id = m + 1;
    Edge target_edge = {0, 0, 0};
    vector<Edge> tree_edges;
    for (LL i = m - 1; i >= 0; i--) {
        if (dsu.unite(all_edges[i].u, all_edges[i].v)) {
            tree_adj[all_edges[i].u].push_back(all_edges[i].v);
            tree_adj[all_edges[i].v].push_back(all_edges[i].u);
            tree_edges.push_back(all_edges[i]);
        }
    }
    for (auto& e : tree_edges) {
        if (e.id < min_tree_edge_id) {
            min_tree_edge_id = e.id;
            target_edge = e;
        }
    }
    vector<bool> in_component_s(n + 1, false);
    vector<LL> q;
    q.push_back(target_edge.u);
    in_component_s[target_edge.u] = true;
    LL head = 0;
    while (head < q.size()) {
        LL u = q[head++];
        for (LL v : tree_adj[u]) {
            if ((u == target_edge.u && v == target_edge.v) || (u == target_edge.v && v == target_edge.u)) {
                continue;
            }
            if (!in_component_s[v]) {
                in_component_s[v] = true;
                q.push_back(v);
            }
        }
    }
    vector<LL> pow2(m + 1);
    pow2[0] = 1;
    for (LL i = 1; i <= m; i++) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }
    LL total_cost = 0;
    for (LL i = 0; i < m; i++) {
        bool u_in = in_component_s[all_edges[i].u];
        bool v_in = in_component_s[all_edges[i].v];
        if (u_in != v_in) {
            total_cost = (total_cost + pow2[all_edges[i].id]) % MOD;
        }
    }
    cout << total_cost << endl;
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/