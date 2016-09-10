#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long Long;

struct Fraccion {
	Long num, den;
	Fraccion() : num(0), den(1) {}
	Fraccion(Long n, Long d) {
		if (d < 0) n = -n, d = -d;
		Long gcd = __gcd(abs(n), abs(d));
		num = n / gcd, den = d / gcd;
	}

	Fraccion operator-() const {
		return Fraccion(-num, den);
	}

	Fraccion operator+(const Fraccion& f) {
		Long gcd = __gcd(den, f.den);
		return Fraccion(
			num * (f.den / gcd) +
			f.num * (den / gcd),
			den * (f.den / gcd)
		);
	}

	Fraccion operator-(const Fraccion& f) {
		return *this + -f; // a - b = a + (-b)
	}

	Fraccion operator*(const Fraccion& f) {
		return Fraccion(num * f.num, den * f.den);
	}

	Fraccion operator/(const Fraccion& f) {
		return Fraccion(num * f.den, den * f.num);
	}

	bool operator<(const Fraccion& cmp) {
		Long gcd = __gcd(den, cmp.den);
		return num * (cmp.den / gcd) <
			   cmp.num * (den / gcd);
	}

	bool operator==(const Fraccion& cmp) {
		Long gcd = __gcd(den, cmp.den);
		return num * (cmp.den / gcd) ==
			   cmp.num * (den / gcd);
	}
};

typedef vector<Fraccion> Vector;
typedef vector<Vector> Matriz;
typedef vector<bool> Bector;

Fraccion fabs(const Fraccion& f) {
	return Fraccion(abs(f.num), f.den);
}

bool EsCero(const Fraccion& f) {
	return f.num == 0;
}

void EliminacionGaussiana(Matriz& m) {
    for (int i = 0; i < m.size(); ++i) {
        int fila_mayor = i;
        for (int j = i + 1; j < m.size(); ++j)
            if (fabs(m[fila_mayor][i]) <
                fabs(m[j][i])) fila_mayor = j;
        swap(m[i], m[fila_mayor]);
        if (EsCero(m[i][i])) continue;
        for (int j = m[i].size() - 1; j >= i; --j)
            m[i][j] = m[i][j] / m[i][i];
        for (int j = 0; j < m.size(); ++j) {
            if (i == j || EsCero(m[j][i])) continue;
            for (int k = m[j].size() - 1; k >= i; --k)
                m[j][k] = m[j][k] - m[i][k] * m[j][i];
        }
    }
}

const int MAXN=37;
mat[MAXN][MAXN];

void fillMat(int m){
	for(int i=1; i<=m; i++){
		if(i+1)
	}
}


void solve(){
	int n,m;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>m;
	}
	//Matriz mat(maxi,vector<Fraccion>(maxi));
}

int main(){
	optimizar_io
	solve();

	return 0;
}