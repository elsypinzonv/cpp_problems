//https://omegaup.com/arena/problem/Ancho-de-un-arbol#problems
#include <iostream>
using namespace std;

int nodoIzq[1001];
int nodoDer[1001];
int N;
int eje=0;
int maxDer[1001];
int maxIzq[1001];
int anchuramax=0;
int niv;


void procesar(int nivel){
    eje++;
    if(maxIzq[nivel]==0) maxIzq[nivel]=eje;
    maxDer[nivel]=eje;
}

void orden(int nodo, int nivel){
    int izq=nodoIzq[nodo];
    int der=nodoDer[nodo];
    if(izq!=-1) orden(izq, nivel+1);
    procesar(nivel);
    if(der!=-1)orden(der, nivel+1);
}

void buscarAnchuraMaxima(){
    int ancho;
    for(int i=1; i<=N; i++){
        ancho=maxDer[i]-maxIzq[i];
        ancho=ancho+1;
            if(ancho>anchuramax){
            anchuramax=ancho;
            niv=i;
        }
    }

}

int main(){
    cin>>N;
    int n;
    for(int i=0; i<N; i++){
        cin>>n;
        cin>>nodoIzq[n];
        cin>>nodoDer[n];
    }
    orden(1,1);
    buscarAnchuraMaxima();
    cout<<niv<<' '<<anchuramax;
}
