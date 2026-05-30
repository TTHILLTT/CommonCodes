#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n, dp[305][305];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    vector<LL> c(n + 1), a(n + 1);
    for (LL i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (LL i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(c.begin() + 1, c.end());
    for (LL i = 1; i <= n; i++) {
        for (LL j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1] + a[1];
            for (LL k = 2; k <= j; k++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + a[k] + c[n - i + 1] - c[i]);
            }
        }
    }
    LL ans = 0;
    for (LL i = 1; i <= n; i++) {
        ans = max(ans, dp[i][n]);
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