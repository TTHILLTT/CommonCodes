#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
bool jz[1005][1005];
LL sumzj, sum1;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    LL n, m;
    cin >> n >> m;
    for (LL i = 1; i <= n; i++) {
        for (LL j = 1; j <= n; j++) {
            cin >> jz[i][j];
        }
    }
    for (LL i = 1; i <= n; i++) {
        if (jz[m][i] == 1) {
            sum1++;
        }
        if (jz[i][m] == 1) {
            sumzj++;
        }
    }
    cout << sum1 << " " << sumzj << " " << sum1 + sumzj;
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/