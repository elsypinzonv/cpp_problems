//http://codeforces.com/problemset/problem/579/A
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
    int c;
    cin>>c;
    bin(c);
    cout<<sum;
}

int main(){
    solve();
    return 0;
}
