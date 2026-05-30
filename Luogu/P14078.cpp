#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n;
pair<LL, LL> a[100005];
int main() {
    cin >> n;
    for (LL i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        a[i].second -= a[i].first;
    }
    sort(a + 1, a + n + 1);
    vector<LL> f;
    for (LL i = 1; i <= n; i++) {
        if (a[i].second < 0) {
            continue;
        }
        if (f.empty() || a[i].second >= f.back()) {
            f.emplace_back(a[i].second);
        }
        else {
            auto it = upper_bound(f.begin(), f.end(), a[i].second);
            *it = a[i].second;
        }
    }
    cout << f.size();
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/