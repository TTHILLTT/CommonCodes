#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);

    int H, W, Q;
    cin >> H >> W >> Q;
    int rows = H, cols = W;
    for (int i = 0; i < Q; ++i) {
        int type, x;
        cin >> type >> x;
        if (type == 1) {
            cout << x * cols << endl;
            rows -= x;
        } else {
            cout << x * rows << endl;
            cols -= x;
        }
    }
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/