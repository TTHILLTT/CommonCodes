#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<LL> a(n);
    LL max1 = -0x3f3f3f3f3f3f3f3f, max2 = -0x3f3f3f3f3f3f3f3f, cnt = 0;
    for (auto& i : a) {
        cin >> i;
        if (i > max1) {
            max2 = max1;
            max1 = i;
            cnt = 1;
        } else if (i == max1) {
            cnt++;
        } else if (i > max2) {
            max2 = i;
        }
    }
    for (LL i = 0; i < n; i++) {
        if (a[i] == max1) {
            if (cnt > 1) {
                cout << max1;
            } else {
                cout << max2;
            }
        } else {
            cout << max1;
        }
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/