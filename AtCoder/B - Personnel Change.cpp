#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, m, a[105][2];
signed main() {
    cin >> n >> m;
    for(LL i = 1; i <= n; i++) {
        LL A, B;
        cin >> A >> B;
        a[A][0]++;
        a[B][1]++;
    }
    for(LL i = 1; i <= m; i++) {
        cout << a[i][1] - a[i][0] << "\n";
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