#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
inline LL read() {
    LL s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
//      if(ch=='-')w=-1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        s = s * 10 + ch - '0', ch = getchar();
    }
    return s * w;
}
LL n, k, m, ans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    LL n = read(), k = read(), m = read();
    vector<vector<LL>> gems(n + 1);
    for (LL i = 0; i < n; i++) {
        LL c = read(), v = read();
        gems[c].push_back(v);
    }
    vector<LL> fst, scd;
    for (LL c = 1; c <= n; c++) {
        if (gems[c].empty()) {
            continue;
        }
        sort(gems[c].begin(), gems[c].end(), greater<LL>());
        fst.push_back(gems[c][0]);
        for (LL i = 1; i < gems[c].size(); i++) {
            scd.push_back(gems[c][i]);
        }
    }
    sort(fst.begin(), fst.end(), greater<LL>());
    sort(scd.begin(), scd.end(), greater<LL>());
    vector<LL> pref1(fst.size() + 1, 0), pref2(scd.size() + 1, 0);
    for (LL i = 0; i < fst.size(); i++) {
        pref1[i + 1] = pref1[i] + fst[i];
    }
    for (LL i = 0; i < scd.size(); i++) {
        pref2[i + 1] = pref2[i] + scd[i];
    }
    LL C = fst.size();
    for (LL x = max(m, (LL)(k - scd.size())); x <= min(k, C); x++) {
        ans = max(ans, pref1[x] + pref2[k - x]);
    }
    cout << ans;
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/