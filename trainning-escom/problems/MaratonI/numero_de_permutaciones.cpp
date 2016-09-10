#include<iostream>
#include<cmath>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

long long const MAXN=1000001;
long long sieve[MAXN + 1];
long long xxn[MAXN + 1];
long long letters[26];

void countChars(string s){
	for (long long i = 0; i < s.length(); i++) {
    	char c = s[i];
    	letters[c-'a'] += 1;
    }
}

long long exponenciar(long long a, long long n, long long m) {
    long long res = 1, p = a;
    for (; n; n >>= 1) {
        if (n & 1) res =
            (res * p) % m;
        p = (p * p) % m;
    }
    return res;
}


long long printCombin(long long n){
	long long mult=1;
	for(long long i=1LL; i<=n; i++){
		if(xxn[i]!=0){
			mult*=exponenciar(i,xxn[i],10);
			mult%=10;
		}
	}
	return mult;m
}

void truco(){
	long long minExp=min(xxn[5], xxn[2]);
	xxn[2]-=minExp;
	xxn[5]-=minExp;
}
	
void acumuladoFactorial(long long n, long long* expp, long long flag){
	for(long long i=2LL; i<=n; i++){
		if(!sieve[i]){
			long long p = n/i;
			while(p){
				expp[i] += flag*p;
				p /= i;
			}	
		}
	}
}

void sieveMark(){
	sieve[0]=sieve[1]=1LL;
	for(long long i=2LL*2LL; i<=MAXN; i+=2LL){
		sieve[i]=2LL;
	}
	long long root = sqrt(MAXN);
	for(long long i=3LL; i<=root; i+=2LL){
		if(sieve[i]) continue; //Es que no es primo
		for(long long j=i*i; j<=MAXN; j+=i){
			if (!sieve[j]) sieve[j]=i;
		}
	}
}

void solve(){
	long long t;
	cin>>t;
	sieveMark();
	string s;
	long long n;
	for(long long i=0LL; i<t; i++){
		cin>>s;
		n=s.size();
		countChars(s);
		acumuladoFactorial(n,xxn,+1);
		for(long long i=0LL; i<26; i++){
			if(letters[i]){
				acumuladoFactorial(letters[i], xxn, -1);
			}
		}
		truco();
		cout<<printCombin(n)<<'\n';
		fill(xxn,xxn+MAXN,0);
		fill(letters,letters+26,0); 
	}
	
}

int main(){
	optimizar_io
	solve();
	return 0;
}