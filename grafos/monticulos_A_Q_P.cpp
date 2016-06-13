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

void add(){
    cin>>n;
     arbol[cont]=n;
     balance();
     cont++;
}


int obtenerHijo(int nodo){

    int hijo=2*nodo;
    int hijo2=2*nodo+1;

    if(arbol[hijo]>arbol[hijo2]){
        return hijo2;
    }else return hijo;

}

void balanceAlrevez(){
    int nodo=1;
    int hijo=obtenerHijo(nodo);
    int aux;
    while(arbol[nodo]>arbol[hijo] && arbol[hijo]>0 && arbol[nodo]>0){
        aux=arbol[nodo];
        arbol[nodo]=arbol[hijo];
        arbol[hijo]=aux;
        nodo=hijo;
        hijo=obtenerHijo(nodo);
    }
}

void delet(){
    arbol[1]=arbol[cont-1];
    cont--;
    balanceAlrevez();
}

void imprimir(){
    for(int i=1; i<cont; i++){
        cout<<arbol[i]<<' ';
    }
    cout<<'\n'<<'\n';
}


void solve(){
    char a;
    while(cin>>a){
        switch(a){
            case 'A':
                add();
                break;
            case 'Q':
                delet();
                break;
            case 'P':
                cout<<arbol[1]<<'\n';
                break;
        }
        imprimir();
    }


}

int main(){
    solve();
    return 0;
}

