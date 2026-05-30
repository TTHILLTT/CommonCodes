#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin >> n >> m;
    vector<bool> taken(m + 1, false);
    while (n--) {
        LL o;
        cin >> o;
        bool tk = false;
        while (o--) {
            LL x;
            cin >> x;
            if (tk) {
                continue;
            }
            if (!taken[x]) {
                taken[x] = true;
                cout << x << endl;
                tk = true;
            }
        }
        if (!tk) {
            cout << 0 << endl;
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