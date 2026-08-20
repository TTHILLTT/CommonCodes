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
    LL T;
    cin >> T;
    while (T--) {
        LL n;
        cin >> n;
        unordered_map<LL, vector<LL>> pos;
        pos.reserve(n * 2);
        for (LL i = 1; i <= n; i++) {
            LL x;
            cin >> x;
            pos[x].push_back(i);
        }
        LL q;
        cin >> q;
        while (q--) {
            LL l, r, x;
            cin >> l >> r >> x;
            auto it = pos.find(x);
            if (it == pos.end()) {
                cout << 0 << '\n';
            } else {
                const auto &vec = it->second;
                LL cnt = upper_bound(vec.begin(), vec.end(), r)
                          - lower_bound(vec.begin(), vec.end(), l);
                cout << cnt << '\n';
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