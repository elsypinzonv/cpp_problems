#include <iostream>
using namespace std;

int sum,b;

void bin(int a){
    int s=0;
    while(a!=0){
        if(a&1){
            s++;
        }
        a=a>>1;
    }
    if(s==b) sum++;
}

void solve(){
    int c;
    cin>>c>>b;
    for(int i=1; i<c; i++){
        bin(i);
    }
    cout<<sum;
}

int main(){
    solve();
    return 0;
}
