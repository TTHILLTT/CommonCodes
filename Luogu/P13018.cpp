#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n, dp[105][500005], a[105], b[105];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    memset(dp, -0x3f, sizeof(dp));
    cin >> n;
    dp[0][50000] = 0;
    for (LL i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        for (LL j = 100000 + a[i] - b[i]; j >= a[i] - b[i]; j--) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - (a[i] - b[i])] + a[i] + b[i]);
        }
    }
    cout << dp[n][50000] << endl;
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/