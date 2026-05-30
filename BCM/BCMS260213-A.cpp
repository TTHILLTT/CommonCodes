#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL t;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin >> t;
    while (t--) {
        LL n;
        cin >> n;
        LL sqrtN = sqrt(n);
        if (sqrtN * sqrtN == n) {
            cout << sqrtN << ' ' << sqrtN << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/