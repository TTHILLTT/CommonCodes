#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n, a[1005], b[1005], c[1005], pre[1005], ans;
LL dp[1005][5][1005];
LL gt(LL me, LL opp, LL val) {
    if (me == opp) {
        return val;
    }
    if ((me + 1) % 3 == opp) {
        return 0; // Lose
    }
    return 2 * val; // Win
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin >> n;
    for (LL i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (LL i = 1; i < n; i++) {
        cin >> b[i];
    }
    for (LL i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + b[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < i; k++) {
            if (c[i] == 0) {
                dp[i][0][k] = max({dp[i - 1][0][k], dp[i - 1][1][k - 1], dp[i - 1][2][k - 1]}) + a[i];
                dp[i][1][k] = max({dp[i - 1][0][k - 1], dp[i - 1][1][k], dp[i - 1][2][k - 1]}) + 2 * a[i];
                dp[i][2][k] = max({dp[i - 1][0][k - 1], dp[i - 1][1][k - 1], dp[i - 1][2][k]});
            } if (c[i] == 1) {
                dp[i][0][k] = max({dp[i - 1][0][k], dp[i - 1][1][k - 1], dp[i - 1][2][k - 1]});
                dp[i][1][k] = max({dp[i - 1][0][k - 1], dp[i - 1][1][k], dp[i - 1][2][k - 1]}) + a[i];
                dp[i][2][k] = max({dp[i - 1][0][k - 1], dp[i - 1][1][k - 1], dp[i - 1][2][k]}) + 2 * a[i];
            } if (c[i] == 2) {
                dp[i][0][k] = max({dp[i - 1][0][k], dp[i - 1][1][k - 1], dp[i - 1][2][k - 1]}) + 2 * a[i];
                dp[i][1][k] = max({dp[i - 1][0][k - 1], dp[i - 1][1][k], dp[i - 1][2][k - 1]});
                dp[i][2][k] = max({dp[i - 1][0][k - 1], dp[i - 1][1][k - 1], dp[i - 1][2][k]}) + a[i];
            }
        }
    }
    for (int k = 0; k < n; k++) {
        ans = max({ans, dp[n][0][k] - pre[k], dp[n][1][k] - pre[k], dp[n][2][k] - pre[k]});
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