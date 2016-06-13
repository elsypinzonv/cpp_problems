#include <iostream>
#include <queue>
#include <set>
#include <string>

using namespace std;

struct position{
    int x;
    int y;
    int z;
    int w;
    string path;
    int live;
};

const int pared='X';
const int gosth='G';

const int MAX=52;
char maze[MAX][MAX];
queue<position> q;
set<string> marks;
int nivel=1;
position nodR;
bool bandera;
int m,n;

string getString(int x, int y, int w, int z){
    return (to_string(x)+to_string(y)+','+to_string(w)+to_string(z));
}

bool isMark(int x, int y, int w, int z){
    return marks.find(getString(x,y,w,z));
}

void mark(position mk){
    marks.insert(getString(mk.x,mk.y,mk.z,mk.w));
}

void pushin(int x, int y, int z, int w, string path, int live){
    if(!isMark(x+y+z+w)){
        if(live>0){
            if(maze[x][y]==gosth){
                q.push({x,y,z,w,path,live-1});
            }else{
                q.push({x,y,z,w,path,live});
            }
        }
    }


}

void getX(int x){
    if(x==-1) return m-1;
    if(x==m) return 0;
    return x;
}

void getY(int y){
    if(y=-1) return -1;
    if(y=n) return 0;
}

void putChild(positon node){
    int x=node.x;
    int y = node.y;
    int z=node.z;
    int w= node.w;

    int a1= getX(x+1);
    int a2= getX(z+1);

    bool b1=(maze[a1][y]==pared);
    bool b2=(maze[a2][w]==pared]);

        if(b1 && !b2){
         pushin(a1, y, z,w, node.path+'N', node.live);
        }else if(!b1 && b2){
            pushin(x, y, a2,w, node.path+'N', node.live);
        }else if(!b1 && !b2){
            pushin(a1, y, a2,w, node.path+'N', node.live);
        }

    a1= getX(x-1);
    a2= getX(z-1);
    b1=(maze[x-1][y]==pared);
    b2=(maze[z-1][w]==pared]);

        if(b1 && !b2){
            pushin(a1, y, z,w, node.path+'S', node.live);
        }else if(!b1 && b2){
            pushin(x, y, a2,w, node.path+'S', node.live);
        }else if(!b1 && !b2){
            pushin(a1, y, a2,w, node.path+'S', node.live);
        }

    a1= getY(x+1);
    a2= getY(z+1);
    b1=(maze[x][y+1]==pared);
    b2=(maze[z][w+1]==pared]);

        if(b1 && !b2){
            pushin(x, a1, z,w, node.path+'O', node.live);
        }else if(!b1 && b2){
            pushin(x, y, z,a2, node.path+'O', node.live);
        }else if(!b1 && !b2){
            pushin(x, a1, z,a2, node.path+'O', node.live);
        }

    a1= getY(x-1);
    a2= getY(z-1);
    b1=(maze[x][y-1]==pared);
    b2=(maze[z][w-1]==pared]);

        if(b1 && !b2){
            pushin(x, a1, z,w, node.path+'E', node.live);
        }else if(!b1 && b2){
            pushin(x, y, z,a2, node.path+'E', node.live);
        }else if(!b1 && !b2){
            pushin(x, a1, z,a2, node.path+'E', node.live);
        }

}

void clean(){
    bandera=false;
    nivel=1;
    while(!q.empty())  q.front();
    //es necesario?
    for(int i=0; i<m;i++){
        for(int j=0; j<n;j++){
            maze[i][j]=0;
        }
    }
    //limpiar set
}


void BFS(){
    position node;
    int cantidad;
    while(!q.empty() && bandera==false){
        cantidad=cola.size();
        for(int i=0; i<cantidad; i++){
            node= q.front();
            if(node.x==node.z && node.y==node.w && bandera==false){
                bandera==true;
                nodR=node;
            }
            q.pop();
            if(!isMark(x,y,z,w)){
                putChild(node);
                mark(node);
            }
        }
        nivel++;
    }
}


void solve(){
    int t;
    cin>>t;

    for(int i=0; i<t; i++){
        cin>>m>>n;
        position nod;
        nod.x=-1;
        nod.live=5;
        for(int j=0; j<m; j++){
            for(int k=0; k<n; k++){
                cin>>maze[m][n];
                if(maze[m][n]=='P'){
                    if(nod.x==-1){
                        nod.x=m;
                        nod.y=n;
                    }else{
                        nod.z=m;
                        nod.w=n;
                    }
                }
            }
        }
        q.push(nod);
        BFS();
        if(bandera){
            cout<<nivel-1<<' '<<nodR.path<<'\n';
        }else cout<<"IMPOSSIBLE"<<'\n';
        clean();
    }
}

int main(){
    solve();
    return 0;
}
