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
    LL X, Q;
    cin >> X >> Q;
    priority_queue<LL> left;
    priority_queue<LL, vector<LL>, greater<LL>> right;
    left.push(X);
    for (LL i = 1; i <= Q; i++) {
        LL A, B;
        cin >> A >> B;
        for (LL v : {A, B}) {
            if (v <= left.top())
                left.push(v);
            else
                right.push(v);
        }
        LL k = i + 1;
        while ((LL)left.size() > k) {
            right.push(left.top());
            left.pop();
        }
        while ((LL)left.size() < k) {
            left.push(right.top());
            right.pop();
        }
        cout << left.top() << endl;
    }
    return 0;
}
