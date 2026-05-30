#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n, ans, a[200005], b[200005];
bool cmp(LL x, LL y) {
	return x > y;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	n *= 2;
	for (LL i = 0; i < n; i++) {
		LL x;
		cin >> x;
		b[i] = x;
		ans += x;
	}
	for (LL i = 0; i < n; i++) {
		LL c;
		cin >> c;
		a[i] = c - b[i];
	}
	sort(a, a + n, cmp);
	n /= 2;
	for (LL i = 0; i < n; i++) {
		ans += a[i];
	}
	cout << ans;
	return 0;
}