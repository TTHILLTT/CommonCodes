#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, x, sum, cnt, a[300005];
signed main() {
    cin >> n >> k >> x;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = n;i > n - k;i--)
        sum -= a[i];
    cnt = -sum;
    for (int i = 1;i <= n;i++) {
        cnt += a[i];
        if (cnt >= x) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}

/*
========================================================================
                        Programed by KaoXiqi                           | 
                         TTHILLTT.github.io                            |
========================================================================
*/