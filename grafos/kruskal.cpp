#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int cont;

struct arista{
    int a;
    int b;
    int p;
};

struct nodo{
    int x;
    int p;
};

bool operator<(arista a, arista b){
    return a.p > b.p;
}

vector<nodo> grafo[500];
vector<nodo> arbol[500];
priority_queue<arista> pq;
queue<int> cola;
int marcas[500];



void addHijos(int nod){
    nodo hijo;
    for(int i=0; i<arbol[nod].size(); i++){
        hijo=arbol[nod][i];
        if(marcas[hijo.x]!=cont){
            cola.push(hijo.x);
        }
    }
}

void amplitud(int c, int d){
    cola.push(c);
    int nod;
    marcas[0]++;
    cont=marcas[0];
    while(!cola.empty()){
        nod= cola.front();
        if(marcas[nod]!=cont){
            addHijos(nod);
        }
        marcas[nod]=cont;
        cola.pop();
    }
}

bool isUnido(int c,int d){
    amplitud(c,d);
    if(marcas[d]==cont) return true;
    return false;
}

void addArbol(arista ar){
    arbol[ar.a].push_back({ar.b,ar.p});
    arbol[ar.b].push_back({ar.a,ar.p});
}

void kruskal(){
    arista ar;
    while(!pq.empty()){
        ar=pq.top();
        if(!isUnido(ar.a,ar.b)){
            addArbol(ar);
        }
        pq.pop();
    }
}


int y,z,peso;

void add(){
    grafo[y].push_back({z,peso});
    grafo[z].push_back({y,peso});
    pq.push({y,z,peso});
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>y>>z>>peso;
        add();
    }
    kruskal();
    int suma=0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<arbol[i].size(); j++){
            suma+=arbol[i][j].p;
        }
    }

    cout<<(suma/2)<<'\n';
}

int main(){
    solve();
    return 0;
}
