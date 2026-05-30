#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const LL N = 100005;
vector<LL> G[N];
LL color[N], cnt1, cnt2;
bool flg;
void dfs(LL u, LL c) {
    color[u] = c;
    if (c == 1) {
        cnt1++;
    } else {
        cnt2++;
    }
    for (LL v : G[u]) {
        if (!color[v]) {
            dfs(v, 3 - c);
        } else if (color[v] == color[u]) {
            flg = false;
        }
    }
}
int main() {
    LL n, m;
    cin >> n >> m;
    for (LL i = 1; i <= m; i++) {
        LL u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    LL ans = 0;
    for (LL i = 1; i <= n; i++) {
        if (!color[i]) {
            cnt1 = cnt2 = 0;
            flg = true;
            dfs(i, 1);
            if (!flg) {
                cout << "Impossible";
                return 0;
            }
            ans += min(cnt1, cnt2);
        }
    }
    cout << ans;
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/