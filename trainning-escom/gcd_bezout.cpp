#include<iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

struct tri{
	long gcd;
	long x;
	long y;
};


tri gcdBezout(long a, long b){
	if(b==0) return {a,1L,0L};
	tri v = gcdBezout(b, a%b);
	return {v.gcd, v.y, v.x-(a/b)*v.y};
	//return {v.gcd, v.y, (m + v.x-((a/b)*v.y)%m)%m};
}

void solve(){
	int a,b;
	//int m; // modulo
	cin>>a>>b;
	tri v= gcdBezout(a,b);
	cout<<v.gcd<<' '<<v.x<<' '<<v.y<<' '<<'\n';

}

int main(){
	optimizar_io
	solve();
	return 0;
}
