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
LL a[100005], nxt[100005], f[100005][15];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    LL t;
    t = read();
    while (t--) {
        LL n;
        n = read();
        for (LL i = 1; i <= n; i++) {
            a[i] = read();
        }
        vector<LL> last(14, n + 1);
        for (LL i = n; i >= 1; i--) {
            nxt[i] = last[a[i]];
            last[a[i]] = i;
        }
        for (LL i = 1; i <= n; i++) {
            f[i][0] = nxt[i];
        }
        for (LL k = 1; k < 15; k++) {
            for (LL i = 1; i <= n; i++) {
                if (f[i][k - 1] <= n) {
                    f[i][k] = f[f[i][k - 1]][k - 1];
                } else {
                    f[i][k] = n + 1;
                }
            }
        }
        LL q;
        q = read();
    }
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/