#include<iostream>
#include<vector>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

struct aes{
	string name;
	int l;
	int h;
};

vector<aes> v;
string res;

bool search(int p){
	aes a;
	bool flag=false; 
	for(int i=0; i< v.size(); i++){
		a=v[i];
		//cout<<a.l<<' '<<a.h<<' '<<p;
		if(a.l<=p && p<=a.h){
			//cout<<a.name<<' ';
			if(flag){
				flag=false;
				break;
			}else{
				res=a.name;
				flag=true;
			}
		}
	}

	return flag;
}

void solve(){
	int cont=0;
	int t;
	cin>>t;
	int d;
	string a;
	int b,c;
	for(int i=0; i<t; i++){
		if(cont++) cout<<'\n';
		cin>>d;
		for(int j=0; j<d; j++){
			cin>>a>>b>>c;
			v.push_back({a,b,c});
		}
		int q,p; 
		cin>>q;
		for(int j=0; j<q; j++){
			cin>>p;
			if(search(p)){
				cout<<res<<'\n';
			} else cout<<"UNDETERMINED"<<'\n';
		} 

		v.clear();
	}

}

int main(){
	optimizar_io
	solve();
	return 0;
}