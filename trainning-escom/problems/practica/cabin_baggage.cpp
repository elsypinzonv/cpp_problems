#include <iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

void solve(){
	long long t;
	long long total=0;
	double l,w,d,p;
	bool flag;
	const double alto=56.00;
	const double ancho=45.00;
	const double profun=25.00;
	const double peso= 7.00;
	const double suma=125.00;
	cin>>t;
	for(long long i=0LL; i<t; i++){
		flag=true;
		cin>>l>>w>>d>>p;
		if(l>alto || w>ancho || d>profun) {
			/*cout<<l<<' '<<alto<<'\n';
			cout<<w<<' '<<ancho<<'\n';
			cout<<d<<' '<<profun<<'\n';
			cout<<p<<' '<<peso<<'\n';*/
			if((l+w+d)>suma)flag=false;
		}
		if(p>peso) flag=false;
		if(flag){
			total++;
			cout<<1<<'\n';
		}else cout<<0<<'\n';
	}
	cout<<total<<'\n';
}

int main(){
	optimizar_io
	solve();
	return 0;
}