#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
fstream fs("test.in",fstream::in);

long long dis;
long long gas;

struct node{
    long long x;
    long long d;
    long long g;
};

vector<node> sums;

bool leer(){
    for(int i=0; i<sums.size(); i++){
        dis+=sums[i].d;
        gas+=sums[i].g;
        if(dis>gas){
            return false;
        }
    }
    return true;
}

void solve(){
    int t;
    fs>>t;
    int n;
    for(int i=0; i<t; i++){
        dis=0;
        gas=0;
        sums.clear();
        fs>>n;
        long long x,y;
        for(int j=1; j<=n; j++){
            fs>>x>>y;
            gas+=x;
            dis+=y;
            if(dis>gas){
                sums.push_back({j,dis,gas});
                gas=0;
                dis=0;
            }
        }
        if(dis==0 && gas==0){
            cout<<"IMPOSSIBLE"<<'\n';
        }else{
            if(leer()){
                if(sums.size()==0){
                    cout<<1<<'\n';
                }else cout<<((sums[sums.size()-1].x)+1)<<"\n";
            } else cout<<"IMPOSSIBLE"<<'\n';
        }
    }
}

int main(){
    solve();
    return 0;
}
