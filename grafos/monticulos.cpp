#include <iostream>
using namespace std;


int arbol[500];
int n;
int cont=1;

void balance(){
    int aux;
    int nodo=cont;
    int padre= nodo/2;
    while(arbol[padre]>arbol[nodo] && padre>0 && nodo>0){
        aux=arbol[padre];
        arbol[padre]=arbol[nodo];
        arbol[nodo]=aux;
        nodo=padre;
        padre=nodo/2;
    }
}

void solve(){
    while(cin>>n){
        arbol[cont]=n;
        balance();
        cont++;
        cout<<arbol[1]<<'\n';
    }


}

int main(){
    solve();
    return 0;
}
