#include <iostream>
using namespace std;

const int MAX=6000;
const int INF=99999;
int fw[MAX][MAX];
int v;

void marshall(){
    for(int k=1; k<=v; k++){
        for(int i=1; i<=v; i++){
            for(int j=1; j<=v; j++){
                fw[i][j]=min(fw[i][j],(fw[j][k]+fw[k][i]));
            }
        }
    }
}

void init(){
     for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            if(i==j){
                fw[i][j]=0;
            } else {
                fw[i][j]=INF;
            }
        }
    }
}

void solve(){

    int m;
    cin>>v>>m;
    int a,b,c;
    init();
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        fw[a][b]=c;
        fw[b][a]=c;
    }

    marshall();

    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            cout<<fw[i][j]<<' ';
        } cout<<'\n';
    }
}



int main(){
    solve();
    return 0;

}




