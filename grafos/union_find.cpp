#include <iostream>
using namespace std;

int n;
int grafo[500];

void imprimir(){
    for(int i=1; i<=n; i++){
        cout<<i<<' ';
    }
    cout<<'\n';
    for(int i=1; i<=n; i++){
        cout<<grafo[i]<<' ';
    } cout<<'\n';
}

void inicializarRaices(){
    for(int i=1; i<=n; i++){
        grafo[i]=i;
    }
}

int getRaiz(int nodo){
    while(nodo!=grafo[nodo]){
        nodo=grafo[nodo];
    }
    return nodo;
}

bool isUnido(int a, int b){
    return (getRaiz(a)== getRaiz(b));
}

void unir(int a, int b){
    if(!isUnido(a,b)){
        grafo[getRaiz(a)]=getRaiz(b);
    }
}

void solve(){
    cin>>n;
    inicializarRaices();
    int a,b;
    while(true){
        cin>>a>>b;
        unir(a,b);
        imprimir();
    }
}


int main(){
    solve();
    return 0;
}
