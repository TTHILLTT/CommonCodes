#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const LL N = 1e5 + 5;
struct prblm {
    LL a, b;
};
bool prCmp(prblm x, prblm y) {
    if (x.a != y.a) {
        return x.a < y.a;
    }
    else {
        return x.b > y.b;
    }
}
LL n, m, k, ans[N], sum, c[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> m >> n >> k;
    vector<prblm> t(n);
    for (auto& i : t) {
        cin >> i.a;
        i.a--;
    }
    for (auto& i : t) {
        cin >> i.b;
    }
    sort(t.begin(), t.end(), prCmp);
    for (LL i = 0; i < n; i++) {
        if (c[t[i].a] < k) {
            ans[t[i].a]++;
            sum++;
            c[t[i].a] += t[i].b;
        }
    }
    for (LL i = 0; i < m; i++) {
        if (c[i] < k) {
            cout << -1;
            return 0;
        }
    }
    for (LL i = 0; i < m; i++) {
        if (ans[i] > sum - ans[i] + 1) {
            if (ans[i] * 2 <= n) {
                sum = ans[i] * 2;
                break;
            }
            cout << -1;
            return 0;
        }
    }
    cout << sum;
    return 0;
}

/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/