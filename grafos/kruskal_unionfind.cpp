#include <iostream>
#include <queue>
#include <vector>

struct nodo{
    int x;
    int p;
};

struct arista{
    int a;
    int b;
    int p;
};

bool operator<(arista a, arista b){
    return a.p > b.p;
}

using namespace std;
vector<nodo> grafo[500];
priority_queue<arista> pq;
int arbol[500];
int N;
int suma=0;

void inicializarRaices(){
    for(int i=0; i<N; i++){
        arbol[i] = i;
    }
}

int getRaiz(int nod){
    while(arbol[nod] != nod){
        nod = arbol[nod];
    }
    return nod;
}

bool isUnido(arista edge){
    return (getRaiz(edge.a) == getRaiz(edge.b));
}

void kruskal(){
    arista edge;
    while(!pq.empty()){
        edge = pq.top();
        if(!isUnido(edge)){
            arbol[getRaiz(edge.a)]= getRaiz(edge.b);
            suma+=edge.p;
        }
        pq.pop();
    }
}

void solve(){
    int A;
    cin>>N>>A;
    int c,d,p;
    for(int i=0;i<A; i++){
        cin>>c>>d>>p;
        grafo[c].push_back({d,p});
        grafo[d].push_back({c,p});
        pq.push({c,d,p});
    }
    inicializarRaices();
    kruskal();
    cout<<suma<<'\n';
}

int main(){
    solve();
    return 0;
}


