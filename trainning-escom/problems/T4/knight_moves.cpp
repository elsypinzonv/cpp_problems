#include <iostream>
#include <queue>
#include <set>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

long long const MAXN= 9;
set<string> tablero;
queue<string> q;


void BFS(){
	string node;
	while(!q.empty()){
		node=q.front();
		//setChild(node);
		tablero.insert(node);
		q.pop();
	}
}

void solve(){
	string a,b;
	cin>>a>>b;
	q.push(a);

	tablero.insert(a);
	iterator it = tablero.find(a);
	cout<<tablero.find(a)<<' '<<tablero.find(b)<<'\n' ;
}

int main(){
	optimizar_io
	solve();
	return 0;
}