#include<iostream>
#include<cmath>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

long long n;
long long const MAXX=65;
long long divisor[MAXX]={0LL,1LL,2LL,4LL,6LL,16LL,12LL,64LL,24LL,36LL,48LL,1024LL,60LL,4096LL,192LL,144LL,120LL,65536LL,180LL,262144LL,240LL,576LL,3072LL,4194304LL,360LL,1296LL,12288LL,900LL,960LL,268435456LL,720LL,1073741824LL,840LL,9216LL,196608LL,5184LL,1260LL,68719476736LL,786432LL,36864LL,1680LL,1099511627776LL,2880LL,4398046511104LL,15360LL,3600LL,12582912LL,70368744177664LL,2520LL,46656LL,6480LL,589824LL,61440LL,4503599627370496LL,6300LL,82944LL,6720LL,2359296LL,805306368LL,288230376151711744LL,5040LL,1152921504606846976LL,3221225472LL,14400LL,7560LL};

long long exponenciar(long long a, long long n) {
    long long res = 1, p = a;
    for (; n; n >>= 1) {
        if (n & 1) res =
            (res * p);
        p = (p * p);
    }
    return res;
}

void print(){
	for(long long j=1; j<MAXX; j++){
		if(divisor[j]==0){
			cout<<j<<endl;
			if((j)%2==0){
				divisor[j]=(1LL<<((j/2)-1)); 
				divisor[j]*=3;
			}else if(j%3==0){
				divisor[j] = (1LL<<((j/3)-1));
				divisor[j]*= 9;
			} else divisor[j] = (1LL<<(j-1));
			
		} 		
	}

	for(long long j=1; j<MAXX; j++){
		cout<< divisor[j]<<"LL"<<",";		
	}cout<<'\n';  
}

void div(){

	long long divs=0;
	for(long long j=1; j<=1000000; j++){
		divs=0;
		for(long long i=1; i*i <=j; i++){
			if(j%i==0){
				divs++;
				if(j/i != i)
					divs++;
			}
		}
		if(divs<65){
			if(divisor[divs]==0) divisor[divs] = j;
		}

				
	}

}

void solve(){
	long long t;
	cin>>t;
	//div(); 
	/*for(long long j=1; j<MAXX; j++){
		if(divisor[j] != divisor2[j]) cout<<j<<' ';
		//cout<< divisor[j]<<" ";		
	}cout<<'\n'; */
	//print();

	long long a;
	for(long long i=0LL; i<t; i++){
		cin>>a;
		cout<<divisor[a]<<'\n';		
	}

}

int main(){
	optimizar_io
	solve();
	return 0;
}