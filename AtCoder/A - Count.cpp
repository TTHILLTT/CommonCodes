#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin>>s;
    LL cnt=0;
    for(LL i=0;i<s.size();i++){
        if(s[i]=='i'||s[i]=='j'){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           | 
                         TTHILLTT.github.io                            |
========================================================================
*/