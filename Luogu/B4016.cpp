#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 100005;
vector<LL> g[N];
LL n, maxx, farthest;
void dfs(LL u, LL fa, LL dist) {
    if (dist > maxx) {
        maxx = dist;
        farthest = u;
    }
    for (LL v : g[u]) {
        if (v != fa) {
            dfs(v, u, dist + 1);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (LL i = 1; i < n; i++) {
        LL u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    maxx = -1;
    dfs(1, 0, 0);
    LL start = farthest;
    maxx = -1;
    dfs(start, 0, 0);
    cout << maxx;
    return 0;
}
/*
=====================================================================
                              TTHILLTT                              |
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/