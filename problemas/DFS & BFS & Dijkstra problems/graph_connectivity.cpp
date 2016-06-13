//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=400

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> grafo[27];
queue<int> cola;
int marcas[27];
int cont=1;
int n;


void meterHijos(int padre){
    int hijo;
    for(int i=0; i<grafo[padre].size(); i++){
        hijo=grafo[padre][i];
        if(marcas[hijo]!=cont) cola.push(hijo);
    }
}

void amplitud(int init){
    cola.push(init);
    int nodo;
    while(!cola.empty()){
        nodo=cola.front();
        cola.pop();
        if(marcas[nodo]!=cont){
            marcas[nodo]=cont;
            meterHijos(nodo);
        }
    }
    cont++;
}

void limpiar(){
    for(int i=0; i<=n; i++){
        marcas[i]=0;
        grafo[i].clear();
    }
    cont=1;
}

void solve(){
    int casos;
    cin>>casos;
    char c;
    for(int i=0; i<casos; i++){
        if(i!=0) cout<<'\n';
        cin>>c;
        n=c-'A';
        string edge;
        getline(cin, edge);
        while(true){
            getline(cin, edge);
            if(edge.size()==0) break;
            grafo[edge[0]-'A'].push_back(edge[1]-'A');
            grafo[edge[1]-'A'].push_back(edge[0]-'A');
        }
        int subgrafos=0;

        for(int j=0; j<=n; j++){
          if(marcas[j]==0){
            amplitud(j);
            subgrafos++;
          }
        }
        cout<<subgrafos<<'\n';
        limpiar();
    }


}

int main(){
    solve();
    return 0;
}
