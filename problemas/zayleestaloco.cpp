#include <iostream>
using namespace std;

void solve(){
    string palabra;
    cin>>palabra;
    for(int i=0; i<palabra.size(); i++){
        for(int j=i; j<palabra.size(); j++){
            cout<<palabra[j];
        }
        for(int j=0; j<i; j++){
            cout<<palabra[j];
        }cout<<'\n';
    }
}

int main(){
    solve();
    return 0;
}
