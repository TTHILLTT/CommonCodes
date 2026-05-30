#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
vector<string> a = {"1", "2", "4", "8", "16", "32", "64", "128", "256", "512"};
int main() {
    LL n;
    cin >> n;
    LL num = 1024;
    while (num <= 1e9) {
        a.push_back(to_string(num));
        num *= 2;
    }
    set<LL> st;
    queue<string> q;
    for (string s : a) {
        st.insert(stoll(s));
        q.push(s);
    }
    while (!q.empty()) {
        string cur = q.front();
        q.pop();
        for (string p : a) {
            string ncur = cur + p;
            if (ncur.size() > 10) {
                continue;
            }
            LL x = stoll(ncur);
            if (x <= 1e9 && st.count(x) == 0) {
                st.insert(x);
                q.push(ncur);
            }
        }
    }
    vector<LL> v(st.begin(), st.end());
    sort(v.begin(), v.end());
    cout << v[n - 1];
    return 0;
}
/*
=====================================================================
                              TTHILLTT                              |
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/