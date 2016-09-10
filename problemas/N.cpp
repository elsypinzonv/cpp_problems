#include <iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

void solve(){
	int n;
	cin>>n;
	int p;
	int ta,tb;
	int nums[3];
	bool cont, color;
	for(int i=0; i<n; i++){
		ta=tb=0;
		cont=color=false;
		for(int j=0; j<3; j++){
			cin>>nums[j];
			ta+=nums[j];
			cout<<nums[j]<<' ';
		}
		int status=2; //0 win, 1 lose, 2 empate
		for(int j=0; j<3; j++){
			cin>>p;
			tb+=p;
			if(status!=0 && status!=1){
				if(nums[j]>p) status=0;	
				if(nums[j]<p) status=1;	
			}
			cout<<p;
			if(j!=2) cout<<' ';
		}cout<<'\n';
		
		if(ta>tb) cont=true;
		if(status==0) color=true;

		if(cont==true && color==true){
			cout<<"both"<<'\n';	
		} else{
			if(cont==false && color==false){
				cout<<"none"<<'\n'; 
			}else {
				if(cont==true){
					cout<<"count"<<'\n';
				}else cout<< "color"<<'\n';
			}
		}



	}
}

int main(){
	optimizar_io
	solve();
	return 0;
}