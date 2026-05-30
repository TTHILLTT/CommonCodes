#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL Q;
    cin >> Q;
    multiset<LL> trees;
    while (Q--) {
        LL t, h;
        cin >> t >> h;
        if (t == 1) {
            trees.insert(h);
        } else {
            auto it = trees.upper_bound(h);
            trees.erase(trees.begin(), it);
        }
        cout << trees.size() << '\n';
    }
    return 0;
}
/*
=====================================================================
                              TTHILLTT                              |
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/