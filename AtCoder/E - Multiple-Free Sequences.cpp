#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL m, a, b;
    cin >> m >> a >> b;
    for (LL x = 0; x < m; x++) {
        for (LL y = 0; y < m; y++) {
            LL s1 = x, s2 = y;
            bool nxt = true, vis[1005][1005];
            memset(vis, false, sizeof vis);
            LL mm = m * m;
            for (LL stp = 0; stp < mm; stp++) {
                if (s1 % m == 0 || s2 % m == 0) {
                    nxt = false;
                    break;
                }
                if (vis[s1][s2]) {
                    break;
                }
                vis[s1][s2] = true;
                LL s3 = (1ll * a * s2 + 1ll * b * s1) % m;
                s1 = s2;
                s2 = s3;
            }
            if (nxt) {
                ans++;
            }
        }
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