#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
inline LL read() {
    LL s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
//      if(ch=='-')w=-1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        s = s * 10 + ch - '0', ch = getchar();
    }
    return s * w;
}
const LL N = 100005;
vector<LL> g[N];
LL color[N], ans = 1;
LL dfs(LL u, LL fa) {
    LL max1 = 0, max2 = 0;
    for (LL v : g[u]) {
        if (v == fa) continue;
        LL t = dfs(v, u);
        if (color[u] != color[v]) {
            if (t > max1) {
                max2 = max1;
                max1 = t;
            } else if (t > max2) {
                max2 = t;
            }
        }
    }
    ans = max(ans, max1 + max2 + 1);
    return max1 + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n;
    cin >> n;
    for (LL i = 1; i <= n; i++) {
        cin >> color[i];
    }
    for (LL i = 1; i < n; i++) {
        LL u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans;
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/