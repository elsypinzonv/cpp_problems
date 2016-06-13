#include <iostream>
#include <cmath>
using namespace std;

void solve(){
   int t;
   cin>>t;

    long double d,x,y;
   for(int i=0; i<t; i++){
        cin>>d>>x>>y;
        long double dist = pow(x,2)+ pow(y,2);
        long double b = (long double)(sqrt((long double)dist/(long double)d));
        if(b <1 && dist!=0){
            cout<<2<<'\n';
        } else cout<< (long double)ceil(b)<<'\n';
   }

}

int main(){
    solve();
    return 0;
}


