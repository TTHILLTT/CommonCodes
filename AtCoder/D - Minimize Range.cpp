#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n, k;
    cin >> n >> k;
    vector<LL> r;
    for (LL i = 0; i < n; i++) {
        LL a;
        cin >> a;
        r.push_back(a % k);
    }
    sort(r.begin(), r.end());
    r.erase(unique(r.begin(), r.end()), r.end());
    LL m = r.size();
    if (m <= 1) {
        cout << 0;
        return 0;
    }
    LL maxGap = 0;
    for (LL i = 0; i < m - 1; i++) {
        maxGap = max(maxGap, r[i + 1] - r[i]);
    }
    LL g = k - (r[m - 1] - r[0]);
    maxGap = max(maxGap, g);
    cout << k - maxGap;
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/