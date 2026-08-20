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
const LL MOD = 1000000007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL m = read(), n = read();
    LL r = m - 1, limit = n - 1;
    if (r < 0 || limit < r) {
        cout << 0;
        return 0;
    }
    vector<LL> inv(r + 1, 1);
    if (r >= 1) {
        inv[1] = 1;
        for (LL i = 2; i <= r; i++) {
            inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
        }
    }
    LL ans = 1;
    for (LL i = 1; i <= r; i++) {
        ans = ans * (limit - i + 1) % MOD;
        ans = ans * inv[i] % MOD;
    }
    cout << ans;
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/