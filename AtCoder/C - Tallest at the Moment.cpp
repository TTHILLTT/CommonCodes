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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<int> H(N), L(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i] >> L[i];
    }
    vector<int> sufMax(N + 1, 0);
    for (int i = N - 1; i >= 0; i--) {
        sufMax[i] = max(sufMax[i + 1], H[i]);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int T;
        cin >> T;
        int need = T + 1;
        int idx = lower_bound(L.begin(), L.end(), need) - L.begin();
        cout << sufMax[idx] << '\n';
    }
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/