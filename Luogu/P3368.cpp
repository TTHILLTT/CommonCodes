#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m,a[500005],d[500005],c[500005];
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
        add(i,a[i]-a[i-1]);
    }
    while(m--){
        LL op;
        cin>>op;
        if(op==1){
            LL x,y,k;
            cin>>x>>y>>k;
            add(x,k);
            add(y+1,-k);
        }else if(op==2) {
            LL x;
            cin>>x;
            cout<<sum(x)<<endl;
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