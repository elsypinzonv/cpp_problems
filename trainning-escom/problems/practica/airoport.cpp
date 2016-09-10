#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);


vector<int> asientos;
pair<int, int> ;

void solve(){
	int t;
	cin>>t;
	int n,k;
	for(int i=0; i<t; i++){
		cin>>n>>k;
		int a;
		for(int j=1; j<=n; j++){
			cin>>a;
			asientos.push_back(a);
		}
	}

}

int main(){
	optimizar_io
	solve();
	return 0;
}