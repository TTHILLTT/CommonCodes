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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    LL n, m;
    cin >> n >> m;
    vector<vector<LL>> g(n + 1);
    for(LL i = 1; i <= m; i++) {
        LL a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    vector<bool> vis(n + 1, false);
    queue<LL> q;
    q.push(1);
    vis[1] = true;
    LL cnt = 1;
    while(!q.empty()) {
        LL u = q.front();
        q.pop();
        for(LL v : g[u]) {
            if(!vis[v]) {
                vis[v] = true;
                cnt++;
                q.push(v);
            }
        }
    }
    cout << cnt;
    return 0;
}
/*
=====================================================================
                        C - Straw Millionaire                       |
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/