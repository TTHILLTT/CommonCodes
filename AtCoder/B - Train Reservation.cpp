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

    int n;
    string x;
    cin >> n >> x;

    int idx = 0;
    if (x == "B") idx = 1;
    else if (x == "C") idx = 2;
    else if (x == "D") idx = 3;
    else if (x == "E") idx = 4;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s[idx] == 'o') {
            cout << "Yes" << '\n';
            return 0;
        }
    }

    cout << "No" << '\n';
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/