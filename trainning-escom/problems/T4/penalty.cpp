#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);


void solve(){
	long long g,a,t,d;
	long long x,y;
	cin>>g>>a>>t>>d;
	while(g!=-1 && a!=-1 && t!=-1 d!=-1){
		
		cout<<g<<"*"<<a<<"/"<<t<<"+"<<d<<"="<<x<<"+"<<y<<"\n";	
		cin>>g>>a>>t>>d;
	}
	
}

int main(){
	optimizar_io
	solve();
	return 0;
}