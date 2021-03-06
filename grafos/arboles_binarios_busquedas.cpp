#include <iostream>
using namespace std;

int n;
int nodoIzq[1001];
int nodoDer[1001];
int nodoRaiz[1001];
int nums[1001];
int cont=1;

void arbol(int nodo){
    nodoRaiz[cont]=nodo;
    nodoDer[cont]=-1;
    nodoIzq[cont]=-1;
    int j=0;
    while(true){
        if(nodo>=nodoRaiz[j]){
            if(nodoDer[j]==-1){
                nodoDer[j]=cont;
                break;
            }else j=nodoDer[j];

        }else{

            if(nodoIzq[j]==-1){
                nodoIzq[j]=cont;
                break;
            }else j=nodoIzq[j];

        }
    }

    cont++;

}

void preOrden(int i){

    if(nodoRaiz[i]>0){
        cout<<nodoRaiz[i]<<' ';
        preOrden(nodoIzq[i]);
        preOrden(nodoDer[i]);
    }

}

void solve(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    for(int i=n-1; i>=0; i--){
        if(i==n-1){
            nodoRaiz[0]=nums[n-1];
            nodoDer[0]=-1;
            nodoIzq[0]=-1;
        }else arbol(nums[i]);
    }

    preOrden(0);
}

int main(){
    solve();
    return 0;
}
