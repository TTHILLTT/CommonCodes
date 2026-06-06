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
    if (n == 2) {
        cout << "! 1" << endl;
        return 0;
    }
    vector<LL> d1(n + 1), dn(n + 1);
    for (LL x = 2; x <= n - 1; x++) {
        cout << "? 1 " << x << endl;
        cin >> d1[x];
    }
    for (LL x = 2; x <= n - 1; x++) {
        cout << "? " << x << ' ' << n << endl;
        cin >> dn[x];
    }
    LL minn = 0x3f3f3f3f3f3f3f3f;
    for (LL x = 2; x <= n - 1; x++) {
        minn = min(minn, d1[x] + dn[x]);
    }
    LL ans = (minn <= 3) ? 2 : minn;
    cout << "! " << ans << endl;
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/