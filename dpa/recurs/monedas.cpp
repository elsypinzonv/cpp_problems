#include <iostream>
using namespace std;

const int a=1;
const int b=5;
const int c=8;
const int d=10;

int s(int x){
    if(x>0){
        return min(
                    min(s(x-a) +1, s(x-b) +1),
                    min(s(x-c) +1, s(x-d)+1)
                   );
    } return 0;
}

void solve(){
    int n;
    cin>>n;
    cout<<s(n)<<'\n';

}

int main(){
    solve();

    return 0;
}
