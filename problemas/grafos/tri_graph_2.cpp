#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct edge{
    int x;
    int peso;
};

bool operator<(edge a, edge b){
    return a.peso > b.peso;
}

int N;
int ar[100001][3];
vector<edge> grafo[1000001];
priority_queue<edge> pq;
int marcas[1000001];

void limpiar(){
    for(int i=0; i<N*3; i++){
        grafo[i].clear();
    }

    for(int i=0; i<1000001; i++){
        marcas[i]=0;
    }

}


void meterHijos(edge padre){
    edge hijo;
    for(int i=0; i<grafo[padre.x].size(); i++){
        hijo=grafo[padre.x][i];
        if(marcas[hijo.x]==0){
            pq.push({hijo.x,hijo.peso+padre.peso});
        }
    }

}

void dijkstra(){
    edge nod;
    while(!pq.empty()){
        nod=pq.top();
        pq.pop();
        if(marcas[nod.x]==0){
            meterHijos(nod);
            marcas[nod.x]=nod.peso;
        }

    }
}

void solve(){
    int cont;
    int casos=0;
    while(true){
        casos++;
        cont=0;
    cin>>N;
    if(N==0) break;
        for(int i=0; i<N; i++){
            cin>>ar[i][0];
            cin>>ar[i][1];
            cin>>ar[i][2];
        }
        int peso;
        for(int i=0; i<N; i++){
            for(int j=0; j<3; j++){
                peso = ar[i][j];
                if(j==0){
                        grafo[cont].push_back({cont+1,peso});
                        grafo[cont].push_back({cont+3,peso});
                        grafo[cont].push_back({cont+4,peso});

                }
                if(j==1){
                    grafo[cont].push_back({cont+2,peso});
                    grafo[cont].push_back({cont+3,peso});
                    grafo[cont].push_back({cont+4,peso});
                    grafo[cont].push_back({cont+1,peso});
                }
                if(j==2){
                    grafo[cont].push_back({cont+2,peso});
                    grafo[cont].push_back({cont+3,peso});
                }
            cont++;
            }
        }

        pq.push({1,1});
        dijkstra();

        cout<<casos<<'.'<<' '<<(marcas[cont-2]+ar[N-1][1]-1)<<"\n";
        limpiar();
    }
}

int main(){
    solve();
    return 0;
}
