#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    ll S = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        S += A[i];
    }

    vector<ll> ans;
    vector<ll> divisors;
    for (ll i = 1; i * i <= S; ++i) {
        if (S % i == 0) {
            divisors.push_back(i);
            if (i != S / i) divisors.push_back(S / i);
        }
    }
    sort(divisors.begin(), divisors.end());

    for (ll L : divisors) {
        ll sum = 0;
        bool ok = true;
        for (int i = 0; i < N; ++i) {
            sum += A[i];
            if (sum > L) { ok = false; break; }
            if (sum == L) sum = 0;
        }
        if (ok && sum == 0) ans.push_back(L);
    }

    for (ll i = 0; i < ans.size(); ++i) {
        if (i) cout << " ";
        cout << ans[i];
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