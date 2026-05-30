#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    vector<LL> p(m + 5), c(m + 5);
    for (LL i = 1; i <= m; i++) {
        cin >> p[i] >> c[i];
    }
    LL ans = 0x3f3f3f3f3f3f3f3f;
    for (LL k = 0; k <= m; k++) {
        vector<LL> cnt(n + 1, 0);
        vector<pair<LL, LL>> cc;
        for (LL i = 1; i <= m; i++) {
            cnt[p[i]]++;
            if (p[i] != 1) {
                cc.push_back({c[i], i});
            }
        }
        if ((LL)cc.size() < k) {
            continue;
        }
        sort(cc.begin(), cc.end());
        LL cost = 0;
        for (LL i = 0; i < k; i++) {
            cnt[p[cc[i].second]]--;
            cnt[1]++;
            cost += cc[i].first;
        }
        bool ok = true;
        for (LL i = 2; i <= n; i++) {
            if (cnt[1] <= cnt[i]) {
                ok = false;
            }
        }
        if (ok) {
            ans = min(ans, cost);
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