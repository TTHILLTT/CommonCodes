#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string add(string a, string b) {
    string res;
    LL i = a.size() - 1, j = b.size() - 1, cr = 0;
    while (i >= 0 || j >= 0 || cr) {
        LL x = (i >= 0 ? a[i--] - '0' : 0);
        LL y = (j >= 0 ? b[j--] - '0' : 0);
        LL sum = x + y + cr;
        res.push_back(sum % 10 + '0');
        cr = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
string sub(string a, string b) {
    string res;
    LL i = a.size() - 1, j = b.size() - 1, br = 0;
    while (i >= 0) {
        LL x = a[i] - '0' - br;
        LL y = (j >= 0 ? b[j--] - '0' : 0);
        if (x < y) {
            x += 10;
            br = 1;
        }
        else {
            br = 0;
        }
        res.push_back(x - y + '0');
        i--;
    }
    while (res.size() > 1 && res.back() == '0') {
        res.pop_back();
    }
    reverse(res.begin(), res.end());
    return res;
}
string div9(const string &a) {
    string res;
    LL cr = 0;
    for (char c : a) {
        LL cur = cr * 10 + (c - '0');
        res.push_back(cur / 9 + '0');
        cr = cur % 9;
    }
    while (res.size() > 1 && res[0] == '0') {
        res.erase(res.begin());
    }
    return res;
}
string initStr(LL n) {
    string res = "1";
    for (LL i = 0; i < n; i++) {
        res.push_back('0');
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    LL n;
    cin >> n;
    vector<LL> a(n);
    for(auto& i : a){
        cin>>i;
    }
    string ans = "0";
    for (auto i : a) {
        string tenPow = initStr(i);     // 10^i
        string tmp = sub(tenPow, "1");  // 10^i - 1
        tmp = div9(tmp);                // (10^i - 1)/9
        ans = add(ans, tmp);
    }
    cout << ans;
    return 0;
}

/*
========================================================================
                        Programed by KaoXiqi                           | 
                         TTHILLTT.github.io                            |
========================================================================
*/