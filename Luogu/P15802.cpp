#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const LL mod = 1e9;
LL t;
LL lst[1000005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin >> t;
    lst[0] = lst[1] = 1;
    lst[2] = 2;
    for (LL i = 3; i <= 1000000; i++) {
        if (i % 3 == 1) {
            lst[i] = (lst[i - 1] + lst[i - 4]) % mod;
        } else {
            lst[i] = (lst[i - 1] + lst[i - 3]) % mod;
        }
    }
    while (t--) {
        LL n;
        cin >> n;
        cout << lst[n] << endl;
    }
    return 0;
}
/*
========================================================================
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/