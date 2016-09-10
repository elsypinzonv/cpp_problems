#include<iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

long multiplicar(long  a, long b, long m){
	long res=0;
	for(; b; b>>=1){
		if(b & 1) res= (res+a)%m;
		a=(a+a)%m;
	}
	return res;
}

void solve(){
	long a,b,m;
	cin>>a>>b>>m;
	cout<<multiplicar(a,b,m)<<'\n';
}

int main(){
	optimizar_io
	solve();
	return 0;
}