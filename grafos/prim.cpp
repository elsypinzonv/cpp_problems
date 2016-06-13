#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct nodo{
    int x;
    int p;
};

bool operator<(nodo a, nodo b){
    return a.p > b.p;
}

int N;
int suma=0;
priority_queue<nodo> pq;
vector<nodo> grafo[500];
bool marcas[500];

void meterHijos(int padre){
    nodo hijo;
    for(int i=0; i<grafo[padre].size(); i++){
        hijo = grafo[padre][i];
        if(!marcas[hijo.x]){
            pq.push(hijo);
        }
    }
}

void prim(){
    nodo nod;
    while(!pq.empty()){
        nod=pq.top();
        if(!marcas[nod.x]){
            meterHijos(nod.x);
            suma+=nod.p;
            marcas[nod.x]=true;
        }
        pq.pop();
    }
}

void solve(){
    int A;
    cin>>N>>A;
    int c,d,p;
    for(int i=0; i<A; i++){
        cin>>c>>d>>p;
        grafo[d].push_back({c,p});
        grafo[c].push_back({d,p});
    }
    pq.push({1,0});
    prim();
    cout<<suma<<'\n';
}

int main(){
    solve();
    return 0;
}
