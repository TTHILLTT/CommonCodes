#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n, k, dp[300005], a[505], c[505], s;
int main() {
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    cin >> n >> k;
    for (LL i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        s += a[i];
    }
    for (LL i = 1; i <= n; i++) {
        for (LL j = s; j >= a[i]; j--) {
            dp[j] = min(dp[j], dp[j - a[i]] + c[i]);
        }
    }
    for (LL i = s; i >= 0; i--) {
        if (dp[i] <= k) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
