#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n, a[1005], b[1005], c[1005], pre[1005], ans;
LL dp[1005][5][1005];
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
    for (LL i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + b[i];
    }
    for (LL i = 1; i <= n; i++) {
        for (LL k = 0; k < i; k++) {
            LL w[3];
            if (c[i] == 0) {
                w[0] = a[i];
                w[1] = 2 * a[i];
                w[2] = 0;
            } else if (c[i] == 1) {
                w[0] = 0;
                w[1] = a[i];
                w[2] = 2 * a[i];
            } else {
                w[0] = 2 * a[i];
                w[1] = 0;
                w[2] = a[i];
            }
            dp[i][0][k] = max({dp[i - 1][0][k], dp[i - 1][1][k - 1], dp[i - 1][2][k - 1]}) + w[0];
            dp[i][1][k] = max({dp[i - 1][0][k - 1], dp[i - 1][1][k], dp[i - 1][2][k - 1]}) + w[1];
            dp[i][2][k] = max({dp[i - 1][0][k - 1], dp[i - 1][1][k - 1], dp[i - 1][2][k]}) + w[2];
        }
    }
    for (LL k = 0; k < n; k++) {
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