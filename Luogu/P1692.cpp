#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 105;
int n, m;
bitset<MAXN> enemy[MAXN];  // adjacency matrix: enemy[i][j] = 1 means i,j are enemies
int cur[MAXN];             // current selection
int best[MAXN];            // best solution found
int bestCnt = 0;           // size of best solution

void dfs(int idx, int cnt) {
    // Pruning: even if we select ALL remaining vertices, can't beat best
    if (cnt + n - idx + 1 <= bestCnt) return;

    if (idx > n) {
        // First solution of each size is lexicographically largest
        // (DFS tries select=1 before not-select=0, so visits in lexicographic order)
        // Therefore cnt > bestCnt (not >=) is correct
        if (cnt > bestCnt) {
            bestCnt = cnt;
            copy(cur, cur + MAXN, best);
        }
        return;
    }

    // Try to select vertex idx
    // Only need to check conflicts with already-selected vertices (1..idx-1)
    bool can = true;
    for (int i = 1; i < idx && can; ++i) {
        if (cur[i] && enemy[idx][i]) can = false;
    }

    if (can) {
        cur[idx] = 1;
        dfs(idx + 1, cnt + 1);
        cur[idx] = 0;
    }

    // Try not to select vertex idx
    dfs(idx + 1, cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        enemy[u].set(v);
        enemy[v].set(u);
    }

    dfs(1, 0);

    cout << bestCnt << endl;
    for (int i = 1; i <= n; ++i) {
        cout << best[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
