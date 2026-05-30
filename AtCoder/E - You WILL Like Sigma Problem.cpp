#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
int main() {
    LL n, m;
    scanf("%lld %lld", &n, &m);
    vector<LL> a(n), b(m);
    for (LL i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (LL j = 0; j < m; j++) {
        scanf("%lld", &b[j]);
    }
    vector<LL> bsum(m + 2, 0);
    for (LL j = 0; j < m; j++) {
        bsum[j + 1] = (bsum[j] + b[j]) % MOD;
    }
    LL ans = 0;
    for (LL j = 0; j < m; j++) {
        LL bj = b[j];
        for (LL i = 0; i < n; i++) {
            ans = (ans + a[i] * bj % MOD * ((i + 1) % (j + 1)) ) % MOD;
        }
    }
    cout << ans;
    return 0;
}
/*
=====================================================================
                              TTHILLTT                              |
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/