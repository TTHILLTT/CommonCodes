#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n;
map<LL, bool>mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin >> n;
    vector<LL>r;
    r.push_back(0);
    r.push_back(1);
    mp[1] = true;
    for (LL i = 2; i <= n; i++) {
        if (r[i - 1] - i > 0 && mp[r[i - 1] - i] == false) {
            r.push_back(r[i - 1] - i);
            mp[r[i - 1] - i] = true;
        }
        else {
            r.push_back(r[i - 1] + i);
            mp[r[i - 1] + i] = true;
        }
    }
    sort(r.begin(), r.end());
    for (LL i = 1; i <= n; i++) {
        cout << r[i] << " ";
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