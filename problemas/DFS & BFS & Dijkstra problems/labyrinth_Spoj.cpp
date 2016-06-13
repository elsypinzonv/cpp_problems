//http://acm.tju.edu.cn/toj/showp1056.html

#include <iostream>
#include <queue>

using namespace std;

const int MAX=1003;
char POINT='1';
char WALL='2';

struct node{
    int x;
    int y;
};

char maze[MAX][MAX];
queue<node> q;

void clean(){
    for(int i=0; i<MAX; i++){
        for(int j=0; j<MAX; j++){
            maze[i][j]=WALL;
        }
    }
    POINT='1';
    WALL='2';
}

void pushChild(node parent){
    int x= parent.x;
    int y= parent.y;
    if(maze[x-1][y]==POINT) q.push({x-1,y});
    if(maze[x+1][y]==POINT) q.push({x+1,y});
    if(maze[x][y-1]==POINT) q.push({x,y-1});
    if(maze[x][y+1]==POINT) q.push({x,y+1});
}


node nex;
int BFS(){
    node nod;
    int niv=-1;
    int dis;
    while(!q.empty()){
        dis=q.size();
        for(int i=0; i<dis; i++){
            nod= q.front();
            q.pop();
                if(maze[nod.x][nod.y]==POINT){
                    nex=nod;
                    pushChild(nod);
                    maze[nod.x][nod.y]=WALL;
                }
            }
        niv++;
    }
    return niv;
}

void solve(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n,m;
        cin>>m>>n;
        node nod;
        nod.x=0;
        nod.y=0;
        for(int j=1; j<=n; j++){
            for(int k=1; k<=m; k++){
                cin>>maze[j][k];
                if(maze[j][k]=='.'){
                    nod.x=j;
                    nod.y=k;
                    maze[j][k]='1';
                }
            }
        }
        if(nod.x!=0 && nod.y!=0){
            q.push({nod.x,nod.y});
            BFS();
            q.push({nex.x, nex.y});
            POINT='2';
            WALL='3';
            cout<<"Maximum rope length is "<<BFS()<<'.'<<"\n";
        }
        clean();
    }
}

int main(){
    solve();
    return 0;
}
