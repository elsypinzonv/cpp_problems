//http://www.spoj.com/problems/MICEMAZE/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX=102;
const int NOT_VISIT=0;
int t;


struct edge{
    int x;
    int cost;
};

bool operator<(edge a, edge b){
    return (a.cost > b.cost);
}

vector<edge> graph[MAX];
priority_queue<edge> pq;
int marks[MAX];
int sum=0;

void putChild(edge parent){
    edge child;
    for(int i=0; i<graph[parent.x].size(); i++){
        child = graph[parent.x][i];
        if(marks[child.x]==NOT_VISIT){
            pq.push({child.x,child.cost+ parent.cost});
        }

    }
}

void dijkstra(){
    edge node;
    while(!pq.empty()){
        node=pq.top();
        pq.pop();
        if(marks[node.x]==NOT_VISIT){
            putChild(node);
            marks[node.x]=node.cost;
            if(node.cost-1<=t) sum++;
        }
    }
}


void solve(){
    int n,e,m;
    cin>>n>>e>>t>>m;
    int a,b,c;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        graph[b].push_back({a,c});
    }
    pq.push({e,1});
    dijkstra();
    cout<<sum<<"\n";
}

int main(){
    solve();
    return 0;

}
