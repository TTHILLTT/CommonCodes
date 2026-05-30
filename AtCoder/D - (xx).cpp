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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    LL T; cin >> T;
    vector<string> votqi(T * 2);
    for (LL i = 0; i < T * 2; ++i) cin >> votqi[i];
    vector<string> ans(T);
    auto norm = [](const string & s) -> string {
        string res;
        LL n = s.size();
        for (LL i = 0; i < n;) {
            if (i + 3 <= n && s[i] == '(' && s[i + 1] == 'x' && s[i + 2] == 'x' && s[i + 3 - 1] == ')') {
                res += "+";
                i += 3;
            } else if (i + 2 <= n && s[i] == 'x' && s[i + 1] == 'x') {
                res += "+";
                i += 2;
            } else {
                res += s[i];
                ++i;
            }
        }
        return res;
    };
    for (LL t = 0; t < T; ++t) {
        string a = votqi[t * 2], b = votqi[t * 2 + 1];
        a = norm(a);
        b = norm(b);
        ans[t] = (a == b ? "Yes" : "No");
    }
    for (auto& x : ans) cout << x << '\n';
    return 0;
}
/*
=====================================================================
                              D - (xx)                              |
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/