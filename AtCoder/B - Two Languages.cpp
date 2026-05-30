#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, m, q;
string s,t;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> s >> t >> q;

    set<char> takahashi(s.begin(), s.end());
    set<char> aoki(t.begin(), t.end());

    while (q--) {
        string w;
        cin >> w;
        bool only_taka = true, only_aoki = true;
        for (char c : w) {
            if (!takahashi.count(c)) {
                only_taka = false;
            }
            if (!aoki.count(c)) {
                only_aoki = false;
            }
        }
        if (only_taka && !only_aoki) {
            cout << "Takahashi\n";
        }
        else if (!only_taka && only_aoki) {
            cout << "Aoki\n";
        }
        else {
            cout << "Unknown\n";
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