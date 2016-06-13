//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=508
#include <iostream>
using namespace std;

const int MAX=21;
const int INF=9999;
int graph[22][22];
int cont=1;
void init(){
    for(int i=1; i<MAX; i++){
        for(int j=1; j<MAX; j++){
            if(i==j){
                graph[i][j]=0;
            }else{
                graph[i][j]=INF;
            }
        }
    }

}

void fw(){
    for(int k=1; k<MAX; k++){
        for(int i=1; i<MAX; i++){
            for(int j=1; j<MAX; j++){
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }
}

void solve(){
    int n;
    while(cin>>n){
        if(cont!=1) cout<<'\n';
        init();
        for(int i=1; i<20; i++){
            if(i!=1) cin>>n;
            int a;
            for(int j=0; j<n; j++){
                cin>>a;
                graph[i][a]=1;
                graph[a][i]=1;
            }
        }
        fw();

        cin>>n;
        int c,b;
        cout<<"Test Set #"<<cont<<'\n';
        for(int i=0; i<n; i++){
            cin>>c>>b;
            if(c<10){
                cout<<' ';
            }
            cout<<c<<" to ";
            if(b<10){
                cout<<' ';
            }
            cout<<b<<": "<<graph[c][b]<<'\n';
        }
        cont++;
    }
}

int main(){
        solve();

    return 0;
}
