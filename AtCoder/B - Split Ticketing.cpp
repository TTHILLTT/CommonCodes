#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
int main() {
    LL n;
    cin >> n;
    vector<vector<LL>> C(n, vector<LL>(n, 0));
    for (LL i = 0; i < n - 1; i++) {
        for (LL j = i + 1; j < n; j++) {
            cin >> C[i][j];
        }
    }
    for (LL a = 0; a < n - 2; a++) {
        for (LL b = a + 1; b < n - 1; b++) {
            for (LL c = b + 1; c < n; c++) {
                if (C[a][b] + C[b][c] < C[a][c]) {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
    cout << "No";
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/