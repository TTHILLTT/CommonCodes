#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
const LL N = 505, M = 305;
char a[N][N];
LL n, m, x, f[2][N][M];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    cout.tie(nullptr);
	LL T;
	cin >> T;
	while (T--) {
		cin >> n >> m >> x;
		for (LL i = 1; i <= n; i++){
            for (LL j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
		memset(f, 0, sizeof f);
		for (LL i = 1; i <= n; i++) {
			for (LL j = 0; j <= m; j++)
				for (LL k = 0; k <= x; k++)
					f[i & 1][j][k] = 0;
			for (LL j = 1; j <= m; j++) {
				for (LL k = 0; k <= x; k++) {
					if (a[i][j] == '?') {
						if (k) {
							f[i & 1][j][k] = max(
								max(f[(i - 1) & 1][j][k], f[i & 1][j - 1][k]),
								max(f[(i - 1) & 1][j][k - 1], f[i & 1][j - 1][k - 1]) + 1
							);
						} else {
							f[i & 1][j][k] = max(f[(i - 1) & 1][j][k], f[i & 1][j - 1][k]);
						}
					} else {
						f[i & 1][j][k] = max(f[(i - 1) & 1][j][k], f[i & 1][j - 1][k]) + (a[i][j] == '1');
					}
				}
			}
		}
		cout << f[n & 1][m][x] << endl;
	}
	return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           | 
                         TTHILLTT.github.io                            |
========================================================================
*/