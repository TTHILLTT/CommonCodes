#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n, ans, h[200005];
bool check(LL E){
    LL e = E, ht = 0;
    for(LL i = 0; i < n; i++){
        if(h[i] >= ht){
            LL need = h[i] - ht;
            if(e < need) return false;
            e -= need;
        }else{
            LL gain = ht - h[i];
            e += gain;
            if(e > E) e = E;
        }
        ht = h[i];
    }
    return true;
}
int main() {
    cin >> n;
    for (LL i = 0; i < n; i++) {    
        cin >> h[i];
    }
    LL maxE = *max_element(h, h + n), ans = maxE;
    LL left = 0, right = maxE;
    while (left <= right) {
        LL mid = left + (right - left) / 2;
        if (check(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ans;
    return 0;
}