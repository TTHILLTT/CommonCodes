#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const LL N = 1e5+5;
LL n, a[N], p[N][20], ans;
void f(LL x) {
    if (x == 1) {
        return;
    }
    unordered_map<LL, LL> t;
    for (LL i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            p[i][++t[i]]++;
            x /= i;
        }
        if (x == 1) {
            return;
        }
    }
    p[x][++t[x]]++;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (LL i = 1; i <= n; i++) {
        cin >> a[i];
        f(a[i]);
    }
    for (LL i = 2; i <= 100000; i++) {
        for (LL j = 1; j < 20; j++) {
            if (!p[i][j]) {
                break;
            }
            ans += min(p[i][j], n - p[i][j]);
        }
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