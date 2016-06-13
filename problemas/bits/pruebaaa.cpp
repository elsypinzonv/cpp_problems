//http://codeforces.com/problemset/problem/579/A
#include <iostream>
using namespace std;

int sum;

void bin(int a){
   while(a!=0){
        if(a&1){
            cout<<'1'<<' ';
        }else cout<<'0'<<' ';
        a=a>>1;
    }cout<<' ';
}

void solve(){
    int c;
    while(true){
        cin>>c;
        bin(c);

    }

}

int main(){
    solve();
    return 0;
}
