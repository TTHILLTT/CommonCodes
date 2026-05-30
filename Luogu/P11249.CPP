#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL t, a[100005], maxx = -0x3f3f3f3f3f3f3f3f, far = -0x3f3f3f3f3f3f3f3f;
unordered_map<LL, bool> mp;
vector<vector<LL>> g(100005);
LL dfs(LL fa, LL node, LL dist) {
    if (dist > maxx) {
        maxx = dist;
        far = node;
    }
    LL res = 1;
    for (LL v : g[node]) {
        if (v == fa) {
            continue;
        }
        if (mp[v]) {
            dfs(node, v, dist + 1);
        } else {
            dfs(node, v, 0);
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--) {
        LL n;
        cin >> n;
        vector<LL> treasure;
        for (LL i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == 1) treasure.push_back(i);
        }
        // 清空邻接表和宝物标记
        for (LL i = 1; i <= n; i++) g[i].clear();
        mp.clear();
        for (LL i = 1; i <= n; i++) if (a[i] == 1) mp[i] = true;
        for (LL i = 1; i < n; i++) {
            LL u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if (treasure.size() == 1) {
            cout << "Yes" << endl;
            continue;
        }
        // 第一次DFS，找直径端点
        LL max_dist = -1, far_node = -1;
        function<void(LL, LL, LL&)> dfs1 = [&](LL u, LL fa, LL& ret) {
            if (mp[u]) {
                if (ret < 0) ret = u;
            }
            for (LL v : g[u]) {
                if (v == fa) continue;
                dfs1(v, u, ret);
            }
        };
        LL start = treasure[0];
        LL ret = -1;
        dfs1(start, -1, ret);
        // 第二次DFS，找直径另一端
        vector<LL> dist(n+1, -1);
        function<void(LL, LL, LL)> dfs2 = [&](LL u, LL fa, LL d) {
            dist[u] = d;
            for (LL v : g[u]) {
                if (v == fa) continue;
                dfs2(v, u, d+1);
            }
        };
        dfs2(ret, -1, 0);
        LL far2 = ret;
        for (LL i = 1; i <= n; i++) if (mp[i] && dist[i] > max_dist) { max_dist = dist[i]; far2 = i; }
        // 第三次DFS，记录直径链
        vector<LL> parent(n+1, -1);
        function<void(LL, LL)> dfs3 = [&](LL u, LL fa) {
            parent[u] = fa;
            for (LL v : g[u]) {
                if (v == fa) continue;
                dfs3(v, u);
            }
        };
        dfs3(far2, -1);
        // 回溯直径链
        set<LL> chain;
        LL cur = ret;
        while (cur != -1) {
            chain.insert(cur);
            cur = parent[cur];
        }
        bool ok = true;
        for (LL i : treasure) {
            if (!chain.count(i)) { ok = false; break; }
        }
        cout << (ok ? "Yes" : "No") << endl;
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