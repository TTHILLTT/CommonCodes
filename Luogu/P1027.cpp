#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Point {
    double x, y;
};

struct City {
    Point p[4];
    double T;
};

City cities[105];
double adj[405][405];
double dists[405];
bool visited[405];

double getDist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double distSq(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void run_test_case() {
    int S, A, B;
    double t;
    if (!(cin >> S >> t >> A >> B)) return;

    for (int i = 0; i < S; ++i) {
        double x1, y1, x2, y2, x3, y3, Ti;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> Ti;
        Point p1 = {x1, y1}, p2 = {x2, y2}, p3 = {x3, y3};
        cities[i].T = Ti;
        cities[i].p[0] = p1;
        cities[i].p[1] = p2;
        cities[i].p[2] = p3;

        // 寻找第四个点：矩形中，对角线两点之和等于另外两点之和
        double d12 = distSq(p1, p2);
        double d13 = distSq(p1, p3);
        double d23 = distSq(p2, p3);

        if (d12 >= d13 && d12 >= d23) { // p1, p2 是对角线
            cities[i].p[3] = {p1.x + p2.x - p3.x, p1.y + p2.y - p3.y};
        } else if (d13 >= d12 && d13 >= d23) { // p1, p3 是对角线
            cities[i].p[3] = {p1.x + p3.x - p2.x, p1.y + p3.y - p2.y};
        } else { // p2, p3 是对角线
            cities[i].p[3] = {p2.x + p3.x - p1.x, p2.y + p3.y - p1.y};
        }
    }

    int totalNodes = 4 * S;
    // 初始化邻接矩阵
    for (int i = 0; i < totalNodes; ++i) {
        for (int j = 0; j < totalNodes; ++j) {
            adj[i][j] = (i == j) ? 0 : 1e18;
        }
    }

    // 构建城市内的铁路边 (Intra-city)
    for (int i = 0;
        i < S; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = j + 1; k < 4; ++k) {
                double weight = getDist(cities[i].p[j], cities[i].p[k]) * cities[i].T;
                adj[4 * i + j][4 * i + k] = adj[4 * i + k][4 * i + j] = weight;
            }
        }
    }

    // 构建城市间的航线 (Inter-city)
    for (int i = 0; i < S; ++i) {
        for (int j = i + 1; j < S; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    double weight = getDist(cities[i].p[k], cities[j].p[l]) * t;
                    adj[4 * i + k][4 * j + l] = adj[4 * j + l][4 * i + k] = weight;
                }
            }
        }
    }

    // Dijkstra 算法
    for (int i = 0; i < totalNodes; ++i) {
        dists[i] = 1e18;
        visited[i] = false;
    }

    // 起点是城市 A 的所有机场
    for (int i = 0; i < 4; ++i) {
        dists[4 * (A - 1) + i] = 0;
    }

    for (int count = 0; count < totalNodes; ++count) {
        int u = -1;
        for (int i = 0; i < totalNodes; ++i) {
            if (!visited[i] && (u == -1 || dists[i] < dists[u])) {
                u = i;
            }
        }

        if (u == -1 || dists[u] == 1e18) break;
        visited[u] = true;

        for (int v = 0; v < totalNodes; ++v) {
            if (!visited[v] && adj[u][v] < 1e17) {
                if (dists[v] > dists[u] + adj[u][v]) {
                    dists[v] = dists[u] + adj[u][v];
                }
            }
        }
    }

    // 终点是城市 B 的所有机场中的最小值
    double ans = 1e18;
    for (int i = 0; i < 4; ++i) {
        ans = min(ans, dists[4 * (B - 1) + i]);
    }

    cout << fixed << setprecision(1) << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    if (!(cin >> n)) return 0;
    while (n--) {
        run_test_case();
    }
    return 0;
}

//AI TESTING