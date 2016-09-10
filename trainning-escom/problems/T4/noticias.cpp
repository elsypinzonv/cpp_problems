#include <iostream>
#include <vector>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

vector<vector<long long>> grafo;

struct UnionFind {
    long long nconjuntos;
    vector<long long> padre;
    vector<long long> tamano;

    UnionFind(long long n) : nconjuntos(n),
        padre(n), tamano(n, 1) {
        for(long long i = 0LL; i < n; ++i)
            padre[i] = i;
    }

    long long Encontrar(long long u) {
        if (padre[u] == u) return u;
        return padre[u] = Encontrar(padre[u]);
    }

    void Unir(long long u, long long v) {
        long long Ru = Encontrar(u);
        long long Rv = Encontrar(v);
        if (Ru == Rv) return;
        --nconjuntos, padre[Ru] = Rv;
        tamano[Rv] += tamano[Ru];
    } 

    bool MismoConjunto(long long u, long long v) {
        return Encontrar(u) == Encontrar(v);
    }

    long long TamanoConjunto(long long u) {
        return tamano[Encontrar(u)];
    }
};


void solve(){
	long long n,i;
	cin>>n>>i;
	char s;
	long long x,y;

	UnionFind uf(n+1);
	for(long long j=0LL; j<i; j++){
		cin>>s;
		if(s=='A'){
			cin>>x>>y;
			uf.Unir(x,y);
		}else{
			cin>>x;
			cout<<uf.TamanoConjunto(x)<<'\n';
		}
	}
}

int main(){
	optimizar_io
	solve();
	return 0;
}