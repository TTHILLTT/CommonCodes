#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[500005],c[500005];
void add(LL x,LL k){
    while(x<=n){
        c[x]+=k;
        x+=x&-x;
    }
}
LL sum(LL x){
    LL res=0;
    while(x>0){
        res+=c[x];
        x-=x&-x;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin>>n>>m;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
        add(i,a[i]);
    }
    while(m--){
        LL op,x,y;
        cin>>op>>x>>y;
        if(op==1){
            add(x,y);
        }
        else if(op==2){
            cout<<sum(y)-sum(x-1)<<endl;
        }
    }
    return 0;
}
/*
========================================================================
                        Programed by KaoXiqi                           | 
                         TTHILLTT.github.io                            |
========================================================================
*/