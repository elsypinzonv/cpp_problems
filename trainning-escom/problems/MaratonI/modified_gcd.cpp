#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);


vector<long long> v;

void div(long long res){
	long long root = sqrt(res);
	for(long long i=1LL; i<=root; i++){
		if(res%i==0){
			v.push_back(res/i); 
			v.push_back(i);
		}
	}
}

/*long long div(long long res,long long l ,long long h){
	long long root = sqrt(res);
	long long maxi=1;
	root=min(root,h);
	for(long long i=1LL; i<=root; i++){
		if(res%i==0){
			if((res/i) <= h) maxi=max(maxi,res/i); 
			if(i <= h) maxi = max(maxi,i);
		}
	}
	if(maxi<l) return 1;
	return maxi;
}*/

long long gcd(long long a, long long b){
	if(b==0) return a;
	return gcd(b,a%b);
}

void solve(){
	long long a,b;
	cin>>a>>b;
	long long t;
	long long l,h;
	long long x= gcd(a,b);
	div(x);
	cin>>t;
	long long maxi;
	for(long long i=0; i<t; i++){
		cin>>l>>h;	
		if(l<=x && x<=h){
			cout<<x<<'\n';
		}else{
			if(x<l){
				cout<<(-1)<<'\n';
			}else{
				maxi=-1;
				for(long long j=0; j<v.size(); j++){
					if(v[j]>=l && v[j]<=h){
						maxi=max(maxi,v[j]);	
					} 
				}
				cout<<maxi<<'\n';
			}

		}

	}
	
}

int main(){
	optimizar_io
	solve();
	return 0;
}
