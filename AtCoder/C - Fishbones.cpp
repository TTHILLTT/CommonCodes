#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
bool apr[11][11][27];
LL n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    cin >> n;
    vector<LL> a(n), b(n);
    for (LL i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    cin >> m;
    vector<string> s(m);
    for (LL i = 0; i < m; i++) {
        cin >> s[i];
    }
    for (string t : s) {
        LL len = t.size();
        for (LL p = 0; p < len; p++) {
            apr[len][p + 1][t[p] - 'a'] = true;
        }
    }
    for (string cur : s) {
        if (cur.size() != n) {
            cout << "No" << endl;
            continue;
        }
        bool flag = true;
        for (LL i = 0; i < n; i++) {
            LL len=a[i], pos=b[i];
            char c=cur[i];
            if (!apr[len][pos][c - 'a']) {
                flag = false;
                break;
            }
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}
/*
=====================================================================
                              TTHILLTT                              |
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/