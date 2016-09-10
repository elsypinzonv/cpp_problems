#include <iostream>
#include <vector> 
#include <queue>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
 

const int MAXN = 1000001;
const int LOGN = 21;

int logs[MAXN];
int nivel[MAXN];
int padre[MAXN][LOGN];
int paps[MAXN]; //MI GRAFO
int raiz=1;

void CalcularPadres(int n) {
    for (int i = 2; i < n; ++i)
        logs[i] = logs[i >> 1] + 1;
    for (int u = 0; u < n; ++u) {
        padre[u][0] = paps[u];
    }
    padre[raiz][0] = raiz;
    for (int i = 1; i < LOGN; ++i) {
        for (int u = 0; u < n; ++u) {
            padre[u][i] = padre[padre[u][i - 1]][i - 1];
        }
    }
}

int LCA(int u, int v) {
    if (nivel[v] > nivel[u]) swap(u, v);
    int h = nivel[u] - nivel[v];
    for (int i = 0; 1 << i <= h; ++i)
        if (h & 1 << i) u = padre[u][i];
    if (u == v) return u;
    for (int i = LOGN - 1; i >= 0; --i)
        if (padre[u][i] != padre[v][i])
            u = padre[u][i], v = padre[v][i];
    return padre[u][0];
}

struct node
{
	int x;
	int padre;
	int niv;
};

vector<int> graf[MAXN];
queue<node> q;

void BFS(){
	node nod;
	while(!q.empty()){
		nod=q.front();
		q.pop();
		if(paps[nod.x]==0){	
			for(int i=0; i<graf[nod.x].size(); i++){
				if(paps[graf[nod.x][i]]==0){
					q.push({graf[nod.x][i],nod.x, nod.niv+1});
				}
			}
			paps[nod.x]=nod.padre;
			nivel[nod.x]=nod.niv;
		}
	}
}

 void solve(){
 	int n,k;
 	cin>>n>>k;
 	int v,u;
 	for(int i=0; i<(n-1); i++){
 		cin>>v>>u;
 		graf[v].push_back(u);
 		graf[u].push_back(v);
 	}
 	q.push({1,-1,0});
 	BFS();
 	paps[1]=0;
 	int a,b;
 	CalcularPadres(n+1);
 	for(int i=0; i<k; i++){
 		cin>>a>>b;
 		if(a==b || a==1){ //matando a 1 igual
 			cout<<0<<'\n';
 		}else if(nivel[a]>=nivel[b]){
 			cout<<1<<'\n';
 		}else{
 			cout<<0<<'\n';
 			if(LCA(a,b)==a){
 				cout<<0<<'\n';
 			} else cout<<1<<'\n'; 
 		}
 	} 
 }

 int main(){
	optimizar_io
	solve();
	return 0;
}