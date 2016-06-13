#include <iostream>
using namespace std;

int nodos, uniones,preguntas;
int uf[100000];

void inicialzar(){
    for(int i=1; i<=nodos; i++){
        uf[i]=i;
    }
}

int getRaiz(int x){
    while(x!= uf[x]){
         x=uf[x];
    }
    return x;
}

bool isUnida(int x, int y){
    return (getRaiz(x)==getRaiz(y));
}


void unir(int x,int y){
    if(!isUnida(x,y)){
        uf[getRaiz(y)]=getRaiz(x);
    }
}

void solve(){
    int x,y;
    for(int i=0; i<uniones; i++){
        cin>>x>>y;
        unir(x,y);
    }

    for(int i=0; i<preguntas; i++){
        cin>>x>>y;
        if(isUnida(x,y)){
            cout<<"SI"<<'\n';
        }else cout<<"NO"<<'\n';
    }

}

int main(){
    cin>>nodos>>uniones>>preguntas;
    inicialzar();
    solve();
}
