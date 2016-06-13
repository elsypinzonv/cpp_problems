#include <iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

int n;

void fibo(int a, int b){
    for(int i=a+1; i<b; i++){
        if(i<n) cout<<i<<" ";
    }
    if(b<n) fibo(b,a+b);
}

void solve(){
    cin>>n;
    fibo(1,1);
    cout<<'\n';
}

int main(){
    optimizar_io
    solve();
    return 0;
}
