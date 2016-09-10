#include <iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

void solve(){

	int t,n,k,sum;
	cin>>t;
	for(int i =0; i<t; i++){
		cin>>n>>k;
		sum=0;
		for(int j=1; j<=n/2; j++){
			if(j%k!=0 && n%j==0) sum+=j;		  
		}
		if(n%k!=0) sum+=n;
		cout<<sum<<'\n';
	}


}

int main(){
	optimizar_io
	solve();
	return 0;
}