#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n;
    cin >> n;
    unordered_map<LL, LL> dp;
    LL ans = 0;
    while (n--) {
        LL a;
        cin >> a;
        dp[a] = dp[a - 1] + 1;
        ans = max(ans, dp[a]);
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