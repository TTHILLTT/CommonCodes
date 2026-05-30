#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n, res, a, f[1 << 26];
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        a ^= (1 << (s[i] - 'a'));
        if (a == 0) {
            res++;
        }
        res += f[a];
        f[a]++;
    }
    cout << res;
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/