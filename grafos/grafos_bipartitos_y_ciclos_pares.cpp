#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int NODE_NUMBER=20;
const int RED=1;
const int BLUE=2;
const int NOT_VISIT=0;

struct node{
    int x;
    int color;
};

vector<int> graph[NODE_NUMBER];
queue<node> q;
int marks[NODE_NUMBER];


int getColor(int color){
    if(color==RED) return BLUE;
    return RED;
}

void putChild(node parent){
    int child;
    for(int i=0; i<graph[parent.x].size(); i++){
        child= graph[parent.x][i];
        if(marks[child]==NOT_VISIT){
           q.push({child,getColor(parent.color)});
        }
    }
}

void BFS(){
    node nod;
    while(!q.empty()){
        nod=q.front();
        q.pop();
        if(marks[nod.x]==NOT_VISIT){
            marks[nod.x] = nod.color;
            putChild(nod);
        }else{
            if(marks[nod.x]== nod.color){
                cout<<"ciclo par"<<'\n';
            } cout<<"ciclo impar"<<'\n';
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=0; i<n; i++){
        if(marks[i]==NOT_VISIT){
            q.push({1,RED});
            BFS();
        }
    }
}

int main(){
    solve();
    return 0;
}
