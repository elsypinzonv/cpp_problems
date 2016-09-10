#include <iostream>
#include <cmath>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

long long expp;

void acumuladoFactorial(long long n, long long p, long long flag){
	
	long long a = n/p;
	while(a){
		expp += a*flag;
		a /= p;
	}		
}

void solve(){
	long long a,b,p;
	while(cin >>a>>b>>p){
		expp=0;
		acumuladoFactorial(b,p,1LL);
		acumuladoFactorial(a-1,p,-1LL);
		cout<<oct<<expp<<'\n';
	}
}

int main(){
	optimizar_io
	solve();
	return 0;
}