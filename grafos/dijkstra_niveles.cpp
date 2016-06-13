#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct nodo{
    int x;
    int peso;
    int nivel;
};

vector<nodo> grafo[500];
priority_queue<nodo> cola;

bool operator<(nodo a, nodo b){
    return a.peso+a.nivel>b.peso+b.nivel;
}
int minimos[500];
int n;

void meter(nodo nod){
    nodo hijo;
    for(int i=0; i<grafo[nod.x].size(); i++){
        hijo= grafo[nod.x][i];
        if(minimos[hijo.x]==0){
            cola.push({hijo.x,hijo.peso+nod.peso,nod.nivel+1});
        }
    }
}

void dijkstra(){
    nodo nod;
    while(!cola.empty()){
        nod= cola.top();
        if(minimos[nod.x]==0){
            minimos[nod.x]=nod.peso+nod.nivel;
            meter(nod);
        }
        cola.pop();

    }
}

void imprimir(){

    for(int i=1; i<n+1; i++){
        cout<<i<<' '<<minimos[i]-1<<'\n';
    }
}

void solve(){
    cin>>n;
    int a,b,p;
    for(int i=0; i<n; i++){
        cin>>a>>b>>p;
        grafo[a].push_back({b,p,0});
        grafo[b].push_back({a,p,0});
    }
    int c;
    cin>>c;
    cola.push({c,1,0});
    dijkstra();
    imprimir();
}

int main(){
    solve();
    return 0;
}
