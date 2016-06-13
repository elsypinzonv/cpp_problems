//http://www.spoj.com/problems/MAKEMAZE/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node{
    int x;
    int y;
};

const int MAX=23;
const char PARED = '#';
const char PASO = '.';

char maze[MAX][MAX];
vector<node> entry;
queue<node> q;


void clean(){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            maze[i][j]=0;
        }
    }
    entry.clear();
}

void pushChild(node parent){
    int x= parent.x;
    int y = parent.y;
    if(maze[x-1][y] == PASO) q.push({x-1,y});
    if(maze[x+1][y] == PASO) q.push({x+1,y});
    if(maze[x][y-1] == PASO) q.push({x,y-1});
    if(maze[x][y+1] == PASO) q.push({x,y+1});
}

void BFS(){
    q.push(entry[0]);
    node nod;
    while(!q.empty()){
        nod=q.front();
        q.pop();
        if(maze[nod.x][nod.y]==PASO){
            pushChild(nod);
            maze[nod.x][nod.y]=PARED;
        }

    }
}

void solve(){
    int t;
    cin>>t;
    int n,m;
    int entrysCon;
    for(int i=0; i<t; i++){
        entrysCon=0;
        cin>>n>>m;
        for(int j=1; j<=n; j++){
            for(int k=1; k<=m; k++){
                cin>> maze[j][k];
                if((j==1 || k==1 || j==n || k==m) && maze[j][k]==PASO){
                    entry.push_back({j,k});
                    entrysCon++;
                }
            }
        }
        node exit;
        if(entrysCon==2){
           BFS();
           exit=entry[1];
           if(maze[exit.x][exit.y]==PARED){
                cout<<"valid"<<"\n";
           }else cout<<"invalid"<<"\n";
        }else cout<<"invalid"<<"\n";
        clean();
    }
}

int main(){
    solve();
    return 0;
}
