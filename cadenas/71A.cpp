#include <iostream>
using namespace std;

string cadena;
int n;

void contar(){

}

void solve(){
    for(int i=0; i<n; i++){
        cin>>cadena;
        if(cadena.size()>10) {
            cout<<cadena[0]<<cadena.size()-2<<cadena[cadena.size()-1]<<'\n';
        }else cout<<cadena<<'\n';
    }
}

int main(){
    cin>>n;
    solve();
    return 0;
}
