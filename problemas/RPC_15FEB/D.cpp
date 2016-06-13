#include <iostream>
#include <queue>
using namespace std;

const int MAX=103;
const char WHITE='w';
const char MARK='x';
const char BLACK='b';

struct node{
    int x;
    int y;
};

char graph[MAX][MAX];
queue<node> q;
int sum;

void clean(){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            graph[i][j]=0;
        }

    }
    sum=0;
}

void add(int x, int y){
   if(graph[x][y]!=MARK && graph[x][y]!=BLACK && graph[x][y]!=0){
        q.push({x,y});
    }
}

void putChild(node parent){
    int x=parent.x;
    int y= parent.y;
    add(x,y-1);
    add(x,y+1);
    add(x-1,y);
    add(x+1,y);
    add(x-1,y+1);
    add(x-1,y-1);
    add(x+1,y-1);
    add(x+1,y+1);
}

void BFS(){
    node nod;
    while(!q.empty()){
        nod=q.front();
        q.pop();
        if(graph[nod.x][nod.y]!=MARK){
            if(graph[nod.x][nod.y]=='-') sum++;
            putChild(nod);
            graph[nod.x][nod.y]=MARK;
        }
    }
}

void solve(){
    int t;
    cin>>t;
    int n;
    for(int i=0; i<t; i++){
        cin>>n;
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
               cin>>graph[j][k];
                if(graph[j][k]==WHITE){
                   q.push({j,k});
                }
            }
        }
        BFS();
        cout<<sum<<"\n";
        clean();
    }

}

int main(){
    solve();
    return 0;
}

