#include<iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

long long gcd(long long a, long long b){
	if(b==0) return a;
	return gcd(b,a%b);
}

void solve(){
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b)<<'\n';
}

int main(){
	optimizar_io
	solve();
	return 0;
}
