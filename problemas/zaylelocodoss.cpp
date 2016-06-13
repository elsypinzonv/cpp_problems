#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct sx{
    string x;
    map<int,int> mp;
};
    string pal;
queue<sx> q;

void putChild(sx a){
    sx b;
    for(int i=0; i<pal.size(); i++){
        if(a.mp[i+1]==0){
            b.x=a.x+pal[i];
            b.mp=a.mp;
            b.mp[i+1]=i+1;
            q.push(b);
        }
    }

}

void BFS(){
    sx a;
    while(!q.empty()){
        a= q.front();
        q.pop();
        if(a.x.size()==pal.size()){
            cout<<a.x<<'\n';
        }
        putChild(a);
    }
}

void solve(){

    cin>>pal;

    for(int i=0; i<pal.size(); i++){
    sx a;
        a.x=pal[i];
        a.mp[i+1]=i+1;
        q.push(a);
    }
    BFS();

}

int main(){
    solve();
    return 0;
}
