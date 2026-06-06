#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, m, color[100005];
vector<LL> g[100005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (LL i = 0; i < m; i++) {
        LL u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    memset(color, -1, sizeof(color));
    LL minB = 0, maxB = 0;
    for (LL i = 1; i <= n; i++) {
        if (color[i] != -1) {
            continue;
        }
        queue<LL> q;
        q.push(i);
        color[i] = 0;
        LL cnt0 = 0, cnt1 = 0;
        while (!q.empty()) {
            LL u = q.front(); q.pop();
            if (color[u] == 0) {
                cnt0++;
            }
            else {
                cnt1++;
            }
            for (LL v : g[u]) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    q.push(v);
                }
            }
        }
        minB += min(cnt0, cnt1);
        maxB += max(cnt0, cnt1);
    }
    cout << minB << ' ' << maxB << endl;
    return 0;
}