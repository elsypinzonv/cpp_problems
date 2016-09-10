#include <iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

void solve(){
	int n;
	cin>>n;
	int p;
	int anterior;
	int sum, num;
	for(int i=0; i<n; i++){
		anterior=-1;
		sum=0;
		while(cin>>p and p){
			if(anterior == -1){
				anterior=p;
				continue;
			} 
			num=p-(2*anterior);
			if(num>0) sum+=num;
			anterior=p;
		}
		cout<<sum<<'\n';
	}
}

int main(){
	optimizar_io
	solve();
	return 0;
}