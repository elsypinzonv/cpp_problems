#include <iostream>
using namespace std;

int n,k,u;
int uf[100000];


void inicialzar(){
    for(int i=1; i<=n; i++){
        uf[i]=i;
    }
}

bool isUnidos(int x, int y){
    return (uf[x]== uf[y]);
}

void une(int x,int y){
    int valor = uf[y];
    if(!isUnidos(x,y)){
        for(int i=1; i<=n; i++){
            if(uf[i]==valor) uf[i]=uf[x];
        }
    }
}

void solve(){
    int x,y;
    for(int i=0; i<u; i++){
        cin>>x>>y;
        une(x,y);
    }

    for(int i=0; i<k; i++){
        cin>>x>>y;
        if(isUnidos(x,y)){
            cout<<"SI"<<'\n';
        } else cout<<"NO"<<'\n';
    }

}

int main(){
    cin>>n>>k>>u;
    inicialzar();
    solve();
}
