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
const LL N = 2e5 + 5;
LL n, m, t[N], c[N], f[N][25], ans = -0x3f3f3f3f3f3f3f3f;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    cin >> n >> m;
    for (LL i = 1; i <= n; i++) {
        cin >> t[i];
        t[i + n] = t[i];
    }
    LL cnt = 0, j = 1;
    for (LL i = 1; i <= n; i++) {
        if (i - 1 != 0) {
            c[t[i - 1]]--;
            if (c[t[i - 1]] == 0) {
                cnt--;
            }
        }
        while (j < 2 * n && cnt < m) {
            c[t[j]]++;
            if (c[t[j]] == 1) {
                cnt++;
            }
            j++;
        }
        f[i][0] = j;
        f[i + n][0] = j + n;
    }
    for (LL j = 1; j <= 20; j++) {
        for (LL i = 1; i <= n; i++) {
            f[i][j] = f[f[i][j - 1]][j - 1];
        }
    }
    for (LL i = 1, j = n; i <= n; i++, j++) {
        LL sum = 0, u = i;
        for (LL k = 20; k >= 0; k--) {
            if (f[u][k] != 0 && f[u][k] <= j + 1) {
                sum += (1 << k);
                u = f[u][k];
            }
        }
        ans = max(ans, sum);
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