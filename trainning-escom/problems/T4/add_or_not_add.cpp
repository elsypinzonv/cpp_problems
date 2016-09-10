#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
 
vector<long long> nums;
vector<long long> sum;

 void solve(){
 	long long n,k;
 	cin>>n>>k;
 	long long a;
 	for(long long i=0LL; i<n; i++){
 		cin>>a;
 		nums.push_back(a);
 	}
 	sort(nums.begin(), nums.end());



 }

 int main(){
	optimizar_io
	solve();
	return 0;
}