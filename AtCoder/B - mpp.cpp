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
    string s;
    cin >> s;
    unordered_map<char, LL> freq;
    for (char c : s) {
        freq[c]++;
    }
    LL maxFreq = 0;
    for (auto &p : freq) {
        maxFreq = max(maxFreq, p.second);
    }
    vector<char> toRemove;
    for (auto &p : freq) {
        if (p.second == maxFreq) {
            toRemove.push_back(p.first);
        }
    }
    string ans;
    for (char c : s) {
        bool remove = false;
        for (char r : toRemove)
            if (c == r) {
                remove = true;
                break;
            }
        if (!remove) {
            ans += c;
        }
    }
    cout << ans;
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/