#include <bits/stdc++.h>
using namespace std;

long long N;
long long ar[100002][3];
long long cont=1;

void solve(){
    while(true){

        cin>>N;
        if(N==0) break;

        for(int i=0; i<N; i++){
            cin>>ar[i][0];
            cin>>ar[i][1];
            cin>>ar[i][2];
        }
        ar[0][0] =10000000000;
        ar[0][2] += ar[0][1];

        for(int i=1; i<N; i++){
            for(int j=0; j<3; j++){
                if(j==0) ar[i][j] += min(ar[i-1][0],ar[i-1][1]);
                if(j==1) ar[i][j] += min(min(ar[i][0],ar[i-1][0]),min(ar[i-1][1],ar[i-1][2]));
                if(j==2) ar[i][j] += min(min(ar[i][1],ar[i-1][1]),ar[i-1][2]);
            }
        }
        cout<<cont<<". "<<ar[N-1][1]<<"\n";
        cont++;
    }
}

int main(){
    solve();
    return 0;
}


