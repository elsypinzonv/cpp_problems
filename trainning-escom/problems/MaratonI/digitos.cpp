#include<iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

long long n;
string nums="";

void solve(){
	cin>>n;
	string l;
	for(int i=0; i<=n; i++){
		l=to_string(i);
		nums+=l;
	}
	size_t found = nums.find(to_string(n));
    if(found!=std::string::npos){ 
        cout << found << '\n';
    }
}

int main(){
	optimizar_io
	solve();
	return 0;
}