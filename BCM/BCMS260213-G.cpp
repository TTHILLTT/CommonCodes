#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const LL mod = 998244353;
LL lowbit(LL x) {
    return x & -x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n;
    cin >> n;
    vector<LL> a(n + 1);
    for (LL i = 1; i <= n; i++) {
        cin >> a[i];
    }
    LL q;
    cin >> q;
    while (q--) {
        LL op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            for (LL i = l; i <= r; i++) {
                a[i] += lowbit(a[i]);
            }
        } else {
            LL sum = 0;
            for (LL i = l; i <= r; i++) {
                sum = (sum + a[i]) % mod;
            }
            cout << sum << endl;
        }
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