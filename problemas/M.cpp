#include <iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

void solve(){
	int n;
	cin>>n;
	bool m,z;
	int p;
	for(int i=0; i<n; i++){
		m=z=false;
		for(int j=0; j<10; j++){
			cin>>p;
			if(p==18) m=true;
			if(p==17) z=true;
			cout<<p;
			if(j!=9) cout<<' ';
		}cout<<'\n';
		if(m==true && z==true){
			cout<<"both"<<'\n';	
		} else{
			if(m==false && z==false){
				cout<<"none"<<'\n'; 
			}else {
				if(m==true){
					cout<<"mack"<<'\n';
				}else cout<< "zack"<<'\n';
			}
		}
	}
}

int main(){
	optimizar_io
	solve();
	return 0;
}