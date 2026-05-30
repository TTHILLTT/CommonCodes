#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n, a[100005], b[35], preXor, ans, cnt[1 << 10], prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (LL i = 1; i <= 30; i++) {
        LL j = i;
        for (LL k = 0; k < 10; k++) {
            while (j % prime[k] == 0) {
                b[i] ^= 1 << k;
                j /= prime[k];
            }
        }
    }
    cnt[0] = 1;
    for (LL i = 1; i <= n; i++) {
        cin >> a[i];
        preXor ^= b[a[i]];
        ans += cnt[preXor]++;
    }
    cout << ans;
    return 0;
}
