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
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    cin >> s;
    LL n;
    cin >> n;
    string ans;
    for (int i = n; i < s.size() - n; i++) {
        ans += s[i];
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