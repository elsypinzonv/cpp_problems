#include<iostream>
#include<vector>
#include<queue>
using namespace std;


vector<int> grafo[500];
queue<int> q;
bool marks[500];
const int NOT_VISIT=false;

void putChild(int node){
    int child;
    for(int i=0; i<grafo[node].size(); i++){
        child=grafo[node][i];
        if(marks[child]==NOT_VISIT){
            q.push(child);
        }
    }
}

void BFS(){
    int node;
    while(!q.empty()){
        node=q.front();
        q.pop();
        if(marks[node]==NOT_VISIT){
            putChild(node);
            marks[node]=true;
            cout<<node<< ' ';
        }
    }
}

void solve(){
    int n,u,t;
    cin>>n>>u;
    int a,b;
    for(int i=0; i<u; i++){
        cin>>a>>b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    cin>>t;
    q.push(t);
    BFS();
}

int main(){
    solve();
    return 0;
}
