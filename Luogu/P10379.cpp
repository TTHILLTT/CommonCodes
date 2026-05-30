#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLLLL;
LL n, m, mp[505][505], sx, sy;
vector<PLLLL> e;
set<vector<PLLLL>> st;
void dfs(LL ini, LL x, LL y) {
    e.push_back({x - sx, y - sy});
    mp[x][y] = 0;
    if (mp[x - 1][y] == ini) {
        dfs(ini, x - 1, y);
    }
    if (mp[x + 1][y] == ini) {
        dfs(ini, x + 1, y);
    }
    if (mp[x][y - 1] == ini) {
        dfs(ini, x, y - 1);
    }
    if (mp[x][y + 1] == ini) {
        dfs(ini, x, y + 1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin >> n >> m;
    for (LL i = 1; i <= n; i++) {
        for (LL j = 1; j <= m; j++) {
            cin >> mp[i][j];
        }
    }
    for (LL i = 1; i <= n; i++) {
        for (LL j = 1; j <= m; j++) {
            if (mp[i][j] != 0) {
                sx = i;
                sy = j;
                dfs(mp[i][j], i, j);
                st.insert(e);
                e.clear();
            }
        }
    }
    cout << st.size();
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/