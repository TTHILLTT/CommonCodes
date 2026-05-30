#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin >> n;
    vector<vector<LL>> mat(n, vector<LL>(n));
    LL sMaxx = n * n / 2;
    LL lS = sMaxx + 1;
    LL small = 1, large = lS;
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < n; j++) {
            if ((i + j) % 2 == 0) {
                mat[i][j] = large;
                large++;
            } else {
                mat[i][j] = small;
                small++;
            }
        }
    }
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < n; j++) {
            cout << mat[i][j];
            if (j < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
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