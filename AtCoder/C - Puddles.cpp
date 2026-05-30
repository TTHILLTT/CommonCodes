#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL h, w;
vector<string> S;
vector<vector<bool>> vis;
LL dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
bool is_border(LL x, LL y) {
    return x == 0 || x == h - 1 || y == 0 || y == w - 1;
}
void bfs(LL sx, LL sy, bool &bd) {
    queue<pair<LL, LL>> q;
    q.push({sx, sy});
    vis[sx][sy] = true;
    if (is_border(sx, sy)) {
        bd = true;
    }
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (LL d = 0; d < 4; d++) {
            LL nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                continue;
            }
            if (S[nx][ny] == '.' && !vis[nx][ny]) {
                vis[nx][ny] = true;
                if (is_border(nx, ny)) bd = true;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    cin >> h >> w;
    S.resize(h);
    for (LL i = 0; i < h; i++) {
        cin >> S[i];
    }
    vis.assign(h, vector<bool>(w, false));
    LL ans = 0;
    for (LL i = 0; i < h; i++) {
        for (LL j = 0; j < w; j++) {
            if (S[i][j] == '.' && !vis[i][j]) {
                bool bd = false;
                bfs(i, j, bd);
                if (!bd) {
                    ans++;
                }
            }
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