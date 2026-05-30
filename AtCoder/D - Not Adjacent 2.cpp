#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
inline LL read() {
    LL s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
//      if(ch=='-')w=-1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        s = s * 10 + ch - '0', ch = getchar();
    }
    return s * w;
}
const LL MOD = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    string s;
    cin >> s;
    LL n = s.size();
    vector<LL> dp(3, 0);
    for (LL i = 0; i < n; i++) {
        LL c = s[i] - 'a', sum = 0;
        for (LL k = 0; k < 3; k++) {
            if (k != c) {
                sum = (sum + dp[k]) % MOD;
            }
        }
        dp[c] = (dp[c] + sum + 1) % MOD;
    }
    LL ans = (dp[0] + dp[1] + dp[2]) % MOD;
    cout << ans;
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/