#include<iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

long long n;
long long A= 1234567;
bool flag;

long getGCD(long a, long b ) {
  long c;
  while ( a != 0 ) {
     c = a; 
     a = b%a;
     b = c;
  }
  return b;
}


void solve(){
	cin>>n;
	long long gcd=getGCD(123456,1234);
	for(int i=0; i<1000; i++){
		long long m=n;
		m=m-(i+1)*A;
		if(m%gcd==0){
			flag=true;
			break;
		}
	}

	if(flag){
		cout<<"YES"<<'\n';
	}else cout<<"NO"<<'\n';
}

int main(){
	optimizar_io
	solve();
	return 0;
}