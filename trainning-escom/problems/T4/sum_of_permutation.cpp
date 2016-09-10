#include <iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

long long const MAXN=1000001;
long long MOD = 1000003;
long long s[MAXN];


void sumar(int n){
	s[1]=1;
	for(long long i=2LL; i<=n; i++){
		s[i]=(1 + ((i%MOD*(s[i-1]%MOD))%MOD)%MOD);
	}
}

void solve(){
	long long t,n;
	cin>>t;	
	sumar(MAXN-1);
	for(long long i=0LL; i<t; i++){
		cin>>n;
		cout<<s[n]<<'\n';
	}
}

int main(){
	optimizar_io
	solve();
	return 0;
}