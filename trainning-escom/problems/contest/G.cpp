#include <iostream>
#include <vector> 
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
 
int const MAXN=1000001;
int gana[MAXN];
int pierde[MAXN];

void fills(int n){
	for(int i=1; i<=n; i++){
		pierde[i]=n-i;
		gana[i]=i-1;
	}
}

void printA(int n){
	for(int i=1; i<=n; i++){
		cout<<i<<' ';
	}cout<<'\n';

	for(int i=1; i<=n; i++){
		cout<<pierde[i]<<' ';
	}cout<<'\n';

	for(int i=1; i<=n; i++){
		cout<<gana[i]<<' ';
	}
}

void recorrer(int n){
	long long win;
	bool ban=false;
	for(int i=n; i>0; i--){
		if(pierde[i]==0 && gana[i]!=0){
			cout<<2<<' '<<i<<'\n';
			ban=true;
			break;
		}
		if(gana[i]>0) win++;
		if(win>=3){
			cout<<1<<'\n';
			ban=true;
			break;
		}
	}
	if(!ban){
		cout<<0<<'\n';
	}

}
 void solve(){
 	long long t;
 	cin>>t;
 	long long n,m;
 	int x,y;
 	for(long long i=0LL; i<t; i++){
 		cin>>n>>m;
 		fills(n);
 		for(long long j=0; j<m; j++){
 			cin>>x>>y;
 			gana[x]+=1;
 			pierde[x]-=1;
 			pierde[y]+=1;
 			gana[y]-=1;
 		}
 		recorrer(n);
 	}
 }

 int main(){
	optimizar_io
	solve();
	return 0;
}