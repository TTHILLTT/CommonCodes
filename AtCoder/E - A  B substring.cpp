#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;

    LL ans = 0;
    for (int l = 0; l < N; ++l) {
        int cntA = 0, cntB = 0;
        for (int r = l; r < N; ++r) {
            if (S[r] == 'A') cntA++;
            else if (S[r] == 'B') cntB++;
            if (cntA > cntB) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           | 
                         TTHILLTT.github.io                            |
========================================================================
*/