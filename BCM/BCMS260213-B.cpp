#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    vector<vector<LL>> a(n, vector<LL>(m));
    vector<LL> rowSum(n, 0), colSum(m, 0);
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < m; j++) {
            cin >> a[i][j];
            rowSum[i] += a[i][j];
            colSum[j] += a[i][j];
        }
    }
    LL ans = 0;
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < m; j++) {
            LL total = rowSum[i] + colSum[j] - a[i][j];
            if (total > ans) {
                ans = total;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/