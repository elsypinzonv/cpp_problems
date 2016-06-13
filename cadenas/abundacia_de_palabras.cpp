#include <iostream>
using namespace std;

int l=14;
string cadena;
int cont;

void solve(){
    while(cin>>cadena){
        cont+=(cadena.size()/l);
    }
    cout<<cont<<'\n';
}

int main(){
    solve();
    return 0;
}
