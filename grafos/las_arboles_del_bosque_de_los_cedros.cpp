#include <iostream>
#include <vector>
using namespace std;

int n;
int nodoIzq[10001];
int nodoDer[10001];
int nodoRaiz[10001];
int cont=1;
vector<int> nums;

void arbol(int nod){
    nodoRaiz[cont]=nod;
    nodoDer[cont]=-1;
    nodoIzq[cont]=-1;
    int i=0;
    int raiz=nodoRaiz[i];
    while(true){
        if(nod>=raiz){
            if(nodoDer[i]==-1){
                nodoDer[i]=cont;
                break;
            }else {
                i=nodoDer[i];
                raiz=nodoRaiz[i];
            }
        }else{
            if(nodoIzq[i]==-1){
                nodoIzq[i]=cont;
                break;
            }else{
                i=nodoIzq[i];
                raiz=nodoRaiz[i];
            }
        }
    }
    cont++;
}

void orden(int nodo){
    int raiz= nodoRaiz[nodo];
    if(raiz >0){
        orden(nodoIzq[nodo]);
        if(nodoIzq[nodo]==-1 && nodoDer[nodo]==-1) nums.push_back(raiz);
        orden(nodoDer[nodo]);
    }
}

int main(){
    cin>>n;
    int nodo;
    for(int i=0; i<n; i++){
        cin>>nodo;
        if(i!=0){
          arbol(nodo);
        }else{
            nodoRaiz[0]=nodo;
            nodoDer[0]=-1;
            nodoIzq[0]=-1;
        }
    }

    orden(0);
    cout<<nums.size()<<"\n";
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<' ';
    }cout<<'\n';
}
