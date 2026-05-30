#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    vector<LL> a(n);
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<LL> uniq;
    uniq.push_back(a[0]);
    for (LL i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            uniq.push_back(a[i]);
        }   
    }
    LL maxx = 1, cur = 1;
    for (LL i = 1; i < uniq.size(); i++) {
        if (uniq[i] == uniq[i - 1] + 1) {
            cur++;
        } else {
            cur = 1;
        }
        maxx = max(maxx, cur);
    }
    cout << maxx;
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/