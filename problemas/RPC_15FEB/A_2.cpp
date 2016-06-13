#include <iostream>
#include <cmath>
using namespace std;


void solve(){
    int t;
    long double d,x,y;
    cin>>t;
    for(int i=0; i<t; i++){
        cin>>d>>x>>y;
         long double dist= x*x + y*y;

        if(d>dist && dist!=0){
            cout<<2<<'\n';
        }else{
            cout<<ceil((long double)sqrt((long double)dist/(long double)d)) <<'\n';
        }
    }

}

int main(){
    solve();
    return 0;
}
