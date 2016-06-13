//https://code.google.com/codejam/contest/9214486/dashboard
#include <iostream>
using namespace std;
 int x;
void excute(char c){
    if(c=='O'){
        x=x<<1;
    }else {
        if(x==0){
            x=1;
        }else x=x*10;
    }
}

void solve(){
    int t;
    cin>>t;
    int b;
    for(int i=0; i<t; i++){
        cin>>b;
        for(int j=0; j<b; j++){
            char c;
            x=0;
            for(int k=0; k<8; k++){
                cin>>c;
                excute(c);
            }
            cout<<(char)x;
        }
    }
}

int main(){
    solve();
    return 0;
}
