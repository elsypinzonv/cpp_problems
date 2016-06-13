#include <iostream>
using namespace std;


int cont[123];
int k;
string cadena;
string sub="";

void crearCadena(int caracter, int n){
    for(int i=0; i<n; i++){
        sub+=char(caracter);
    }

}

void contar(){
    for(int i=0; i<cadena.size(); i++){
        cont[int(cadena[i])]++;
    }
}

bool validar(){
    for(int i=97; i<123; i++){
        if(cont[i]%k==0){
            crearCadena(i,cont[i]/k);
        }else return false;
    }
    return true;
}

string cadenar(){
    string cad="";
    for(int i=0; i<k; i++){
        cad+=sub;
    }
    return cad;
}

void solve(){
    if(cadena.size()%k==0){
        contar();
        if(validar()){
            cout<<cadenar()<<'\n';
        }else cout<<(-1)<<'\n';
    }else cout<<(-1)<<'\n';
}

int main(){
    cin>>k>>cadena;
    solve();
}
