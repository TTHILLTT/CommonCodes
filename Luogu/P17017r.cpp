#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;

const LL MOD = 1000000007;  // 1e9 + 7
const int MAXN = 2005;      // N ≤ 1000, a_i ≤ 1001, leave some margin

LL fact[MAXN], inv_fact[MAXN];

// 快速幂：计算 a^b mod MOD （费马小定理求逆元用）
LL qpow(LL a, LL b) {
    LL res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// 预处理阶乘和阶乘逆元
void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    // 费马小定理：inv_fact[n] = fact[n]^(MOD-2) mod MOD
    inv_fact[MAXN - 1] = qpow(fact[MAXN - 1], MOD - 2);
    for (int i = MAXN - 1; i >= 1; i--) {
        inv_fact[i - 1] = inv_fact[i] * i % MOD;
    }
}

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        LL sum = 0;
        LL prod_inv = 1;  // Π inv_fact[a_i]
        for (int i = 0; i < M; i++) {
            int a;
            cin >> a;
            sum += a;
            prod_inv = prod_inv * inv_fact[a] % MOD;
        }
        LL ans = fact[N] * prod_inv % MOD;
        if (sum == N + 1) {
            ans = ans * (N + 1) % MOD;
        }
        // sum == N 时不需要额外乘
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    precompute();
    solve();
    return 0;
}
/*
=====================================================================
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/