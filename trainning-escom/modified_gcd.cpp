#include<iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

long long gcd(long long a, long long b){
	if(b==0) return a;
	return gcd(b,a%b);
}

void solve(){
	long long a,b;
	cin>>a>>b;
	long long t;
	long long l,h;
	cin>>t;
	for(long long i=0; i<t; i++){
		cin>>l>>h;	
		long long x= gcd(a,b);
		if(l<=x && x<=h){
			cout<<x<<'\n';
		}else{
			if(x<l){
				cout<<(-1)<<'\n';
			}else{
				cout<<"te la creiste"<<'\n';
			}

		}

	}
	
}

int main(){
	optimizar_io
	solve();
	return 0;
}
