#include <iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

int nodeL[1001];
int nodeR[1001];
int maxL[1001];
int maxR[1001];
int N;
int axis;
int level;
int maxWidth=0;

void process(int lev){
    axis++;
    if(maxL[lev]==0) maxL[lev]=axis;
    maxR[lev]=axis;
}

void order(int node, int lev){
    int left = nodeL[node];
    int right = nodeR[node];
    if(left!= -1) order(left, lev+1);
    process(lev);
    if(right!=-1) order(right, lev+1);
}

void calculateMaxWidth(){
    int width;
    for(int i=1; i<=N; i++){
        width = maxR[i]-maxL[i];
        width=width+1;
        if(width>maxWidth){
            maxWidth=width;
            level=i;
        }
    }
}

void solve(){
    cin>>N;
    int n;
    for(int i=0; i<N; i++){
        cin>>n;
        cin>>nodeL[n];
        cin>>nodeR[n];
    }
    order(1,1);
    calculateMaxWidth();
    cout<<level<<' '<<maxWidth<<'\n';
}

int main(){
    optimizar_io
    solve();
    return 0;
}
