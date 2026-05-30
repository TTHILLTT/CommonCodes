#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
bool vis[100005];
LL cnt1, cnt2, ans1, ans2, n, m;
vector<LL> G[100005];
void dfs(LL u, LL tag) {
    vis[u] = true;
    if (tag == 1) {
        cnt1++;
    }
    else {
        cnt2++;
    }
    for (LL v : G[u]) {
        if (!vis[v]) {
            dfs(v, 3 - tag);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        LL u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (LL i = 1; i <= n; i++) {
        cnt1 = cnt2 = 0;
        dfs(i, 1);
        ans1 += max(cnt1, cnt2);
        ans2 += min(cnt1, cnt2);
    }
    cout << ans1 << " " << ans2;
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/