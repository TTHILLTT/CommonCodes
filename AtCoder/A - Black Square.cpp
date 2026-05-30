#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int P, Q, X, Y;
    cin >> P >> Q >> X >> Y;
    if (X >= P && X < P + 100 && Y >= Q && Y < Q + 100) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           | 
                         TTHILLTT.github.io                            |
========================================================================
*/