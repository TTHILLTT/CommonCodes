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
    LL a[3][6];
    for (LL i = 0; i < 3; i++) {
        for (LL j = 0; j < 6; j++) {
            a[i][j] = read();
        }
    }
    LL cnt = 0;
    for (LL i = 0; i < 6; i++) {
        for (LL j = 0; j < 6; j++) {
            for (LL k = 0; k < 6; k++) {
                vector<LL> v = {a[0][i], a[1][j], a[2][k]};
                sort(v.begin(), v.end());
                if (v[0] == 4 && v[1] == 5 && v[2] == 6) {
                    cnt++;
                }
            }
        }
    }
    cout << fixed << setprecision(10) << cnt / 216.0 << endl;
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/