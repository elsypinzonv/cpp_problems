#include <iostream>
using namespace std;

const int MAX=102;
const long long INF=4294967296;
long long  fw[MAX][MAX];
long long n;

void marshall(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                fw[i][j]=min(fw[i][j],(fw[j][k]+fw[k][i]));
            }
        }
    }
}

void init(){
     for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j){
                fw[i][j]=0;
            } else {
                fw[i][j]=INF;
            }
        }
    }
}

void solve(){

    int e,m;
    long long t;
    cin>>n>>e>>t>>m;
    int a,b;
    long long c;
    init();
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        fw[a][b]=c;
    }

    marshall();
    int sum=0;
    for(int i=1; i<=n; i++){
        if(fw[e][i]>=t) sum++;
    }
    cout<<sum;
}



int main(){
    solve();
    return 0;

}




