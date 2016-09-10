//https://omegaup.com/arena/problem/findprime#problems
#include<iostream>
#include<cmath>
#include<bitset>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

long long const MAXN=9832718;
bitset<MAXN + 1> primes;
long long cont=0;
long long n;

void printN(){
	for(long long i=1LL; i<=MAXN; i++){
		if(!primes[i]){
			cont++;
			if(cont==n) cout<<i<<'\n';
		}
	}
}

void sieve(){
	primes[0]=primes[1]=1;
	for(long long i=2LL*2LL; i<=MAXN; i+=2LL){
		primes[i]=1;
	}
	long long root= sqrt(MAXN);
	for(long long i=3LL; i<=root; i+=2LL){
		if(primes[i]) continue;
		for(long long j=i*i; j<=MAXN; j+=i){
			primes[j]=1;
		}
	}
}

void solve(){
	cin>>n;
	sieve();
	printN();
}

int main(){
	optimizar_io
	solve();
	return 0;
}