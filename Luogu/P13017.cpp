#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, m, sum;
vector<LL>tree[100005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (LL i = 1; i <= m; i++) {
        LL u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for (LL i = 1; i <= n; i++) {
        sum += (tree[i].size() * (tree[i].size() - 1) / 2);
    }
    cout << sum;
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/