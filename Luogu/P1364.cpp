#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const LL N = 105;
LL w[N], l[N], r[N], n, sum[N], dist[N];
vector<LL> tree[N];
void dfs1(LL u, LL fa) {
    sum[u] = w[u];
    for (LL v : tree[u]) {
        if (v == fa) continue;
        dfs1(v, u);
        sum[u] += sum[v];
        dist[u] += dist[v] + sum[v];
    }
}
void dfs2(LL u, LL fa) {
    for (LL v : tree[u]) {
        if (v == fa) continue;
        dist[v] = dist[u] + (sum[1] - 2 * sum[v]);
        dfs2(v, u);
    }
}

int main() {
    cin >> n;
    for (LL i = 1; i <= n; i++) {
        cin >> w[i] >> l[i] >> r[i];
        if (l[i]) {
            tree[i].push_back(l[i]);
        }
        if (r[i]) {
            tree[i].push_back(r[i]);
        }
    }
    dfs1(1, 0);
    dfs2(1, 0);
    LL ans = dist[1];
    for (LL i = 2; i <= n; i++) {
        if (dist[i] < ans) {
            ans = dist[i];
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