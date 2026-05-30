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
LL quick_pow(LL a, LL b, LL p) {
    LL res = 1;
    a %= p;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}
int main() {
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    LL a, b, p;
    if (cin >> a >> b >> p) {
        LL ans = quick_pow(a, b, p);
        printf("%lld^%lld mod %lld=%lld\n", a, b, p, ans);
    }
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/