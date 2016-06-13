#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct nodo{
    int x;
    int peso;
};

struct arista{
    int a;
    int b;
    int peso;
};

bool operator<(arista a, arista b){
    return a.peso > b.peso;
}

int N,A;
vector<nodo> grafo[500];
vector<nodo> arbol[500];
priority_queue<arista> pq;

queue<int> cola;
int marcas[500];
int cont=1;

void addHijos(int padre){
    nodo hijo;
    for(int i=0; i<arbol[padre].size(); i++){
       hijo= arbol[padre][i];
        if(marcas[hijo.x]!=cont){
            cola.push(hijo.x);
        }
    }

}

bool amplitud(int a, int b){
    cola.push(a);
    int padre;
    while(!cola.empty()){
        padre=cola.front();
        marcas[padre]=cont;
        addHijos(padre);
        cola.pop();
    }
    cont++;

    return (marcas[b]== marcas[a]);
}

void kruskal(){
    arista ar;
    while(!pq.empty()){
        ar=pq.top();
        if(!amplitud(ar.a, ar.b)){
            arbol[ar.a].push_back({ar.b,ar.peso});
            arbol[ar.b].push_back({ar.a,ar.peso});
       }
        pq.pop();
    }

}

void addGrafo(int a, int b, int peso){
    grafo[a].push_back({b,peso});
    grafo[b].push_back({a,peso});
    pq.push({a,b,peso});
}

void sumar(){
    int suma=0;
    for(int i=1; i<=N; i++){
        for(int j=0; j<arbol[i].size(); j++){
             suma+=arbol[i][j].peso;
        }
    }
    suma=suma/2;
    cout<<suma<<'\n';
}

void solve(){
    cin>>N>>A;
    int a,b,peso;
    for(int i=0; i<A; i++){
        cin>>a>>b>>peso;
        addGrafo(a,b,peso);
    }
    kruskal();
    sumar();
}

int main(){
    solve();
    return 0;
}
