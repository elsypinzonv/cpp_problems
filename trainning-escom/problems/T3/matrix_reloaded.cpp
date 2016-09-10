#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

typedef vector<double> vec;
typedef vector<vec> Matriz;

const double ERROR = 1e-9;

bool isZero(double a) {
    return fabs(a) < ERROR;
}

void eliminacionGauss(Matriz& m){
	 for (int i = 0; i < m.size(); ++i) {
        if (isZero(m[i][i])) continue;
        for (int j = m[i].size() - 1; j >= i; --j){
            m[i][j] = m[i][j] / m[i][i];
        }
        for (int j = 0; j < m.size(); ++j) {
            if (i == j || isZero(m[j][i])) continue;
            for (int k = m[j].size() - 1; k >= i; --k){
                m[j][k] = m[j][k] - m[i][k] * m[j][i];
            }
        }
    }
}
bool check(Matriz& mat, int n){
	int cont=0;
		for(int i=0; i<mat.size(); i++){
			for(int j=0; j<n; j++){
				if(j==cont){
					if(mat[i][j]!=1) return false;
				}else{
					if(mat[i][j]!=0) return false;
				}
			}
			cont++;
		} 
	return true;
}	

void solve(){
	int n;
	double b;
	while(cin>>n and n){
		int cont=0;
		Matriz mat(n,vector<double>(n*2,0));
		for(int i=0; i<n; i++){	
			for(int j=0; j<n; j++){
				cin>>b;
				mat[i][j]=b;
			}
			mat[i][cont+n]=1;	
			cont++;
		}
		eliminacionGauss(mat);
		if(check(mat,n)){
			for(int i=0; i<mat.size(); i++){
				for(int j=n; j<mat[i].size(); j++){
					cout<<fixed;
					cout<<setprecision(6);
					cout<<mat[i][j];
					if(j!=(mat[i].size()-1))cout<<' ';
				}cout<<'\n';
			}
		}else{
			cout<<"Not possible"<<'\n';
		}	 
		cout<<'\n';
	}
	//cout<<'\n';
}

int main(){
	optimizar_io
	solve();
	return 0;
}