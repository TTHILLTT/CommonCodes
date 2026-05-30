#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define arr array<int, 3>
using namespace std;
int n, k, x, a[100005];
signed main() {
    cin >> n >> k >> x;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    priority_queue<arr> q;
    q.push({a[1] * k, 2, k});
    for (int i = 1;i <= x;i++)
    {
        auto res = q.top();
        q.pop();
        cout << res[0] << '\n';
        if (res[2] == 0)
            continue;
        for (int j = res[1];j <= n;j++) {
            q.push({res[0] - a[1] + a[j], j, res[2] - 1});
        }
    }
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           | 
                         TTHILLTT.github.io                            |
========================================================================
*/