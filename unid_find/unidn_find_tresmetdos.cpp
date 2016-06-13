#include <iostream>
using namespace std;

int nodos,uniones,preguntas;
int uf[10000];


void inicialzar(){
    for(int i=0; i<n; i++){
        uf[i]=i;
    }
}

int getRaiz(int x){
    while(x!=uf[x]){
        x=uf[x];
    }
    return x;
}

bool isUnida(int x, int y){
    return (getRaiz(x) == getRaiz(y));
}

void unir(int x, int y){
    if(!isUnida(x,y)){
        uf[getRaiz(y)]=getRaiz(x);
    }
}
