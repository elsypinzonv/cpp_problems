#include<iostream>
#include<cmath>
#include <bitset>
#include <vector>
#include <string>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

long long const MAXN=1000001;
bitset<MAXN + 1> primes;
long long n; //=50LL;
long long mult=1;
long long m=10000000000;
string p[1000001];

void printPrimes(){
	mult=1;
	for(int i=2; i<MAXN; i++){
		if(!primes[i]){
			mult=((i*mult)%m);
		}
		string s= to_string(mult);
		while(s.size()<10 && i>30){
				s="0"+s;
		}
		p[i]= s;
	}
}

void sieve(){
	primes[0]=primes[1]=1;
	for(long long i=2LL*2LL; i<=MAXN; i+=2LL){
		primes[i]=1;
	}
	long long root = sqrt(MAXN);
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
	printPrimes();		
	string s;
	for(long long i=0; i<t; i++){
		cin>>n;
		cout<<p[n]<<'\n';
	} 
}

int main(){
	optimizar_io
	solve();
	return 0;
}