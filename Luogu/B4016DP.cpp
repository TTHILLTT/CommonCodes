#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> g[N];
int n, ans = 0;

int dfs(int u, int fa) {
    int max1 = 0, max2 = 0;
    for (int v : g[u]) {
        if (v == fa) continue;
        int d = dfs(v, u) + 1;
        if (d > max1) {
            max2 = max1;
            max1 = d;
        } else if (d > max2) {
            max2 = d;
        }
    }
    ans = max(ans, max1 + max2);
    return max1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans << '\n';
    return 0;
}
/*
===============================================================================
                              TTHILLTT.github.io                              |
                              Visual Studio Code                              |
===============================================================================
*/