#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n, k;
int main() {
    cin >> n >> k;
    vector<LL> h(n);
    for (auto& i : h) {
        cin >> i;
    }
    deque<LL> maxq, minq;
    LL ans = 0;
    for (LL i = 0; i < n; i++) {
        while (!maxq.empty() && h[maxq.back()] <= h[i]) {
            maxq.pop_back();
        }
        maxq.push_back(i);
        while (!minq.empty() && h[minq.back()] >= h[i]) {
            minq.pop_back();
        }
        minq.push_back(i);
        if (maxq.front() <= i - k) {
            maxq.pop_front();
        }
        if (minq.front() <= i - k) {
            minq.pop_front();
        }
        if (i >= k - 1) {
            ans = max(ans, h[maxq.front()] - h[minq.front()]);
        }
    }
    cout << ans << endl;
    return 0;
}