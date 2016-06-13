#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<bool> bi;

void solve(){
    int a,b,c;
    cin>>a;

    if(a==0) cout<<a;
    while(a!=0){
        c=a>>1;
        b=c<<1;
        if(a!=b){
            bi.push_back(1);
        } else bi.push_back(0);

        a=c;
    }
    reverse(bi.begin(), bi.end());
    for(int i=0; i<bi.size(); i++){
        cout<<bi[i]<<' ';
    }


}

int main(){
    solve();
    return 0;
}
