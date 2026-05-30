#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLLLL;
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
LL n, m, a, b, v[100005], vis[100005];
vector<LL>g[100005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin >> n >> m >> a >> b;
    for (LL i = 0; i < n; i++) {
        cin >> v[i];
    }
    while (m--) {
        LL x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    queue<PLLLL>q;
    q.push({a, 0});
    while (!q.empty()) {
        LL x = q.front().first;
        LL y = q.front().second;
        if (x == b) {
            cout << y + v[b] - v[a];
            goto end;
        }
        q.pop();
        for (auto i : g[x]) {
            if (!vis[i]) {
                vis[i] = 1;
                q.push({i, y + 1});
            }
        }
    }
    cout << "No solution";
end:
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/