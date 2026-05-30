#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const LL dx[4] = {-1, 1, 0, 0};
const LL dy[4] = {0, 0, -1, 1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (LL i = 0; i < n; i++) {
        cin >> grid[i];
    }
    vector<vector<LL>> cnt(n, vector<LL>(m, 0));
    LL ori = 0;
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                LL bd = 0;
                for (LL k = 0; k < 4; k++) {
                    LL ni = i + dx[k];
                    LL nj = j + dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if (grid[ni][nj] == '#') {
                            bd++;
                        }
                    }
                }
                cnt[i][j] = bd;
                if (bd == 0) {
                    ori++;
                }
            }
        }
    }
    vector<vector<LL>> cnt2(n, vector<LL>(m, 0));
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < m; j++) {
            if (grid[i][j] == '.' && cnt[i][j] == 1) {
                for (LL k = 0; k < 4; k++) {
                    LL ni = i + dx[k];
                    LL nj = j + dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if (grid[ni][nj] == '#') {
                            cnt2[ni][nj]++;
                            break;
                        }
                    }
                }
            }
        }
    }
    LL maxx = 0;
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                LL gain = cnt2[i][j];
                bool self_can = true;
                for (LL k = 0; k < 4; k++) {
                    LL ni = i + dx[k];
                    LL nj = j + dy[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if (grid[ni][nj] == '#') {
                            self_can = false;
                            break;
                        }
                    }
                }
                if (self_can) {
                    gain++;
                }
                maxx = max(maxx, gain);
            }
        }
    }
    cout << ori + maxx;
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/