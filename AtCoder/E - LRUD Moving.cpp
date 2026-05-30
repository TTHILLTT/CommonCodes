#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
char dir[4] = {'L', 'R', 'U', 'D'};
LL n, a, b;
bool found = false;
vector<vector<bool>> vis;
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
struct state {
    LL x, y, step;
    string theWayOf;
    vector<vector<bool>> vis;
};
// bool dfs(LL x, LL y, LL step, LL tgtX, LL tgtY, LL tot, string theWayOf) {
//     if (found) {
//         return true;
//     }
//     if (x == tgtX && y == tgtY) {
//         if (step == tot) {
//             ans.push_back(theWayOf);
//             found = true;
//             return true;
//         }
//         return false;
//     }
//     for (LL i = 0; i < 4; i++) {
//         LL nowX = x + dx[i], nowY = y + dy[i];
//         if (nowX < 1 || nowX > n || nowY < 1 || nowY > n || vis[nowX][nowY]) {
//             continue;
//         }
//         vis[nowX][nowY] = true;
//         theWayOf.push_back(dir[i]);
//         if (dfs(nowX, nowY, step + 1, tgtX, tgtY, tot, theWayOf)) {
//             return true;
//         }
//         theWayOf.pop_back();
//         vis[nowX][nowY] = false;
//     }
//     return false;
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    LL T;
    cin >> T;
    while (T--) {
        cin >> n >> a >> b;
        vector<vector<bool>> vis(n + 5, vector<bool>(n + 5, false));
        vis[a][b] = true;
        vis[1][1] = true;
        queue<state> q;
        q.push({1, 1, 1, "", vis});
        bool found = false;
        string ans = "";
        while (!q.empty() && !found) {
            state cur = q.front();
            q.pop();
            if (cur.x == n && cur.y == n) {
                if (cur.step == n * n - 1) {
                    ans = cur.theWayOf;
                    found = true;
                    break;
                }
                continue;
            }
            for (LL i = 0; i < 4; i++) {
                LL nx = cur.x + dx[i], ny = cur.y + dy[i];
                if (nx < 1 || nx > n || ny < 1 || ny > n) {
                    continue;
                }
                if (cur.vis[nx][ny]) {
                    continue;
                }
                vector<vector<bool>> newVis = cur.vis;
                newVis[nx][ny] = true;
                q.push({nx, ny, cur.step + 1, cur.theWayOf + dir[i], newVis});
            }
        }
        if (found) {
            cout << "Yes" << endl << ans << endl;
        } else {
            cout << "No" << endl;
        }
        // dfs(1, 1, 1, n, n, n * n - 1, "");
    }
    return 0;
}
/*
=====================================================================
                          E - LRUD Moving                           |
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/