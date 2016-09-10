#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
 
vector<string> normal;
vector<string> invers;

void subcadenas(string s){
	string a;
	for(int j=1; j<=s.size(); j++){
		for(int i=0; i<s.size()-j+1; i++){
			a=s.substr(i,j);
			normal.push_back(a);
			reverse(a.begin(),a.end());
			invers.push_back(a);
		}
	}
}

 void solve(){
 	int t;
 	string s;
 	cin>>t;

 	for(int i=0; i<t; i++){
 		cin>>s;
 		subcadenas(s);
 		sort(normal.begin(),normal.end());
 		sort(invers.begin(),invers.end());
 		string a="";
 		string b="";
 		for(int i=0; i<normal.size(); i++){
 			a+=normal[i];
 		}
 		for(int i=0; i<invers.size(); i++){
 			b+=invers[i];
 		}
 		//cout<<a<<'\n'<<b;
 		if(a==b){
 			cout<<"YES"<<'\n';
 		} else cout<<"NO"<<'\n';
 		normal.clear();
 		invers.clear();
 	}
 }

 int main(){
	optimizar_io
	solve();
	return 0;
}