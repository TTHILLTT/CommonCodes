#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
bool is(string s, string t) {
    LL p = 0;
    for (char c : s) {
        if (c == t[p]) {
            p++;
        }
        if (p == t.size()) {
            return true;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    string s, t;
    cin >> s >> t;
    LL n = s.size(), ans = 0;
    for (LL l = 0; l < n; l++) {
        for (LL r = l; r < n; r++) {
            string cur = s.substr(l, r - l + 1);
            if (!is(cur, t)) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
/*
=====================================================================
                              TTHILLTT                              |
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/