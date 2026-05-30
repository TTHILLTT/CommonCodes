#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    LL n = s.size(), ans = 0;
    vector<LL> hPos;
    for (LL i = 0; i < n - 1; i++) {
        if (s[i] == 'h') {
            hPos.push_back(i);
        }
        if (s[i] == 'y' && s[i + 1] == 'w') {
            LL limit = i - 2;
            if (limit >= 0 && !hPos.empty()) {
                auto it = upper_bound(hPos.begin(), hPos.end(), limit);
                ans += (it - hPos.begin());
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