#include <iostream>
#include <vector>
#include <algorithm>
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

Vector sols;
Bector solf;

void solve(){
	long long p;
	long long row,colum;
	string d;
	string a,b;
	bool flag;
	bool notSolution; 
	bool arbitrary;
	long long cont;
	long long zero;
	long long aux;
	bool first=false;
	while(cin>>p and p){
		cin>>colum>>row;
		if(first)cout<<'\n';
		long long maxi= max(row,colum+1);
		Matriz mat(maxi,vector<Fraccion>(maxi));
		for(int i=0; i<row; i++){
			for(int j=0; j<=colum; j++){
				cin>>d;
				size_t found = d.find("/");
				if(found!=std::string::npos){ 
					a=d.substr (0,found);
					b=d.substr (found+1,d.size()); 
					mat[i][j]=Fraccion(stoi(a),stoi(b));
    			}else  mat[i][j]=Fraccion(stoi(d),1);
			}
		}

		EliminacionGaussiana(mat);

		cont=0;
		zero=0;
		notSolution=false;
		for(int i=0; i<row; i++){
			flag=false;
			arbitrary=false;
			for(int j=0; j<=colum; j++){
				Fraccion f=mat[i][j];
				if(j==0 && f.num ==0) 
					flag=true;
				if(i==j && f.num!=0){
					cont++;
					//cout<<cont<<' ';	
				}  
				if(i==j && f.num==0){
					aux=0;
					for(int k=0; k<=row; k++){
						if(mat[i][k].num!=0) aux++;
					}
					if(aux==1) cont++;
				} 

				if(j == (colum) && flag==true && f.num!=0){
					notSolution=true;
				}
				if(flag==true & f.num!=0) flag=false;
			} 
			if(notSolution==true) break;
		}

		if(notSolution){
			cout<<"Solution for Matrix System # "<<p<<'\n';
			cout<<"No Solution."<<'\n';
		}else{
			if(cont<colum){
				if(cont==0) cont=1;
				cout<<"Solution for Matrix System # "<<p<<'\n';
				//cout<<"Infinitely many solutions containing "<<zero<<" arbitrary constants."<<'\n';
				cout<<"Infinitely many solutions containing "<<(colum-cont)<<" arbitrary constants."<<'\n';

			}else{
				cout<<"Solution for Matrix System # "<<p<<'\n';
				for(long long i=0LL; i<row; i++){
					if(i<colum){
						Fraccion f=mat[i][colum];
						cout<<"x["<<(i+1)<<"] = ";
						cout<<f.num;
						if(f.den!=1 && f.num!=0) cout<<'/'<<f.den;
						cout<<'\n';	
					}
					
				} 
			}
		}
		first=true;
		//
	}
}

int main(){
	optimizar_io
	solve();
	return 0;
}