#include <iostream>
using namespace std;

int sum;

void bin(int a){

    while(a!=0){
        if(a&1){
            sum++;
        }
        a=a>>1;
    }

}

void solve(){
    for(int i=1; i<16; i++){
        bin(a);
    }
    cout>>a;
}

int main(){
    solve();
    return 0;
}
