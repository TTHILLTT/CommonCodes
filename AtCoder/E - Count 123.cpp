#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 998244353;
const LL G = 3;

LL modpow(LL a, LL b) {
    LL r = 1;
    while (b) {
        if (b & 1) r = r * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r;
}

void ntt(vector<LL> &a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        LL wlen = modpow(G, (MOD - 1) / len);
        if (invert) wlen = modpow(wlen, MOD - 2);
        for (int i = 0; i < n; i += len) {
            LL w = 1;
            for (int j = 0; j < len / 2; j++) {
                LL u = a[i + j];
                LL v = a[i + j + len / 2] * w % MOD;
                a[i + j] = (u + v) % MOD;
                a[i + j + len / 2] = (u - v + MOD) % MOD;
                w = w * wlen % MOD;
            }
        }
    }
    if (invert) {
        LL inv_n = modpow(n, MOD - 2);
        for (LL &x : a) x = x * inv_n % MOD;
    }
}

vector<LL> multiply(vector<LL> a, vector<LL> b) {
    int n = 1;
    while (n < (int)a.size() + (int)b.size() - 1) n <<= 1;
    a.resize(n); b.resize(n);
    ntt(a, false); ntt(b, false);
    for (int i = 0; i < n; i++) a[i] = a[i] * b[i] % MOD;
    ntt(a, true);
    return a;
}

vector<LL> fact, inv_fact;

void precompute(int n) {
    fact.resize(n + 1);
    inv_fact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
    inv_fact[n] = modpow(fact[n], MOD - 2);
    for (int i = n; i >= 1; i--) inv_fact[i - 1] = inv_fact[i] * i % MOD;
}

LL C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X1, X2, X3;
    cin >> X1 >> X2 >> X3;

    if (X2 == 0) {
        cout << ((X1 == 0 || X3 == 0) ? 1 : 0) << '\n';
        return 0;
    }
    if (X1 == 0) {
        cout << C(X2 + X3, X2) << '\n';
        return 0;
    }
    if (X3 == 0) {
        cout << C(X1 + X2, X1) << '\n';
        return 0;
    }

    precompute(X1 + X2 + X3);

    vector<LL> F(X1), Gv(X3);
    for (int a = 0; a < X1; a++)
        F[a] = C(X1 - 1, a) * inv_fact[a + 1] % MOD;
    for (int b = 0; b < X3; b++)
        Gv[b] = C(X3 - 1, b) * inv_fact[b + 1] % MOD;

    vector<LL> conv = multiply(F, Gv);
    conv.resize(X1 + X3 - 1);

    LL ans = 0;
    for (int t = 0; t < (int)conv.size(); t++) {
        LL h = conv[t] * fact[t + 2] % MOD;
        LL g = (C(X2 - 1, t) + 2 * C(X2 - 1, t + 1) + C(X2 - 1, t + 2)) % MOD;
        ans = (ans + h * g) % MOD;
    }

    cout << ans << '\n';
    return 0;
}
