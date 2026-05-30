#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n, k;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin >> n >> k;
    vector<LL> d(n);
    for (auto& i : d) {
        cin >> i;
    }
    sort(d.begin(), d.end(), greater<LL>());
    LL ans = 0;
    for (LL i = k; i < n; i++) {
        ans += d[i];
    }
    cout << ans;
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/