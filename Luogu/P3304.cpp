#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLLLL;
LL n, farthest, maxx;
vector<PLLLL> g[200005];
void dfs(LL u, LL fa, LL dist) {
    if (dist > maxx) {
        maxx = dist;
        farthest = u;
    }
    for (auto v : g[u]) {
        if (v.first != fa) {
            dfs(v.first, u, dist + v.second);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin >> n;
    for (LL i = 1; i < n; i++) {
        LL u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    maxx = -0x3f3f3f3f3f3f3f3f;
    dfs(1, 0, 0);
    LL start = farthest;
    maxx = -0x3f3f3f3f3f3f3f3f;
    dfs(start, 0, 0);
    cout << maxx << endl;
    return 0;
}
/*
=====================================================================
                              TTHILLTT                              |
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/