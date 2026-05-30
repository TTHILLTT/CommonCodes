#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL h,w;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // freopen(".in","r",stdin);
    // freopen(".out","w",stdout);
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(i==0||i==h-1||j==0||j==w-1) cout<<"#";
            else cout<<".";
        }
        cout<<endl;
    }
    return 0;
}
/*
=====================================================================
                              TTHILLTT                              |
                         TTHILLTT.github.io                         |
                         Visual Studio Code                         |
=====================================================================
*/