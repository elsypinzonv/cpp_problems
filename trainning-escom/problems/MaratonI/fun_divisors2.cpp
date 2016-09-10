#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

long long const MAXN=100000001;
long long const MAXX=65;
long long divisor[MAXX];
long long sieve[MAXN + 1];
typedef pair<long long ,long long> pii;


void printFactores(vector<pii> facts,long long k){
	long long divs=0;
	for(int i=0; i<facts.size(); i++){	
		divs*=(facts[i].second+1);
	}
	if(divisor[divs]==0){
		divisor[divs]=k;
		cout<<divisor[divs]<<' '<<k<<'\n';	
	} 

}

void sieveMark(){
	sieve[0]=sieve[1]=1LL;
	for(long long i=2LL*2LL; i<=100; i+=2LL){
		sieve[i]=2LL;
	}
	long long root = sqrt(100);
	for(long long i=3LL; i<=root; i+=2LL){
		if(sieve[i]) continue; //Es que no es primo
		for(long long j=i*i; j<=100; j+=i){
			if (!sieve[j]) sieve[j]=i;
		}
	}
}

vector<pii> getFactoresPrimos(long long a){
	long long count=0LL;
	while(!(a%2)){
		a/=2;
		count++;
	}
	vector<pii> facts;
	if(count) facts.push_back(pii(2,count));
	long long root=sqrt(a);
	for(long long i=3; i<=root; i+=2){
		count=0;
		while(!(a%i)){
			a/=i;
			count++;
		}
		if(count) facts.push_back(pii(i,count));
	}
	if(a>1) facts.push_back(pii(a,1));
	return facts;
}

void solve(){
	sieveMark();
	for(int i=0; i<MAXN; i++){
		printFactores(getFactoresPrimos(i),i);
	}
}

int main(){
	//optimizar_io
	solve();
	return 0;
}