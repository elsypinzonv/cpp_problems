#include <iostream>
#include <vector> 
#include <stack>
#include <queue>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

typedef int Costo;
const Costo INF = 1 << 30;

typedef pair<int, int> Arista;
typedef pair<Costo, int> CostoNodo;
typedef pair<Costo, Arista> Ponderada;



struct GrafoPonderado {
	int n;
	bool bi;
    vector<vector<CostoNodo>> ady;

	GrafoPonderado(int N, bool B = true)
        : n(N), bi(B), ady(N) {}
	
	void AgregarArista(int u, int v, Costo c) {
		if (bi) ady[v].push_back(CostoNodo(c, u));
	        ady[u].push_back(CostoNodo(c, v));
	}

    vector<Costo> Dijkstra(int s) {
        vector<Costo> dist(n, INF);
        priority_queue<CostoNodo> pq;
        pq.push(CostoNodo(0, s)), dist[s] = 0;
		while (!pq.empty()) {
			Costo p = -pq.top().first;
			int u = pq.top().second; pq.pop();
			if (dist[u] < p) continue;
			for (CostoNodo arista : ady[u]) {
				int v = arista.second;
				p = dist[u] + arista.first;
				if (p < dist[v]) dist[v] = p,
				    pq.push(CostoNodo(-p, v));
			}
        }
		return dist;
    }

    vector<Costo> Dijkstra(int s, vector<Costo>& minu,vector<Costo>& minv,int x) {
        vector<Costo> dist(n, INF);
        priority_queue<CostoNodo> pq;
        pq.push(CostoNodo(0, s)), dist[s] = 0;
		while (!pq.empty()) {
			Costo p = -pq.top().first;
			int u = pq.top().second; pq.pop();
			if (dist[u] < p) continue;
			for (CostoNodo arista : ady[u]) {
				int v = arista.second;
				if(minu[u]+arista.first+ minv[v]==x || minu[v]+arista.first+ minv[u]==x) continue;
				p = dist[u] + arista.first;
						if (p < dist[v]) dist[v] = p,
				    pq.push(CostoNodo(-p, v));
			}
        }
		return dist;
    }
};

void solve(){
	int n,m;
	while(cin>>n>>m and (n or m)){
		int u,v,w;
		GrafoPonderado graf(n);
		vector<Costo> minu, minv, res;
		for(int i=0; i<m; i++){
			cin>>u>>v>>w;
			graf.AgregarArista(u-1,v-1,w);
		}
		minu=graf.Dijkstra(0);
		minv=graf.Dijkstra(n-1);
		res=graf.Dijkstra(0,minv,minu,minu[n-1]);
		if(res[n-1]==INF){
			cout<<"Do'oh!\n";
		}else cout<<res[n-1]<<'\n';	
	}
	
}

int main(){
	optimizar_io
	solve();
	return 0;
}