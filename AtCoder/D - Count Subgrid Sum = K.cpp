#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL c(const vector<LL> &arr, LL k) {
    if (k < 0) return 0;
    LL l = 0, sum = 0;
    LL cnt = 0;
    for (LL r = 0; r < (LL)arr.size(); r++) {
        sum += arr[r];
        while (l <= r && sum > k) {
            sum -= arr[l];
            l++;
        }
        cnt += (r - l + 1);
    }
    return cnt;
}
LL h, w, k;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> h >> w >> k;
    vector<string> grid(h);
    for (LL i = 0; i < h; i++) {
        cin >> grid[i];
    }
    LL ans = 0;
    for (LL r1 = 0; r1 < h; r1++) {
        vector<LL> colSum(w, 0);
        for (LL r2 = r1; r2 < h; r2++) {
            for (LL j = 0; j < w; j++) {
                colSum[j] += (grid[r2][j] - '0');
            }
            ans += c(colSum, k) - c(colSum, k - 1);
        }
    }
    cout << ans;
    return 0;
}
