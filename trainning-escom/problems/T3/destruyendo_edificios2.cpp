#include<iostream>
#include<stack>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

struct building{
	long long h;
	long long w;
};

stack<building> s;
long long maxi;

void updateData(long long height){
	building b;
	long long width=0;
	long long minHeight=0;

	while(!s.empty() && (s.top().h > height)){
		b= s.top();
		minHeight=b.h;
		width+=b.w;
		maxi=max(minHeight*width,maxi);
		s.pop();
	}
	s.push({height,width+1});
	maxi=max(maxi,(height*(width+1)));
}

void solve(){
	long long n;
	cin>>n;
	long long height;
	for(long long i=0; i<n; i++){
		cin>>height;
		updateData(height);
		
	}
	updateData(0);
	cout<<maxi<<'\n';
}


int main(){
	optimizar_io
	solve();
	return 0;
}	