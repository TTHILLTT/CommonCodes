#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,q,a[500005],c[500005];
void add(LL x, LL k){
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
    cin>>n>>q;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
        add(i,a[i]);
    }
    while(q--){
        LL op;
        cin>>op;
        if(op==1){
            LL x;
            cin>>x;
            add(x,-a[x]);
            add(x+1,-a[x+1]);
            swap(a[x],a[x+1]);
            add(x,a[x]);
            add(x+1,a[x+1]);
        }else if(op==2){
            LL l,r;
            cin>>l>>r;
            cout<<sum(r)-sum(l-1)<<endl;
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