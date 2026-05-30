#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL l, r, d, u, ans;
LL f(LL m) {
    LL xl = max(l, -m), xr = min(r, m), yl = max(d, -m), yr = min(u, m);
    if (xl > xr || yl > yr){
        return 0;
    }
    return (xr - xl + 1) * (yr - yl + 1);
}
int main() {
    cin >> l >> r >> d >> u;
    LL maxn = max({abs(l), abs(r), abs(d), abs(u)});
    for (LL i = 0; i <= maxn; i += 2) {
        ans += f(i) - f(i - 1);
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