#include<iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

void solve(){
	int n,k;
	cin>>n>>k;
	int res=0;
	for(int i=2ll; i<=n; i++){
		res=((res+k)%i);
	}
	cout<<(res+1)<<'\n';
}

int main(){
	optimizar_io
	solve();
	return 0;
}