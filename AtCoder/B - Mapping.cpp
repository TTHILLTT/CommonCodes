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
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    int N, M;
    cin >> N >> M;
    vector<int> F(N);
    for (int i = 0; i < N; i++) {
        cin >> F[i];
    }
    set<int> s(F.begin(), F.end());
    bool q1 = (s.size() == N);
    bool q2 = true;
    for (int i = 1; i <= M; i++) {
        if (s.find(i) == s.end()) {
            q2 = false;
        }
    }
    cout << (q1 ? "Yes" : "No") << endl;
    cout << (q2 ? "Yes" : "No") << endl;
    return 0;
}
/*
=====================================================================
                             B - Mapping                            |
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/