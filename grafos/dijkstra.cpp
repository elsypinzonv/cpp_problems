#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct nodo{
    int x;
    int peso;
};

int minimos[500];
vector<nodo> grafo[500];
int n;

bool operator<(nodo a, nodo b){
    return a.peso>b.peso;
}
priority_queue<nodo> cola;


void meter(nodo nod){
    for(int i=0; i<grafo[nod.x].size(); i++){
        nodo hijo=grafo[nod.x][i];
        if(minimos[hijo.x]==0){
            cola.push({hijo.x,hijo.peso+nod.peso});
        }
    }
}

void dijkstra(){
    nodo nod;
    while(!cola.empty()){
        nod=cola.top();
        cola.pop();
        if(minimos[nod.x]==0){
            minimos[nod.x]=nod.peso;
            meter(nod);
        }
    }
}

void imprimir(){

    for(int i=1; i<n+1; i++){
        cout<<i<<' '<<minimos[i]-1<<'\n';
    }
}

int main(){
    cin>>n;
    int a,b,p;
    for(int i=0; i<n; i++){
        cin>>a>>b>>p;
        grafo[a].push_back({b,p});
        grafo[b].push_back({a,p});
    }
    int c;
    cin>>c;
    cola.push({c,1});
    dijkstra();
    imprimir();
}
