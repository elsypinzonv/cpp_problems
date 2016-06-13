#include<iostream>
#include<queue>
using namespace std;

const string enun ="Case #";
queue<int> q;

void solve(){
    int t;
    cin>>t;
    int n;
    for(int i=1; i<=t; i++){
        cin>>n;
        int p;
        for(int j=0; j<2*n;j++){
            cin>>p;
            if(j==0){
                q.push(p*100/75);
                cout<<enun<<i<<':'<<' '<<p;
            }else{
                if(q.empty()){
                     q.push(p*100/75);
                     cout<<' '<<p;
                }else{
                    if(p==q.front()){
                        q.pop();
                    }else{
                        q.push(p*100/75);
                        cout<<' '<<p;
                    }
                }

            }
        } cout<<'\n';
    }
}

int main(){
    solve();
    return 0;
}
