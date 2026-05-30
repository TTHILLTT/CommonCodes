#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL t;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin >> t;
    while (t--) {
        LL n, m;
        cin >> n >> m;
        vector<LL>d[n + 5];
        for (LL i = 1; i <= m; i++) {
            LL u, v;
            cin >> u >> v;
            d[u].push_back(v);
            d[v].push_back(u);
        }
        
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