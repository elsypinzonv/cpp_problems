#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

const long long MAXN=1000002;
long long grafo[MAXN];
queue<long long> q;
long long marks[MAXN];
long long sums[MAXN];
long long cont=1;
stack<long long> s;

void setChilds(long long parent){
	long long a;
	a=grafo[parent];
	if(marks[a]!=cont){
		q.push(a);
	}
}

long long BFS(){
	long long sum=0LL;
	while(!q.empty()){
		long long node =q.front();
		if(marks[node]!=cont){
			if(marks[node]==0){
				setChilds(node);
				sum++;				
			}else{
				sum+=sums[node];
			}
			marks[node]=cont;
		}
		q.pop();
	}
	return sum;
}

void solve(){
	long long e;
	long long a;
	cin>>e;
	for(long long i=1LL; i<=e; i++){
		cin>>a;
		grafo[i]=a;

	}
	long long maxi=0;	
	long long m;
	for(long long j=1LL; j<=e; j++){
		if(!marks[j]){
			q.push(j);
			m=BFS();
			maxi=max(m,maxi);
			while(!s.empty()){
				sums[s.top()]=m;
				s.pop();
			}
			cont++;
		}
	}
	cout<<maxi<<'\n';
}

int main(){
	optimizar_io
	solve();
	return 0;
}