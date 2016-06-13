#include <iostream>
using namespace std;

const int a=1;
const int b=5;
const int c=8;
const int d=10;

int const MAX=99999;
int ar[MAX];


int getI(int i){
    if(i<0){
        return MAX;
    } return ar[i-a];
}

void s(int x){
    ar[0]=0;

    for(int i=1; i<=x; i++){
            ar[i]= min(
                       min(getI(i-a),getI(i-b)),
                       min(getI(i-c),getI(i-d))
                       ) +1;

    }

}


void solve(){
    int n;
    cin>>n;
    s(n);
    cout<<ar[n]<<'\n';
}

int main(){
    solve();
    return 0;
}
