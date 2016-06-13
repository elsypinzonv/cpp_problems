#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_NODE=10001;
const int NOT_VISIT=0;

struct edge{
    int x;
    int weight;
};

bool operator< (edge a, edge b){
    return a.weight > b.weight;
}

vector<edge> graph[MAX_NODE];
priority_queue<edge> pq;
int marks[MAX_NODE];

void putChild(edge parent){
        edge child;
    for(int i=0; i<graph[parent.x].size(); i++){
        child = graph[parent.x][i];
        if(marks[child.x]==NOT_VISIT){
            pq.push({child.x,child.weight+parent.weight});
        }
    }

}

void dijkstra(){
    edge edg;
    while(!pq.empty()){
        edg= pq.top();
        pq.pop();
        if(marks[edg.x]==NOT_VISIT){
            putChild(edg);
            marks[edg.x]=edg.weight;
        }
    }
}

void resolve(int b){
    if(marks[b]==NOT_VISIT){
        cout<<"NO"<<"\n";
    }else cout<<(marks[b]-1)<<"\n";
}

void clean(){
    for(int i=0; i<MAX_NODE; i++){
        marks[i] = NOT_VISIT;
        graph[i].clear();
    }
}

void solve(){
    int c;
    cin>>c;
    int n,m;
    for(int i=0; i<c; i++){
        cin>>n>>m;
        int a,b,w;
        for(int j=0; j<m; j++){
            cin>>a>>b>>w;
            graph[a].push_back({b,w});
        }
        cin>>a>>b;
        pq.push({a,1});
        dijkstra();
        resolve(b);
        clean();
    }

}

int main(){
    solve();
    return 0;
}
