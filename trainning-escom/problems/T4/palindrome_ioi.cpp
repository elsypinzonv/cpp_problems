#include <iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
 
 /*long long dp(int i, int j){

 	if(s[i]==s[j]) return dp(i-1,j-1);
 	return min(dp(i+1, j), dp(i,j-1)) +1;
 }
*/

 void solve(){
 	long long n;
 	string s;
 		cin>>n>>s;
 		for(long long i=0LL; i<(n/2); i++){
 			for(long long j=(n-1); j>=n/2; j--){
 				//cout<<i<<' '<<j<<'\n';
 				cout<<s[i]<<' '<<s[j]<<'\n';
 			}
 		}
 }

 int main(){
	optimizar_io
	solve();
	return 0;
}