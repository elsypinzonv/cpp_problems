#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int n;

struct nodo{
    int x;
    int peso;
};


vector<nodo> grafo[20001];
int minimos[20001];

bool operator<(nodo a, nodo b){
    return a.peso > b.peso ;
}

priority_queue<nodo> cola;

void meter(nodo nod){
    nodo hijo;
    for(int i=0; i<grafo[nod.x].size(); i++){
        hijo = grafo[nod.x][i];
        if(minimos[hijo.x]==0){
            cola.push({hijo.x,hijo.peso+nod.peso});
        }

    }

}

void dijkstra(){
    nodo nod;
    while(!cola.empty()){
        nod=cola.top();
        if(minimos[nod.x]==0){
            minimos[nod.x]=nod.peso;
            meter(nod);
        }
        cola.pop();
    }

}


void clean(){
    for(int i=0; i<20001; i++){
        minimos[i]=0;
        grafo[i].clear();
    }

}

void solve(){
    int N;
    cin>>N;
    int m,S,T;
    for(int i=1; i<=N; i++){
        cin>>n>>m>>S>>T;
        int a,b,p;
        for(int j=0; j<m; j++){
             cin>>a>>b>>p;
            grafo[a].push_back({b,p});
            grafo[b].push_back({a,p});
        }
        cola.push({S,1});
        dijkstra();
        cout<<"Case #"<<i<<":"<<" ";
        if(minimos[T]>0){
            cout<<minimos[T]-1<<'\n';
        } else cout<<"unreachable"<<'\n';

        clean();
    }
}


int main(){
    solve();
    return 0;
}
