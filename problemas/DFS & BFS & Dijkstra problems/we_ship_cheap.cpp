//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=703
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAX = 700;
const int NOT_VISIT=0;

struct edge{
    int x;
    int cost;
    int p;
};

bool operator<(edge a, edge b){
    return a.cost > b.cost;
}

vector<int> graph[MAX];
map<string,int> mp;
priority_queue<edge> pq;
vector<string> cl;
vector<string> route;
int mark[MAX];

int cont=1;

void clean(){
    route.clear();
    cl.clear();
    for(int i=0; i<MAX; i++){
        graph[i].clear();
        mark[i];
    }
    mp.clear();
}

int getValue(string a){
    int x;
     if(mp[a]!=NOT_VISIT){
            x= mp[a];
        }else{
            mp[a]=cont;
            cl.push_back(a);
            x=cont;
            cont++;
        }
    return x;
}

void putChild(edge parent){
    int child;
    for(int i=0; i<graph[parent.x].size(); i++){
        child=graph[parent.x][i];
        if(mark[child]==NOT_VISIT){
            pq.push({child,parent.cost+1,parent.x});
        }
    }
}

void dijkstra(){
    edge node;
    while(!pq.empty()){
        node = pq.top();
        pq.pop();
        if(mark[node.x]==NOT_VISIT){
            mark[node.x]=node.p;
            putChild(node);
        }
    }

}

void printRoute(string b){
    int a= getValue(b);
    route.push_back(b);
    while(mark[a]!=a){
        a=mark[a];
        route.push_back(cl[a-1]);
    }
    reverse(route.begin(),route.end());
    for(int i=0; i<route.size(); i++){
        if(i%2==0){
          if(i==0){
            cout<<route[i];
          }else{
            cout<<route[i]<<'\n'<<route[i];
          }
         }else {
             if(i==route.size()-1){
                cout<<' '<<route[i]<<'\n';
             }else cout<<' '<<route[i]<<'\n'<<route[i]<<' ';
        }
    }

}

void solve(){
    int n;
    while(true){
        cin>>n;
        string a,b;
        int x,y;
        for(int i=0; i<n; i++){
            cin>>a>>b;
            x=getValue(a);
            y=getValue(b);
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        cin>>a>>b;
        pq.push({getValue(a),1,mp[a]});
        dijkstra();

        if(mark[getValue(b)]==NOT_VISIT){
            cout<<"No route"<<'\n';
        }else{
            printRoute(b);
        }
        clean();
    }

}

int main(){
    solve();
    return 0;
}
