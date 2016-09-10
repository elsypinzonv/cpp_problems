#include<iostream>
#include<queue>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

struct node{
	int x;
	int y;
	int v;
};

int NOT_VISIT=-1;
int grid[104][104];
queue<node> q;
int n,m;
int maxRing;

void printAnswer(){

	if(maxRing>=10){
		for(int r=2; r<=n+1; r++){
			for(int c=2; c<=m+1; c++){
				if(grid[r][c]<10){
					if(grid[r][c]!=0){
						cout<<".."<<grid[r][c];
					}else cout<<"...";

				} else cout<<"."<<grid[r][c];
			} cout<<'\n';
		}
	}else {
		for(int r=2; r<=n+1; r++){
			for(int c=2; c<=m+1; c++){
				if(grid[r][c]==0){
					cout<<"..";
				}else cout<<"."<<grid[r][c];
			} cout<<'\n';
		}
	}
}



void setChild(node parent){
	if(grid[parent.x+1][parent.y]==NOT_VISIT) q.push({parent.x+1,parent.y,parent.v+1});
	if(grid[parent.x-1][parent.y]==NOT_VISIT) q.push({parent.x-1,parent.y,parent.v+1});
	if(grid[parent.x][parent.y+1]==NOT_VISIT) q.push({parent.x,parent.y+1,parent.v+1});
	if(grid[parent.x][parent.y-1]==NOT_VISIT) q.push({parent.x,parent.y-1,parent.v+1});
}

void BFS(){
	node nod;
	while(!q.empty()){
		nod=q.front();
		q.pop();
		setChild(nod);
		if(grid[nod.x][nod.y]==NOT_VISIT){
			grid[nod.x][nod.y]=nod.v;
			maxRing= max(nod.v,maxRing);
		} 
	}
}

void setZero(){
	for(int r =1; r<=n+1; r++){
		q.push({r,1,0});
		q.push({r,n+2,0});		
	}
	for(int c =1; c<=m+1; c++){
		q.push({1,c,0});
		q.push({m+2,c,0});
	}
}

void solve(){	
	cin>>n>>m;
	char a;
	for(int r=2; r<=n+1; r++){
		for(int c=2; c<=m+1; c++){
			cin >> a;
			if(a=='T'){
				grid[r][c]=-1;	
			} else{
				q.push({r,c,0});	
			}
		}
	}
	setZero();
	BFS();
	printAnswer();
}



int main(){
    optimizar_io
    solve();
    return 0;
}