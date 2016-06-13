#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_NODE=100001;
const int NOT_VISIT=0;
const int RED=1;
const int BLUE=2;

struct node{
    int x;
    int color;
};

vector<int> graph[MAX_NODE];
queue<node> q;
vector<int> colors;

int marks[MAX_NODE];
bool cycle;

int getColor(int color){
    if(color== RED) return BLUE;
    return RED;
}

void putChild(node parent){
    int child;
    for(int i=0; i<graph[parent.x].size(); i++){
        child=graph[parent.x][i];
        if(marks[child]==NOT_VISIT) q.push({child,getColor(parent.color)});
    }
}

long long calcular(){
    long long sum=0;
    long long n;
    for(int i=0; i<colors.size(); i++){
        n=colors[i];
        sum+=((n*(n-1))/2);
    }
    return sum;
}

long long maxi;

void BFS(){
    long long reds=0;
    long long blues=0;
    node nod;
    while(!q.empty()){
        nod=q.front();
        q.pop();

        if(marks[nod.x]==NOT_VISIT){
            putChild(nod);
            marks[nod.x]= nod.color;
            if(nod.color==RED){
              reds++;
            } else blues++;
        }else{
            if(marks[nod.x] != nod.color){
                cycle=true;
            }
        }
    }
    colors.push_back(reds);
    colors.push_back(blues);
    maxi=max(maxi,reds+blues);

}

void solve(){
    long long N,A;
    cin>>N>>A;
    int a,b;
    for(int i=0; i<A; i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    if(A==0){
        cout<<'3'<<' '<<((long long)((N*(N-1)*(N-2))/6))<<"\n";
    }else {
        for(int i=1; i<=N; i++){
            if(marks[i]==NOT_VISIT){
                   q.push({i,RED});
                   BFS();
            }
        }

        if(cycle){
            cout<<'0'<<' '<<'1'<<"\n";
        }else{
            if(maxi==2){
                cout<<'2'<<' '<<((long long)(A*(N-2)))<<"\n";
            }else{
                cout<<'1'<<' '<<calcular()<<"\n";
            }
        }
    }
}

int main(){
    solve();
    return 0;
}
