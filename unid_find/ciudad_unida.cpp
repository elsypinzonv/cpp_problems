#include <iostream>
using namespace std;

int N,M;
int fu[2001];
int conexos[2001];


int getRaiz(int x){
    while(x!=fu[x]){
        x=fu[x];
    }
    return x;
}

bool isUnidos(int x, int y){
    return (getRaiz(x)==getRaiz(y));
}

void unir(int x, int y){
    if(!isUnidos(x,y)){
        fu[getRaiz(y)]= getRaiz(x);
    }
}

int getAristasUnidas(){
    for(int i =0; i<N; i++){
        conexos[getRaiz(i)]++;
    }
    int aristasUnidas=0;
    for(int i=0; i<N; i++){
        aristasUnidas+=(((conexos[i])*(conexos[i]-1))/2);
    }
    return aristasUnidas;
}

void solve(){
    int x,y;
    for(int i=0; i<M; i++){
        cin>>x>>y;
        unir(x,y);
    }

    cout<<((N*(N-1)/2)-getAristasUnidas())<<'\n';
}

void inicialzar(){
    for(int i=0; i<N; i++){
        fu[i]=i;
    }
}

int main(){
    cin>>N>>M;
    inicialzar();
    solve();
}
