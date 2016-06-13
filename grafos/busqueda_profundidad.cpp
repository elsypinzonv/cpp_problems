#include <iostream>
using namespace std;

int nodoIzq[1001];
int nodoDer[1001];
int N;


void preOrden(int nodo){
    cout<<nodo<<' ';
    int izq=nodoIzq[nodo];
    int der= nodoDer[nodo];
    if(izq!=-1) preOrden(izq);
    if(der!=-1) preOrden(der);
}

void preOrden2(int nodo){
    if(nodo!=-1){
        cout<<nodo<<' ';
        preOrden2(nodoIzq[nodo]);
        preOrden2(nodoDer[nodo]);
    }
}

void orden(int nodo){
    int izq=nodoIzq[nodo];
    int der= nodoDer[nodo];
    if(izq!=-1) orden(izq);
    cout<<nodo<<' ';
    if(der!=-1) orden(der);
}

void orden2(int nodo){
    if(nodo!=-1){
        orden2(nodoIzq[nodo]);
        cout<<nodo<<' ';
        orden2(nodoDer[nodo]);
    }
}

void postOrden(int nodo){
    int izq=nodoIzq[nodo];
    int der= nodoDer[nodo];
    if(izq!=-1) postOrden(izq);
    if(der!=-1) postOrden(der);
    cout<<nodo<<' ';
}

void postOrden2(int nodo){
    if(nodo!=-1){
        postOrden2(nodoIzq[nodo]);
        postOrden2(nodoDer[nodo]);
        cout<<nodo<<' ';
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
    cout<<"PREORDEN ";
    preOrden(0);
    cout<<'\n';
    preOrden2(0);
    cout<<'\n'<<"ORDEN ";
    orden(0);
    cout<<'\n';
    orden2(0);
    cout<<'\n'<<"POSTORDEN ";
    postOrden(0);
        cout<<'\n';
    postOrden2(0);
}
