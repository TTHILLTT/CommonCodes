#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
struct BIT {
    int n;
    vector<int> c;
    BIT(int n): n(n), c(n+2, 0) {}
    void add(int x, int v) {
        for (; x <= n; x += x & -x) c[x] += v;
    }
    int sum(int x) {
        int r = 0;
        for (; x; x -= x & -x) r += c[x];
        return r;
    }
    int kth(int k) {
        int x = 0, s = 0;
        for (int i = 20; i >= 0; --i) {
            if (x + (1 << i) <= n && s + c[x + (1 << i)] < k) {
                x += (1 << i);
                s += c[x];
            }
        }
        return x + 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n, m;
    cin >> n >> m;
    vector<LL> a(n);
    vector<LL> cnt(m + 1, 0);
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    LL Q;
    cin >> Q;
    vector<pair<LL, int>> queries(Q);
    for (int i = 0; i < Q; i++) {
        LL x; cin >> x;
        queries[i] = {x, i};
    }
    vector<LL> ans(Q);
    // 统计每个数字出现次数
    vector<pair<LL, int>> freq;
    for (int i = 1; i <= m; i++) freq.push_back({cnt[i], i});
    sort(freq.begin(), freq.end());
    // 二分层数
    LL left = 0, right = 1e18 / m + 10, layer = 0;
    while (left <= right) {
        LL mid = (left + right) / 2;
        LL total = 0;
        for (auto [c, v] : freq) total += max(0LL, mid - c);
        if (total + n >= queries[0].first) {
            layer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    // 统计填满layer后每个数的出现次数
    vector<LL> fill(m + 1);
    for (int i = 1; i <= m; i++) fill[i] = max(cnt[i], layer);
    // 统计填满layer后总长度
    LL filled = 0;
    for (int i = 1; i <= m; i++) filled += fill[i];
    // 离线处理所有查询
    vector<vector<pair<LL, int>>> bucket(m + 2);
    for (int i = 0; i < Q; i++) {
        LL x = queries[i].first;
        if (x <= n) {
            ans[queries[i].second] = a[x - 1];
        } else if (x <= filled) {
            bucket[(x - n - 1) % m + 1].push_back({x, queries[i].second});
        } else {
            LL rem = (x - filled - 1) % m + 1;
            bucket[rem].push_back({x, queries[i].second});
        }
    }
    // 用树状数组找第k小
    BIT bit(m);
    for (int i = 1; i <= m; i++) bit.add(i, 1);
    for (int i = 1; i <= m; i++) {
        for (auto [x, idx] : bucket[i]) {
            ans[idx] = bit.kth(i);
        }
    }
    for (int i = 0; i < Q; i++) cout << ans[i] << "\n";
    return 0;
}