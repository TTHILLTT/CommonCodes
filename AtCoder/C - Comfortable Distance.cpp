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
    int N, L, R;
    string S;
    cin >> N >> L >> R >> S;
    vector<vector<int>> pos(26);
    for (int i = 0; i < N; i++) {
        pos[S[i] - 'a'].push_back(i);
    }

    LL ans = 0;
    for (int i = 0; i < N; ++i) {
        int c = S[i] - 'a';
        int left = i + L;
        int right = i + R;
        auto &vec = pos[c];
        auto it1 = lower_bound(vec.begin(), vec.end(), left);
        auto it2 = upper_bound(vec.begin(), vec.end(), right);
        ans += distance(it1, it2);
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