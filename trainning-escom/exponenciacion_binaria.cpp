#include<iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

long exponenciar(long  a, long n, long m){
	long res=1;
	for(; n; n>>=1){
		if(n & 1) res= (res*a)%m;
		a=(a*a)%m;

	}
	return res;
}

void solve(){
	long a,n,m;
	cin>>a>>n>>m;
	cout<<exponenciar(a,n,m)<<'\n';
}

int main(){
	optimizar_io
	solve();
	return 0;
}