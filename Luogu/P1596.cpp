#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int N, M;
vector<string> grid;
void dfs(int x, int y) {
    grid[x][y] = '.';
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && grid[nx][ny] == 'W') {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> N >> M;
    grid.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }
    int ponds = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] == 'W') {
                ++ponds;
                dfs(i, j);
            }
        }
    }
    cout << ponds;
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/