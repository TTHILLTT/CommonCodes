#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n, m, k;
int main() {
    cin >> n >> m >> k;
    vector<LL> profits(n + 1), costs(n + 1);
    for (LL i = 1; i <= n; i++) {
        cin >> profits[i] >> costs[i];
    }
    vector<vector<LL>> dp(n + 1, vector<LL>(m + 1, LLONG_MIN));
    dp[0][0] = 0;
    for (LL i = 1; i <= n; i++) {
        for (LL c = 0; c <= m; c++) {
            dp[i][c] = dp[i-1][c];
        }
        for (LL prev = max(0ll, i - k); prev < i; prev++) {
            for (LL c = 0; c <= m; c++) {
                if (dp[prev][c] != LLONG_MIN) {
                    LL new_cost = c + costs[i];
                    if (new_cost <= m) {
                        dp[i][new_cost] = max(dp[i][new_cost], dp[prev][c] + profits[i]);
                    }
                }
            }
        }
    }
    LL ans = 0;
    for (LL i = 1; i <= n; i++) {
        for (LL c = 0; c <= m; c++) {
            if (dp[i][c] != LLONG_MIN) {
                ans = max(ans, dp[i][c]);
            }
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