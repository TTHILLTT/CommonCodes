#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
int digit_sum(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int N, K;
    cin >> N >> K;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (digit_sum(i) == K) ans++;
    }
    cout << ans << endl;
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           | 
                         TTHILLTT.github.io                            |
========================================================================
*/