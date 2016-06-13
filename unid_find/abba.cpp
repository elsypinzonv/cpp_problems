#include <iostream>
using namespace std;

int uf[1000256];
string cadena;
int cont;

int getRaiz(int x){
    while(uf[x]!=x){
        x=uf[x];
    }
    return x;
}

bool isUnidos(int x, int y){
    return (getRaiz(x)== getRaiz(y));
}

void unir(int x, int y){
    if(!isUnidos(x,y)){
        cont++;
        uf[getRaiz(y)]=getRaiz(x);
    }
}

void inicializar(){
    for(int i=0; i<256; i++){
        uf[i]=i;
    }
}

void solve(){
    int tope = 255+cadena.size();
    for(int i=256, j=0; j<cadena.size(); i++, j++){
        uf[i]=int(cadena[j]);
    }

    for(int i=256; i<tope; i++, tope--){
        unir(i, tope);
    }
}

int main(){
    cin>>cadena;
    inicializar();
    solve();
   cout<<cont<<'\n';
}
