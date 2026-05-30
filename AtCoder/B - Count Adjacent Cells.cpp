#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
inline LL read() {
    LL s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        s = s * 10 + ch - '0', ch = getchar();
    }
    return s * w;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int H = read(), W = read();

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            int cnt = 0;
            if (i > 1) cnt++;
            if (i < H) cnt++;
            if (j > 1) cnt++;
            if (j < W) cnt++;
            cout << cnt;
            if (j < W) cout << ' ';
        }
        cout << endl;
    }

    return 0;
}
