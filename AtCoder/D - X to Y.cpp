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
LL x, y, k;
LL depth(LL n) {
    LL d = 0;
    while (n > 0) { 
        n /= k; 
        d++;
    }
    return d;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    LL T;
    cin >> T;
    while (T--) {
        cin >> x >> y >> k;
        LL dX = depth(x), dY = depth(y);
        LL ans = 0;
        while (dX > dY) {
            x /= k;
            dX--;
            ans++;
        }
        while (dY > dX) {
            y /= k;
            dY--;
            ans++;
        }
        while (x != y) {
            x /= k;
            y /= k;
            ans += 2;
        }
        cout << ans << endl;
    }
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/