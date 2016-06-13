#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
    int x;
    int peso;
};

bool operator<(node a, node b){
    return a.peso>b.peso;
}

const int NOT_VISIT =0;
vector<node> grafo[500];
priority_queue<node> pq;
int mins[500];

void putChild(node parent){
    node child;
    for(int i=0; i<grafo[parent.x].size(); i++){
        child = grafo[parent.x][i];
        if(mins[child.x]==NOT_VISIT){
            pq.push({child.x, child.peso + parent.peso});
        }
    }
}

void dijkstra(){
    node nod;
    while(!pq.empty()){
        nod=pq.top();
        pq.pop();
        if(mins[nod.x]==NOT_VISIT){
            putChild(nod);
            mins[nod.x]=nod.peso;
        }
    }
}

void solve(){
    int n,u;
    cin>>n>>u;
    int a,b,c;
    for(int i=0; i<u; i++){
        cin>>a>>b>>c;
        grafo[a].push_back({b,c});
        grafo[b].push_back({a,c});
    }
    pq.push({1,1});
    dijkstra();
    for(int i=1; i<=n; i++){
        cout<<mins[i]-1<<' ';
    }cout<<'\n';
}

int main(){
    solve();
    return 0;
}
