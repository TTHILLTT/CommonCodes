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
const LL MOD = 998244353;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);string S;
    cin >> s;
    LL n = s.size(), ans = 0, l = 0;
    for (LL r = 0; r < n; r++) {
        if (r > 0 && s[r] == s[r - 1]) {
            l = r;
        }
        ans = (ans + (r - l + 1)) % MOD;
    }
    cout << ans << endl;
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/