#include<iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

long long gcd(long long a, long long b){
	if(b==0) return a;
	return gcd(b,a%b);
}


void solve(){
	long long a,b,t;
	cin>>t;
	for(long long i=0LL; i<t; i++){
		cin>>a>>b;
		if(gcd(a,b)==1LL){
			cout<<"SI"<<'\n';
		}else cout<<"NO"<<'\n';
	}

}

int main(){
	optimizar_io
	solve();
	return 0;
}
