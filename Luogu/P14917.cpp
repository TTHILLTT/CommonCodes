#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n, a, maxx = 0, maxxx = 0, ans = 0;
int main() {
    cin >> n;
    for (LL i = 0; i < n; i++) {
        cin >> a;
        if (a == maxx) {
            ans = max(ans, maxxx);
            maxx = 0;
            maxxx = 0;      
        }
        else if (a > maxx) {
            maxxx = maxx;
            maxx = a;
        }
        else if (a > maxxx) {
            maxxx = a;
        }
    }
    cout << ans;
    return 0;
}

/*
========================================================================
                        Programed by KaoXiqi                           |
                         TTHILLTT.github.io                            |
                    Powered by Visual Studio Code                      |
========================================================================
*/