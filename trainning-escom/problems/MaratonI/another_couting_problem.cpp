#include<iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

long exponenciar(long long a, long long n, long long m){
	long long res=1;
	for(; n; n>>=1){
		if(n & 1) res= (res*a)%m;
		a=(a*a)%m;
	}
	return res;
}

void solve(){
	long long n,c,m;
	cin>>n>>c>>m;
	cout<<exponenciar(c,n,m)<<'\n';
}

int main(){
	optimizar_io
	solve();
	return 0;
}