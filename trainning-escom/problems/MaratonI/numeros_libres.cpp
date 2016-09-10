#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

map<int, int> primes;

bool printFactores(){
	bool flag=false;
	map<int, int>::iterator p = primes.begin();
	while (p != primes.end()){
	    //cout<<p->first<<' '<<p->second<<'\n';
	    if(p->second >1){
	    	flag=true;
	    	break;
	    }
	    p ++;
	} 
	return flag;
}

void getFactoresPrimos(long long a){
	int count=0;
	while(!(a%2)){
		a/=2;
		count++;
	}
	if (count) primes[2]=primes[2]+count;
	int root=sqrt(a);
	for(int i=3; i<=root; i++){
		count=0;
		while(!(a%i)){ 
			a/=i;
			count++;
		}
		if(count) primes[i]= primes[i]+count;
	}
	if(a>1) primes[a]= primes[a]+1;
}

void solve(){
	long long t;
	long long a,b;
	cin>>t;
	for(long long i=0ll; i<t; i++){
		cin>>a>>b;
		getFactoresPrimos(a);
		getFactoresPrimos(b);		
		if(printFactores()){
			cout<<"NO"<<'\n';
		}else cout<<"SI"<<'\n';
		primes.clear();
	}
	
}

int main(){
	optimizar_io
	solve();
	return 0;
}