#include<iostream>
#include<cmath>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

long long const MAXN=100;
long long sieve[MAXN + 1];
long long expp[MAXN + 1];
long long n;

string getFormat(long long n){
	string s = to_string(n);
	while(s.size()<3){
		s=" "+s;
	}
	return s;
}

void printPrimes(){
	cout<<getFormat(n);
	cout<<'!'<<" =";
	long long cont=0LL;
	for(long long i=1LL; i<=n; i++){
		if(expp[i]!=0){
			if(cont>14){
				cont=0;
				cout<<'\n'<<"      ";
			}
			cout<<getFormat(expp[i]);
			cont++;
		}
	}
}

void acumuladoFactorial(){
	fill(expp+2, expp + n + 1, 1); //duda: mi libreta tiene exp+2
	for(long long i=n; i>3LL; --i){
		if(!sieve[i]) continue; //Si es primo.
		expp[sieve[i]]+=expp[i];
		expp[i/sieve[i]]+=expp[i];
		expp[i]=0;
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
	cin>>n;
	while(n != 0){
		acumuladoFactorial();
		printPrimes();
		fill(expp,expp+n,0);
		cout<<'\n';
		cin>>n;

	}
}

int main(){
	optimizar_io
	solve();
	return 0;
}