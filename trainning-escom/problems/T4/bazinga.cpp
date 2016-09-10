#include <iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

bool getResult(string s, string r){
	if(s=="tesoura"){
		if(r=="papel" || r == "lagarto") return true;
		return false;
	} 

	if(s=="papel"){
		if(r=="pedra" || r == "Spock") return true;
		return false;
	}
	if(s=="pedra"){
		if(r=="lagarto" || r == "tesoura") return true;
		return false;
	}
	if(s=="lagarto"){
		if(r=="Spock" || r == "papel") return true;
		return false;
	}
	if(s=="Spock"){
		if(r=="tesoura" || r == "pedra") return true;
		return false;
	}
	return false;
}


void solve(){
	long long t;
	cin>>t;
	string s, r;
	for(long long i=1LL; i<=t; i++){
		cin>>s>>r;
		cout<<"Caso #"<<i<<": ";
		if(s==r){
			cout<<"De novo!"<<'\n';
		}else{
			if(getResult(s,r)){
				cout<<"Bazinga!"<<'\n';
			}else cout<<"Raj trapaceou!"<<'\n';
		}
	}
}

int main(){
	optimizar_io
	solve();
	return 0;
}