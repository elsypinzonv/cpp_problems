#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

typedef pair<int ,int> pii;


void printFactores(vector<pii> facts){
	for(int i=0; i<facts.size(); i++){
		cout<<"factor "<<facts[i].first<<"-"<<facts[i].second<<" veces"<<'\n';
	}
}

vector<pii> getFactoresPrimos(int a){
	int count=0;
	while(!(a%2)){
		a/=2;
		count++;
	}
	vector<pii> facts;
	if(count) facts.push_back(pii(2,count));
	int root=sqrt(a);
	for(int i=3; i<=root; i++){
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
	int n;
	cin>>n;
	printFactores(getFactoresPrimos(n));
}

int main(){
	optimizar_io
	solve();
	return 0;
}