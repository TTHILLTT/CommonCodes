#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
inline LL read() {
    LL s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        s = s * 10 + ch - '0', ch = getchar();
    }
    return s * w;
}
const LL MAXN = 200005;
struct Interval {
    LL L, R;
    bool operator<(const Interval& other) const {
        if (R != other.R) {
            return R < other.R;
        }
        return L < other.L;
    }
} a[MAXN];
LL N, K;
bool check(LL mid) {
    LL cnt = 0;
    LL last_R = -1e18;
    for (LL i = 0; i < N; i++) {
        if (a[i].L >= last_R + mid) {
            cnt++;
            last_R = a[i].R;
            if (cnt >= K) {
                return true;
            }
        }
    }
    return cnt >= K;
}
int main() {
    N = read();
    K = read();
    LL maxR = 0, minL = 1e18;
    for (LL i = 0; i < N; i++) {
        a[i].L = read();
        a[i].R = read();
        maxR = max(maxR, a[i].R);
        minL = min(minL, a[i].L);
    }
    sort(a, a + N);
    if (!check(1)) {
        cout << -1 << endl;
        return 0;
    }
    LL lo = 1, hi = maxR - minL;
    while (lo < hi) {
        LL mid = (lo + hi + 1) / 2;
        if (check(mid)) {
            lo = mid;
        }
        else {
            hi = mid - 1;
        }
    }
    cout << lo << endl;
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/