#include<iostream>
#include<cmath>
#include<bitset>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

long long const MAXN=400001;
//long long const MAXN=4000001;

bitset<MAXN + 1> primes;
long long n;
long long maxN;

void getNextPrimo(){
	bool flag;
	for(long long i=n; true; i++){
		flag=false;
		long long root = sqrt(i);
		for(long long j=2; j<=root; j++){
			if(!primes[j]){
				if(i%j==0){
					flag=true;
					break;
				}
			}
		}
		if(!flag){
			cout<<i<<'\n';
			break;
		}
	}

}

void sieve(){
	primes[0]=primes[1]=1;	
	for(long long i=2LL*2LL; i<=MAXN; i+=2LL){
		primes[i]=1;
	}
	//long long root = sqrt(MAXN);
	for(long long i=3LL; i<=MAXN; i+=2LL){
		if(primes[i]) continue;
		for(long long j=i*i; j<=MAXN; j+=i){
				primes[j]=1;
		}	
		
		
	}

}

void solve(){
	long long t;
	cin>>t;
	sieve();
	for(int i=0; i<t; i++){
		cin>>n;
		if(n==0 || n==1){
			cout<<2<<'\n';
			continue;
		}
		getNextPrimo();
	}
	
}

int main(){
	optimizar_io
	solve();
	return 0;
}