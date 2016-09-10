#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

const int MAXN = 10001;
int color[MAXN];
long long a1,a2;

struct node{
	int n;
	int col;
};

vector<int> grafo[MAXN];
queue<node> q;
const int NOT_MARK = -1;


void setChilds(node nod){
	int child;

	for(int i=0; i<grafo[nod.n].size(); i++){
		child=grafo[nod.n][i];
		if(color[child]==NOT_MARK || color[child]==nod.col){
			q.push({child,!(nod.col)});
		}
	}
}

 
bool BFS(){
	node nod;
	while(!q.empty()){
		nod= q.front();
		if(color[nod.n]==NOT_MARK){
			color[nod.n]=nod.col;
			setChilds(nod);
			if(nod.col){
				a1++;
			}else a2++; 	
		}else{
			if(color[nod.n]!= nod.col) return false;
		}
		q.pop();
	}
	return true;
}

void solve(){
	int t;
	bool bi;
	int v,e;
	cin>>t;	
	int a,b;
	int mini;

	for(int j=0; j<t; j++){
		cin>>v>>e;
		bi=true;
		a1=0; a2=0; mini=0;
		fill(color,color+MAXN,-1);
		for(int i=0; i<e; i++){
			cin>>a>>b;
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}
		for(int i=0; i<v; i++){
			a1=0; a2=0;
			if(color[i]== NOT_MARK){
				q.push({i,0});
				if(!BFS()){
					bi=false;
					cout<<"-1"<<'\n';
				}
				queue<node> empty;
				swap(q,empty);	 
			}
			if((a1!=0) && (a2!=0)){
				mini+=min(a1,a2);	
			} else mini+=max(a1,a2);
			//
			/*if((a1==0 && a2!=0) || (a2==0 && a1!=0)){
				mini+=max(a1,a2); //<<'\n';
			}else mini+=min(a1,a2); //<<'\n'; */
			if(!bi) break;
		}

		if(bi){
			cout<<mini<<'\n';
			/*if((a1==0 && a2!=0) || (a2==0 && a1!=0)){
				cout<<max(a1,a2)<<'\n';
			}else cout<<min(a1,a2)<<'\n'; */ 
		}

		for(int i=0; i<v; i++){
			grafo[i].clear();	
		}
	}
}

int main(){
	optimizar_io
	solve();
	return 0;
}