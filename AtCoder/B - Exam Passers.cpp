#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n, l, r;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    LL maxx = -0x3f3f3f3f3f3f3f3f, id = -1;
    cin >> n >> l >> r;
    for (LL i = 1; i <= n; i++) {
        LL x;
        cin >> x;
        if (x >= l && x <= r && x > maxx) {
            maxx = max(maxx, x);
            id = i;
        }
    }
    cout << id;
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/