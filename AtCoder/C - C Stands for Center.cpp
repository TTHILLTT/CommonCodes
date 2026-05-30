#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    LL n = s.size(), ans = 0;

    for (LL i = 0; i < n; i++) {
        if (s[i] == 'C') {
            ans += min(i, n - 1 - i) + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
