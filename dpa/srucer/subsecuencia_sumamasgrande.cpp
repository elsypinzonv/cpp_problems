#include<iostream>
using namespace std;

void solve(){
    int t;
    cin>>t;
    int n,m, maxi;
    cin>>maxi;
    m=maxi;
    for(int i=1; i<t; i++){
        cin>>n;
        m=max(n,n+m);
        maxi=max(maxi,m);
    }
    cout<<maxi;
}

int main(){
    solve();
    return 0;
}
