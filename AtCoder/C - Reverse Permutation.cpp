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
LL n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> n >> s;
    deque<LL> dq;
    bool is_reverse = false;
    for (LL k = 1; k <= n; k++) {
        if (s[k - 1] == 'o') {
            if (is_reverse) {
                dq.push_front(k);
            }
            else {
                dq.push_back(k);
            }
            is_reverse = !is_reverse;
        } else { // 'x'
            if (is_reverse) {
                dq.push_front(k);
            }
            else {
                dq.push_back(k);
            }
        }
    }
    if (is_reverse) {
        for (LL i = dq.size() - 1; i >= 0; i--) {
            cout << dq[i] << " ";
        }
    } else {
        for (LL i = 0; i < dq.size(); i++) {
            cout << dq[i] << " ";
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