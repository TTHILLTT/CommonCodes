#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,q,a[500005],presum[500005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin>>n>>q;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
        presum[i]=presum[i-1]+a[i];
    }
    while(q--){
        LL op;
        cin>>op;
        if(op==1){
            LL x;
            cin>>x;
            presum[x]=presum[x-1]+a[x+1];
            swap(a[x],a[x+1]);
        }
        else if(op==2){
            LL l,r;
            cin>>l>>r;
            cout<<presum[r]-presum[l-1]<<endl;
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