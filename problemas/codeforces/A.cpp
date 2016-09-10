#include<iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);


bool bandera;

void solve(){
	int n;
	string name;
	cin>>n;

	long long after,before;
	for(int i=0; i<n; i++){
		cin>>name;
		cin>>after>>before;
		if(after>=2400){
			if(before>after){
				bandera=true;
			}
		}

	}
	if(bandera){
		cout<<"YES"<<'\n';
	} else cout<<"NO"<<'\n';

}

int main(){
	optimizar_io
	solve();
	return 0;
}