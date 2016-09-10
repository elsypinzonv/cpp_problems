#include <iostream>
#include <vector> 
#include <stack>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
 
struct UnionFind {

    int n; vector<int> padre, tam;

    UnionFind(int N) : n(N),
        tam(N, 1), padre(N) {
        while (--N) padre[N] = N;
    }

    int Raiz(int u) {
        if (padre[u] == u) return u;
        return padre[u] = Raiz(padre[u]);
    }

    bool SonConexos(int u, int v) {
        return Raiz(u) == Raiz(v);
    }

    void Unir(int u, int v) {
        int Ru = Raiz(u);
        int Rv = Raiz(v);
        if (Ru == Rv) return;
        --n, padre[Ru] = Rv;
        tam[Rv] += tam[Ru];
    }

    int Tamano(int u) {
        return tam[Raiz(u)];
    }
};

struct question
{
	char a;
	int x;
	int y;
};

const int MAXN = 20001;
long long arbol[MAXN];
bool cut[MAXN];
stack<string> r;
stack<question> q;

 void solve(){
 	int t;
 	int n,k;
 	cin>>t;
 	for(int i=0; i<t; i++){	
 		cin>>n>>k;
 		UnionFind uf(n+1);
 		for(int j=0; j<n; j++){
 			cin>>arbol[j];
 		}
 		char p;
 		int a,b;
 		bool flag;
 		for(int j=0; j<k; j++){
 			flag=false;
 			cin>>p;
 			if(p=='C'){
 				cin>>a;
 				if(cut[a-1]) flag=true;
 				cut[a-1]=true;
 			}else{
 				cin>>a>>b;
 			}
 			if(!flag) q.push({p,a-1,b-1});
 			flag=false;
 		}
 		for(int j=0; j<n; j++){
 			if(!cut[j]) {
 				if(arbol[j]!=0){
 					uf.Unir(j,arbol[j]-1);
 				}
 			}
 		}
 		question qe;
 		while(!q.empty()){
 			qe=q.top();
 			q.pop();
 			if(qe.a == 'Q'){
 				if(uf.SonConexos(qe.x, qe.y)){
 					r.push("YES");
 				} else r.push("NO");
 			}else{
 				if(arbol[qe.x]!=0){
 					uf.Unir(qe.x,arbol[qe.x]-1);
 				}
 			}
 		}

 		cout<<"Case #"<<(i+1)<<':'<<'\n';
 		while(!r.empty()){
 			cout<<r.top()<<'\n';
 			r.pop();
 		}

 		fill(cut, cut + MAXN , false);

 	}
 }

int main(){
	optimizar_io
	solve();
	return 0;
}