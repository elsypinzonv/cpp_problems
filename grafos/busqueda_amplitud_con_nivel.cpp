//https://omegaup.com/arena/problem/diametroarbol#problems
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> grafo[200001];
queue<int> cola;
bool mark[200001];
int n;
int nivel=-1;
int cantidad=0;
int nodoFinal;


void limpiar(){
    nivel=-1;
    cantidad=0;

    for(int i=0; i<200001; i++){
        mark[i]=false;
    }
}



void addNodo(int nodo){
     for(int i=0; i<grafo[nodo].size(); i++){
        if(!mark[grafo[nodo][i]]) cola.push(grafo[nodo][i]);
     }
}

void amplitud(){
    while(!cola.empty()){
        cantidad=cola.size();
        int nodo;
        for(int i=0; i<cantidad; i++){
            nodo=cola.front();
            addNodo(nodo);
            mark[nodo]=true;
            cola.pop();
        }
        nodoFinal=nodo;
        nivel++;
    }
}

void solve(){
    cin>>n;
    int a,b;
    for(int i=0; i<n-1; i++){
        cin>>a>>b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    cola.push(1);
    amplitud();
    limpiar();
    cola.push(nodoFinal);
    amplitud();
    cout<<nivel<<'\n';
}


int main(){
    solve();
    return 0;
}
