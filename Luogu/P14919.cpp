#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const int N = 100005;
vector<int> G[N];
LL c[N], f[N];
void dfs(int u) {
    if (G[u].empty()) {
        f[u] = c[u];
        return;
    }
    LL sum = 0;
    for (int v : G[u]) {
        dfs(v);
        sum += f[v];
    }
    f[u] = min(c[u], sum);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int fa;
        cin >> fa;
        G[fa].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    dfs(1);
    cout << f[1];
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/