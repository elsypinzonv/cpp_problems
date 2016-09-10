#include<iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

int grid[102][102];
int TREE = -1;
int cont=0;
bool isFinish;
int n,m;
int maxRing;

void printAnswer(){

	if(cont>=10){
		for(int r=1; r<=n; r++){
			for(int c=1; c<=m; c++){
				if(grid[r][c]<10){
					if(grid[r][c]!=0){
						cout<<".."<<grid[r][c];
					}else cout<<"...";

				} else cout<<"."<<grid[r][c];
			} cout<<'\n';
		}
	}else {
		for(int r=1; r<=n; r++){
			for(int c=1; c<=m; c++){
				if(grid[r][c]==0){
					cout<<"..";
				}else cout<<"."<<grid[r][c];
			} cout<<'\n';
		}
	}
}

bool checarHijo(int a, int b){

	if(grid[a+1][b]==cont) return true;
	if(grid[a-1][b]==cont) return true;
	if(grid[a][b+1]==cont) return true;
	if(grid[a][b-1]==cont) return true;

	return false;

}

void recorrer(){
	for(int r=1; r<=n; r++){
		for(int c=1; c<=m; c++){
			if(grid[r][c]==TREE){
				if(checarHijo(r,c)){
					isFinish=false;
					grid[r][c]=cont+1;
				}
			}
		}
	}
}

void solve(){
	cin>>n>>m;
	char a;
	for(int r=1; r<=n; r++){
		for(int c=1; c<=m; c++){
			cin >> a;
			if(a=='T') grid[r][c]=-1;
		}
	}
	while(!isFinish){
		isFinish=true;
		recorrer();
		cont++;
	}
	printAnswer();
}



int main(){
    optimizar_io
    solve();
    return 0;
}