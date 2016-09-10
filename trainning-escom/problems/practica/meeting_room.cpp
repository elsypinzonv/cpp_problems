#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

vector<pair<int,int>> events;

void solve(){
	int n;
	int s,f;
	long long maximo;
	int limite_izquierdo;
	cin>>n;
	for(int i=0; i<n; i++){
		maximo=limite_izquierdo=0;
		while(cin>>s>>f and (s or f)){
			events.push_back({f,s});
		}
		sort(events.begin(), events.end());
		for(long long j=0LL; j<events.size(); j++){
			if(limite_izquierdo<= events[j].second){
				limite_izquierdo=events[j].first;
				maximo++;
			}
		}
		cout<<maximo<<'\n';
		events.clear();
	}
}

int main(){
	optimizar_io
	solve();
	return 0;
}