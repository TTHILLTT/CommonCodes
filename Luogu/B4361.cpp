#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
struct St {
    LL h, w, idx;
};
bool cmp(const St &a, const St &b) {
    if (a.h != b.h) return a.h > b.h;
    return a.w > b.w;
}
int main() {
    LL n;
    cin >> n;
    vector<St> stu(n);
    for (LL i = 0; i < n; i++) {
        cin >> stu[i].h >> stu[i].w;
        stu[i].idx = i;
    }
    vector<St> target = stu;
    sort(target.begin(), target.end(), cmp);
    vector<LL> cur(n), tgt(n);
    for (LL i = 0; i < n; i++) {
        cur[i] = i;
    }
    for (LL i = 0; i < n; i++) {
        tgt[i] = target[i].idx;
    }
    LL ans = 0;
    for (LL i = 0; i < n; i++) {
        for (LL j = 0; j < n - i - 1; j++) {
            if (cur[j] != tgt[j]) {
                LL pos;
                for (LL k = j; k < n; k++) {
                    if (cur[k] == tgt[j]) {
                        pos = k;
                        break;
                    }
                }
                while (pos > j) {
                    swap(cur[pos], cur[pos - 1]);
                    ans++;
                    pos--;
                }
            }
        }
    }
    cout << ans;
    return 0;
}