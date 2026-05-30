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


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int T, tot, a[MAXN], b[MAXN], son[MAXN][2], dp[MAXN][6005], cost[MAXN];
int idx = 0;

// 递归建树，返回当前节点编号
int build() {
    int now = ++tot;
    int t, c;
    t = a[idx++];
    c = a[idx++];
    cost[now] = t;
    if (c == 0) {
        son[now][0] = build();
        son[now][1] = build();
    } else {
        b[now] = c;
    }
    return now;
}

void dfs(int u) {
    if (b[u]) {
        // 叶子节点：展室
        for (int t = 0; t <= T; t++) {
            int maxPaint = min(b[u], (t - 2 * cost[u]) / 5);
            if (t >= 2 * cost[u] + 5 && maxPaint > 0)
                dp[u][t] = maxPaint;
            else
                dp[u][t] = 0;
        }
        return;
    }
    dfs(son[u][0]);
    dfs(son[u][1]);
    for (int t = 0; t <= T; t++) {
        dp[u][t] = 0;
        // 枚举分配给左子树的时间
        for (int k = 0; k <= t - 2 * cost[u]; k++) {
            dp[u][t] = max(dp[u][t], dp[son[u][0]][k] + dp[son[u][1]][t - 2 * cost[u] - k]);
        }
    }
}

int main() {
    string line;
    getline(cin, line);
    T = stoi(line) - 1; // 留1秒逃跑
    getline(cin, line);
    stringstream ss(line);
    while (ss >> a[idx]) idx++;
    tot = 0;
    int root = build();
    dfs(root);
    cout << dp[root][T] << endl;
    return 0;
}