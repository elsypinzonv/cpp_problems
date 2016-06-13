#include<iostream>
#include <algorithm>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

const int MAX=100001;
long long n,k;
struct coor{
    long long x;
    long long y;
};
coor pro[MAX];

bool operator<(coor a, coor b){
    if(a.x<b.x){
        return true;
    }else if (a.x==b.x){
        return (a.y < b.y);
    }else{
        return false;
    }
}

void solve(){
    cin>>n>>k;
    for(long long i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        pro[i]={x,y};
    }
    sort(pro,pro+n);
    for(long long i=0; i<k; i++){
        int a,b;
        cin>>a>>b;
        coor c ={a,b};
        if(binary_search(pro,pro+n,c)){
            cout<<'0'<<'\n';
        }else cout<<'1'<<'\n';
   }
}

int main(){
    optimizar_io
    solve();
    return 0;
}
