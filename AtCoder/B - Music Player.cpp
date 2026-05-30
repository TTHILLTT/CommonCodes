#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL Q, voice;
bool playing;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    playing=false;
    cin>>Q;
    while(Q--){
        LL o;
        cin>>o;
        if(o==1){
            voice++;
        }else if(o==2){
            voice=max(0LL,voice-1);
        }else if(o==3){
            playing=!playing;
        }
        if(playing&&voice>=3){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
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