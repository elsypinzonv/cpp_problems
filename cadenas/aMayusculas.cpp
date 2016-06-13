#include <iostream>
using namespace std;

string cadena;

int convertir(int x){
    if((x>='a' && x<='z')){
        return x-32;
    }
    return x;
}

void solve(){
    for(int i=0; i< cadena.size(); i++){
        int x=convertir(int(cadena[i]));
        cadena[i]=x;
    }
    cout<<cadena<<'\n';
}

int main(){
    getline(cin,cadena);
    solve();
}

