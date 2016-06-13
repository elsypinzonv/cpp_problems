#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> bi;

void solve(){
    int a;
    cin>>a;
    int x;
    while(a!=0){
        if(a&1){
            bi.push_back(1);
        } else bi.push_back(0);
        a=a>>1;
    }
    reverse(bi.begin(), bi.end());
    for(int i=0; i< bi.size(); i++){
        cout<<bi[i]<<' ';
    } cout<<'\n';

}

int main(){
    solve();
    return 0;
}

