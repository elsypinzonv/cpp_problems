//http://codeforces.com/problemset/problem/467/B
#include <iostream>
#include <vector>

using namespace std;
int s;
vector<int> vc;
int k,n;

void bit(int x, int y){
    int sum=0;
    int b=x^y;
    for(int i=0; i<n; i++){
        if(b&1){
            sum++;
        }
        b=b>>1;
    }
    if(sum<=k) s++;

}

void solve(){
    int m;
    cin>>n>>m>>k;
    int x;
    for(int i=0; i<=m; i++){
        cin>>x;
        vc.push_back(x);
    }
    for(int i=0; i<m; i++){
      bit(vc[i], vc[m]);
    }
    cout<<s<<'\n';
}

int main(){
    solve();
    return 0;
}

