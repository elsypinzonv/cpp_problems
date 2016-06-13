//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=4829

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX=10001;
const int NOT_VISIT=0;
struct edge{
    int x;
    int cost;
};

bool operator<(edge a, edge b){
    return a.cost > b.cost;
}

priority_queue<edge> pq;
vector<edge> graph[MAX];
vector<edge> gr[MAX];
int marks[MAX];
int c;
void clean(){
    for(int i=0; i<=c; i++){
        graph[i].clear();
        marks[i]=0;
    }
}

void create(){
    for(int i=1; i<=c; i++){
        edge parent;
        for( int j=0; j<graph[i].size(); i++){
            parent=graph[i][j];
            edge child;
            for(int k=0; k<graph[parent.x].size(); k++){
                gr[i].push_back(graph[parent.x][k]);
            }
        }
    }
}

void pushChild(edge parent){
    edge child;
    edge grandchild;
    for(int i=0; i<graph[parent.x].size(); i++){
        child=graph[parent.x][i];
        edge grandchild;
        for(int j=0; j<graph[child.x].size(); j++){
            grandchild= graph[child.x][j];
            if(marks[grandchild.x]==NOT_VISIT){
                pq.push({grandchild.x,parent.cost+child.cost+grandchild.cost});
            }
        }
    }
}

void dijkstra(){
    edge current;
    while(!pq.empty()){
        current=pq.top();
        pq.pop();
        if(marks[current.x]==NOT_VISIT){
                        marks[current.x]=current.cost;
            pushChild(current);

        }
    }
}

void solve(){

    while(true){
        int v;
        cin>>c>>v;
        int a,b,w;
        for(int i=0; i<v; i++){
            cin>>a>>b>>w;
            graph[a].push_back({b,w});
            graph[b].push_back({a,w});
        }
        pq.push({1,1});
        create();
        dijkstra();
        cout<<(marks[c]-1)<<"\n";
        clean();
    }

}

int main(){
    solve();
    return 0;
}

