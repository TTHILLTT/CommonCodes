#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 5005;
LL fa[N];
LL find(LL x) {
    if (fa[x] != x) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
void unite(LL x, LL y) {
    LL fx = find(x), fy = find(y);
    if (fx != fy) {
        fa[fx] = fy;
    }
}
int main() {
    LL n, m, p;
    cin >> n >> m >> p;
    for (LL i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (LL i = 0; i < m; i++) {
        LL a, b;
        cin >> a >> b;
        unite(a, b);
    }
    for (LL i = 0; i < p; i++) {
        LL a, b;
        cin >> a >> b;
        if (find(a) == find(b)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
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