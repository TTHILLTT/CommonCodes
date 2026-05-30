#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
string s, t;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin >> s >> t;
    vector<pair<char, LL>> S, T;
    LL cntA = 0;
    for (char c : s) {
        if (c == 'A') {
            cntA++;
        }
        else {
            S.push_back({c, cntA});
            cntA = 0;
        }
    }
    S.push_back({'?', cntA});
    cntA = 0;
    for (char c : t) {
        if (c == 'A') {
            cntA++;
        }
        else {
            T.push_back({c, cntA});
            cntA = 0;
        }
    }
    T.push_back({'?', cntA});
    if (S.size() != T.size()) {
        cout << -1;
        return 0;
    }
    for (LL i = 0; i < S.size(); i++) {
        if (S[i].first != T[i].first) {
            cout << -1;
            return 0;
        }
    }
    LL ans = 0;
    for (LL i = 0; i < S.size(); i++) {
        ans += abs(S[i].second - T[i].second);
    }
    cout << ans << endl;
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/