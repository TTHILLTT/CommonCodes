#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    LL T;
    cin >> T;
    while (T--) {
        LL n, d;
        cin >> n >> d;
        vector<LL> a(n), b(n);
        for (auto& i : a) {
            cin >> i;
        }
        for (auto& i : b) {
            cin >> i;
        }
        queue<pair<LL, LL>> q;
        LL day = 0;
        for (LL i = 0; i < n; ++i) {
            day++;
            if (a[i] > 0) {
                q.push({day, a[i]});
            }
            LL nd = b[i];
            while (nd > 0 && !q.empty()) {
                LL use = min(q.front().second, nd);
                q.front().second -= use;
                nd -= use;
                if (q.front().second == 0) q.pop();
            }
            while (!q.empty() && q.front().first <= day - d) {
                q.pop();
            }
        }
        LL ans = 0;
        while (!q.empty()) {
            ans += q.front().second;
            q.pop();
        }
        cout << ans << endl;
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