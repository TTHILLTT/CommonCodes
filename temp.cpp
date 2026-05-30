#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> enemy;   // 邻接表
vector<int> selected;        // 当前尝试的选择
vector<int> best;            // 最优解
int bestCnt = 0;             // 最优人数

// 检查能否选第 x 个人
bool canSelect(int x) {
    for (int i = 1; i <= n; i++) {
        if (selected[i] && enemy[x][i]) {
            return false;
        }
    }
    return true;
}

void dfs(int idx, int cnt) {
    // idx 从 n 到 1 搜索，当前考虑 idx 号居民
    if (idx == 0) {
        if (cnt > bestCnt) {
            bestCnt = cnt;
            best = selected;
        }
        return;
    }

    // 剪枝：如果剩余人数 + 当前人数 <= bestCnt，不可能更优
    if (cnt + idx <= bestCnt) return;

    // 尝试选 idx
    if (canSelect(idx)) {
        selected[idx] = 1;
        dfs(idx - 1, cnt + 1);
        selected[idx] = 0;
    }

    // 尝试不选 idx
    // 但如果不选 idx，还要考虑后面能否超过 bestCnt
    if (cnt + idx - 1 > bestCnt) {
        dfs(idx - 1, cnt);
    }
}

int main() {
    cin >> n >> m;
    enemy.assign(n + 1, vector<int>(n + 1, 0));
    selected.assign(n + 1, 0);
    best.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        enemy[u][v] = 1;
        enemy[v][u] = 1;
    }

    dfs(n, 0);

    cout << bestCnt << endl;
    for (int i = 1; i <= n; i++) {
        cout << best[i] << " ";
    }
    cout << endl;

    return 0;
}