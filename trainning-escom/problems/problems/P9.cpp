#include<iostream>
#include<bitset>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

int const MAXN=1025;
//long long const MAXN=64;
bitset<MAXN + 1> players;
int result;
int cont;

long expp(long  a, long n, long m){
	long res=1;
	for(; n; n>>=1){
		if(n & 1) res= (res*a)%m;
		a=(a*a)%m;

	}
	return res;
}

void solve(){
	int t;
	cin>>t;
	int n,m;
	for(int i=0; i<t; i++){
		cin>>n>>m;
		int p;
		for(int j=0; j<m; j++){
			cin>>p;
			players[p]=1;
		}
		result=0;
		while(n){
			cont=1;
			for(int j=2; j<=(1<<n); j+=2){
				if((players[j]==true && players[j-1]==false) || (players[j]==false && players[j-1]==true)) result++;

				if((players[j]==true && players[j-1]==false) || (players[j]==false && players[j-1]==true)){
					players[cont]= false;//min(players[j], players[j+1]);
				}else{
					if(players[j]==0 && players[j-1]==0){
						players[cont]= false;	
					} else players[cont]= 1;
				}

				cont++;
			}
			n--;
		}
		cout<<result<<'\n';
	}
	players.reset();
}

int main(){
	optimizar_io
	solve();
	return 0;
}