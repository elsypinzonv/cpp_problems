#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

struct p{
	long long s;	
	long long a;
};

bool flag;
vector<p> v;

void solve(){
	int t,c;
	cin>>t;
	long long sum;
	long long a;
	long long gcd;
	for(int i=0; i<t; i++){
		flag=false;
		gcd=0;
		cin>>c;
		for(int j=0; j<c; j++){
			sum=0;
			for(int k=0; k<9; k++){			
				cin>>a;
				sum+=a;				
			}
			cin>>a;
			if(j==0 && a==sum) flag=true;
			if(flag==true && a!=sum) flag=false;
			v.push_back({sum,a});
			if(gcd!=0 || (sum-a)!=0) gcd= __gcd(gcd,sum-a); 
		}
		if(gcd<=1 || flag==true){
			cout<<"impossible"<<'\n';
		}else{
			for(int l=0; l<v.size(); l++){
				if(((v[l].s)%gcd)!=v[l].a){
					flag=true;
					break;	
				} 
			}
			if(flag==true){
				cout<<"impossible"<<'\n';
			}else cout<<gcd<<'\n';
		}
		v.clear(); 
	}
}

int main(){
	optimizar_io
	solve();
	return 0;
}