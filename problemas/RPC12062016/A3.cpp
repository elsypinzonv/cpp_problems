#include<iostream>
#include<algorithm>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);


struct Fraccion {

	long num;
	long den;

	Fraccion(long n, long d){
		long gcd=__gcd(n,d);
		num=n/gcd;
		den=d/gcd;
		if(den<0){
			num*=-1;
			den*=-1;
		}
	}

	bool operator<(const Fraccion & f){
		//if(f.den==0) return
		return  num*f.den  < f.num*den;
	}

};



void solve(){
	int T;
	long long k,d;
	cin>>T;
	string name;
	for(int i=0; i<T; i++){
		Fraccion LOOSE(1,3);
		for(int i=0; i<5; i++){
			cin>>name;
			cin>>k>>d;	
			Fraccion a(k,d);
			if(a<LOOSE){
				cout<<name<<' '<<"plz uninstall"<<'\n';
			}
		}
	}
	


}

int main(){
	optimizar_io
	solve();
	return 0;
}