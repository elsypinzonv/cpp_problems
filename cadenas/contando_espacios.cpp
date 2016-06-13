#include <iostream>
using namespace std;

string cadena;
int cont;
void solve(){
    cont=0;
    for(int i=0; i<cadena.size(); i++){
        if(cadena[i]==' ') cont++;
    }
    cout<<cont<<'\n';
}

int main(){
    while(getline(cin,cadena)){
            solve();
    }
}
