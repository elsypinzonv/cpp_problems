#include <iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

void solve(){
	int t;
	cin>>t;
	int n,m;
	bool b;
	for(int i=0; i<t; i++){
		cin>>n;
		b=true;
		for(int j=0; j<4; j++){
			cin>>m;
			if(n != m-1) b=false;
			n=m;
		}
		if(b){
			cout<<'Y'<<'\n';	
		} else cout<<'N'<<'\n';
		
	}

}

int main(){
	optimizar_io
	solve();
	return 0;
}