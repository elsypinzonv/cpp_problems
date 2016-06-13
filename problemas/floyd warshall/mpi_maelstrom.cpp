//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=364
#include <iostream>
using namespace std;

const int MAX=102;
const int INF=-1;
int fw[MAX][MAX];
int n;


int getInt(string s){
    int n=0;
    for(int i=0; i<s.size(); i++){
        n=(n*10)+(s[i]-'0');
    }

    return n;
}

void floydW(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(fw[i][k]==INF || fw[k][j]==INF){
                    fw[i][j]=fw[i][j];
                }else{
                    if(fw[i][j]==INF){
                        fw[i][j]=fw[i][k]+fw[k][j];
                    }else {
                        fw[i][j]=min(fw[i][j],fw[i][k]+fw[k][j]);
                    }
                }
           }
        }

    }
}

void init(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j){
                fw[i][j]=0;
            }else fw[i][j]=INF;
        }
    }
}

void solve(){
    cin>>n;
    string s;
    init();
    for(int i=2; i<=n; i++){
        for(int j=1; j<i; j++){
            cin>>s;
            if(s!="x"){
                fw[i][j]=getInt(s);
                fw[j][i]=fw[i][j];
            }
        }
    }


    floydW();
    int rs=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            rs= max(rs, fw[i][j]);
        }
    }
    cout<<rs<<'\n';
}

int main(){

    solve();
    return 0;
}

