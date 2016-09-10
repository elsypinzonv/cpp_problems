#include<iostream>
#include<cmath>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

long long const MAXN=1000001;
long long sieve[MAXN + 1];
long long xxn[MAXN + 1];
long long xxk[MAXN + 1];
long long xxnk[MAXN + 1];

long long printCombin(long long n){
	long long mult=1;
	for(long long i=1LL; i<=n; i++){
		if(xxn[i]!=0){
			mult*=pow(i,xxn[i]);
		}
	}
	return mult;
}

void multiplicar(long long n){
	for(long long i=0; i<=n; i++){
		xxn[i]-=(xxk[i]+xxnk[i]);
	}
}

	
void acumuladoFactorial(long long n, long long* expp){
	for(int i=2; i<=n; i++){
		if(!sieve[i]){
			int p = i;
			while(p <= n){
				expp[i] += (n/p);
				p *= i;
			}	
		}
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
	long long t;
	cin>>t;
	sieveMark();
	long long n,k;
	for(long long i=0LL; i<t; i++){
		cin>>n>>k;
		acumuladoFactorial(n-1,xxn);
		acumuladoFactorial(k-1,xxk);
		acumuladoFactorial((n-1)-(k-1), xxnk);
		multiplicar(n);
		cout<<printCombin(n)<<'\n';
		fill(xxn,xxn+n,0);
		fill(xxk,xxk+n,0);
		fill(xxnk,xxnk+n,0);
	}
	
}

int main(){
	optimizar_io
	solve();
	return 0;
}