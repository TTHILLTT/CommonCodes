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
int f[1005][1005], n, t, x, y;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    cin >> t;
    for (int q = 1; q <= t; q++) {
        cin >> n;
        for (int i = 1; i <= 2 * n - 2; i++) {
            cin >> x >> y;
            if (x == n && y == n && x + y - 2 < i) {
                cout << "No" << endl;
                break;
            }
            if (x + y - 2 > i) {
                f[x][y] = -1;
            }
        }
        f[1][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if ((f[i - 1][j] == 1 || f[i][j - 1] == 1) && f[i][j] != -1) {
                    f[i][j] = 1;
                }
            }
        }
        if (f[n][n] == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        if (q != t) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    f[i][j] = 0;
                }
            }
        }
    }
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/