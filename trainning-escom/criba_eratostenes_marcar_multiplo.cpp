#include<iostream>
#include<cmath>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

long long const MAXN=50;
long long sieve[MAXN + 1];

void printPrimes(){
	for(long long i=1LL; i<=MAXN; i++){
	//if(primes[i]!=0){
			cout<<sieve[i]<<' ';
	//	}
	}
}

void sieveMark(){
	sieve[1]=1;
	for(long long i=2LL*2LL; i<=MAXN; i+=2LL){
		sieve[i]=2LL;
	}
	long long root = sqrt(MAXN);
	for(long long i=3LL; i<=root; i+=2LL){
		if(sieve[i]) continue;
		for(long long j=i*i; j<=MAXN; j+=i){
			if (!sieve[j]) sieve[j]=i;
		}
	}

}

void solve(){
	sieveMark();
	printPrimes();
}

int main(){
	optimizar_io
	solve();
	return 0;
}