#include <iostream>
#include <vector> 
#include <stack>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
 
const int MAXN = 1000001;
long long mini[MAXN];
long long maxi[MAXN];
vector<int> graf[MAXN];
stack<int> p;
long long tim=1;

void BFS(){
	int nod;
	while(!p.empty()){
		nod=p.top();
		p.pop();
		if(mini[nod]==0){	
			p.push(nod);
			for(int i=0; i<graf[nod].size(); i++){
				if(mini[graf[nod][i]]==0) p.push(graf[nod][i]);
			}
			mini[nod]=tim;
		}else{
			maxi[nod]=tim;
		}
		tim++;
	}
}

 void solve(){
 	int n,k;
 	cin>>n>>k;
 	int v,u;
 	for(int i=0; i<(n-1); i++){
 		cin>>v>>u;
 		graf[v].push_back(u);
 		graf[u].push_back(v);
 	}
 	p.push(1);
 	BFS();
 	int a,b;
 	long long r1,r2,l1,l2;
 	for(int i=0; i<k; i++){
 		cin>>a>>b;
 		r1=mini[a];
 		r2=maxi[a];
 		l1=mini[b];
 		l2=maxi[b];
 		if((r1<=l1 && l1<=r2)||(r1<=l2 && l2<=r2)){
 			cout<<0<<'\n';
 		}else cout<<1<<'\n';
 	} 
 }

 int main(){
	optimizar_io
	solve();
	return 0;
}