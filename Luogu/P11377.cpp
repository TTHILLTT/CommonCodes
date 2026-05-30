#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n, P, Q, p[105], c[105], dp[105][50005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    LL t;
    cin >> t;
    while (t--) {
        cin >> n >> P >> Q;
        for (LL i = 1; i <= n; i++) {
            cin >> p[i] >> c[i];
        }
        memset(dp, 0, sizeof dp);
        for (LL i = 1; i <= n; i++) {
            for (LL j = 1; j <= Q; j++) {
                dp[i][j] = dp[i - 1][j];
                if (c[i] <= j) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + p[i]);
                }
            }
        }
        for (LL q = 1; q <= Q; q++) {
            if (dp[n][q] >= P) {
                cout << q << endl;
                goto ig;
                break;
            }
        }
        cout << -1 << endl;
ig:
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