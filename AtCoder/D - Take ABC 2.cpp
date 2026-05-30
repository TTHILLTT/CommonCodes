#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    string S;
    cin >> S;
    queue<LL> qa, qb, qc;
    LL n = S.size();
    for (LL i = 0; i < n; i++) {
        if (S[i] == 'A') {
            qa.push(i);
        }
        else if (S[i] == 'B') {
            qb.push(i);
        }
        else {
            qc.push(i);
        }
    }
    LL ans = 0;
    while (!qa.empty() && !qb.empty() && !qc.empty()) {
        LL ia = qa.front();
        while (!qb.empty() && qb.front() < ia) {
            qb.pop();
        }
        if (qb.empty()) {
            break;
        }
        LL ib = qb.front();
        while (!qc.empty() && qc.front() < ib) {
            qc.pop();
        }
        if (qc.empty()) {
            break;
        }
        LL ic = qc.front();
        ans++;
        qa.pop();
        qb.pop();
        qc.pop();
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