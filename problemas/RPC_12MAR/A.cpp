#include<iostream>
using namespace std;

int tt,tb,st,sb,ta;
void solve(){
    int n,b,t;
    while(cin>>n){
        cin>>b>>t;
        tt=tb=st=sb=0;
        ta=n;
        while(st+sb!=n){
            if(tb==0 && tt==0){
                tb=min(ta,b);
                ta=max(0,ta-b);
                tt=min(ta,t);
                ta=max(0,ta-t);
            }else{

                if(tb==0){
                    tb=min(ta,b);
                    ta=max(0,ta-b);
                    tt--;
                    st++;
                }else{
                    if(tt==0){
                        tt=min(ta,t);
                        ta=max(0,ta-t);
                        tb--;
                        sb++;
                    }else{
                        tt--;
                        tb--;
                        sb++;
                        st++;
                    }
                }

            }
        } cout<<sb<<' '<<st<<'\n';
    }
}


int main(){
    solve();

    return 0;
}
