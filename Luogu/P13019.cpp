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
LL n, q, fa[100005][20], minChild[100005][20];
vector<LL>g[100005];
void dfs(LL u, LL f) {
    fa[u][0] = f;
    if (!g[u].empty()) {
        minChild[u][0] = *min_element(g[u].begin(), g[u].end());
    } else {
        minChild[u][0] = u;
    }
    for (auto v : g[u]) {
        if (v == f) {
            continue;
        }
        dfs(v, u);
    }
    return;
}
LL jumpFa(LL u, LL x) {
    for (int k = 0; k < 20; k++) {
        if ((x >> k) & 1) {
            u = fa[u][k];
        }
    }
    return u;
}
LL jumpMinChild(LL u, LL x) {
    for (int k = 0; k < 20; k++) {
        if ((x >> k) & 1) {
            u = minChild[u][k];
        }
    }
    return u;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    cin >> n >> q;
    for (LL i = 2; i <= n; i++) {
        LL u;
        cin >> u;
        g[u].push_back(i);
    }
    dfs(1, 0);
    fa[1][0] = 1;
    for (LL j = 1; j < 20; j++) {
        for (LL i = 1; i <= n; i++) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
            minChild[i][j] = minChild[minChild[i][j - 1]][j - 1];
        }
    }
    while (q--) {
        LL s, k;
        cin >> s >> k;
        vector<LL>a(k);
        for (auto &x : a) {
            cin >> x;
        }
        LL u = s;
        for (LL i = 0; i < k; i++) {
            if (a[i] > 0) {
                u = jumpFa(u, a[i]);
            } else {
                u = jumpMinChild(u, -a[i]);
            }
        }
        cout << u << endl;
    }
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/