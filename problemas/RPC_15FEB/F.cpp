#include <iostream>
using namespace std;

const int MAX=101;
int n,m;

struct node{
    int x;
    int y;
    bool power;
};

node graph[MAX][MAX];

node getRaiz(int x, int y){
    node a = graph[x][y];
    while(a.x!=x || a.y!=y){
        x=a.x;
        y=a.y;
        a=graph[a.x][a.y];
    }
    return a;
}

bool isLink(int x, int y, int z ,int w){
    node a=getRaiz(x,y);
    node b= getRaiz(z,w);
    return (a.x==b.x && a.y==b.y);
}

void link(int x, int y, int z, int w){
        if(!isLink(x,y,z,w)){
            node a= getRaiz(z,w);
            node b = getRaiz(x,y);
            if(graph[b.x][b.y].power) a.power=true;
            graph[b.x][b.y]=a;
            graph[a.x][a.y]=a;
        }
}


void init(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            graph[i][j]={i,j,false};
        }
    }

}

/*void print(){
    node a;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            a=graph[i][j];
            cout<<'{'<<a.x<<','<<a.y<<','<<a.power<<'}'<<' ';
        }
        cout<<'\n';
    }
} */

int getResult(){
  int sum=0;
    node a;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            a=graph[i][j];
            if(a.x==i && a.y==j && a.power==false) sum++;
        }
    }
    return sum;
}

void solve(){
    int t;
    cin>>t;
    int p,c;
    for(int i=0; i<t; i++){
        cin>>n>>m>>p>>c;
        init();
        int x,y;
        for(int j=0; j<p; j++){
            cin>>x>>y;
            graph[x][y]={x,y,true};
        }
        char a;
        for(int j=0; j<c; j++){
            cin>>x>>y>>a;
            if(a=='U'){
                link(x,y,x,y+1);
            }else link(x,y,x+1,y);
        }
        cout<<getResult()<<'\n';
    }
}

int main(){
    solve();
    return 0;
}

