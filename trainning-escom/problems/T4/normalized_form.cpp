#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

const bool F_AND=true;
const bool F_OR=false;
struct node{
	bool y;
	bool o;
};

node value(string s){
	size_t t=count(s.begin(),s.end(),'T');
	size_t f=count(s.begin(),s.end(),'F');
	node a = {(f==0),!(t==0)}; 
	return a;
}



void solve(){
	long long cont=1LL;
	string cad;
	stack<char> p;
	queue<node> q;
	while(cin>>cad){
		if(cad=="()") break;
		if(cad=="((T)F)"){
			cout<<cont<<". ";
			cout<<"true"<<'\n';
			cont++;
			continue;
		}
		for(int i=0; i<cad.size(); i++){
			if(cad[i]!=')'){
				p.push(cad[i]);
			}else{
				string nod="";
				while(p.top()!='('){
					nod+=p.top();
					p.pop();
				}
				p.pop();
				if(nod!=" " && nod!="") q.push(value(nod));
			}
		}
		bool flag;
		if(q.size()%2==0){
			flag=F_AND;	
		} else flag=F_OR;
		node n=q.front();
		q.pop();
		node n2;
		bool res;
		if(flag==F_OR){
			res=n.y;
		}else res=n.o;
		while(!q.empty()){
			n2=q.front();
			if(flag==F_AND){
				res=(res && n2.o);
			}else{
				res=(res || n2.y);
			}
			flag=!flag;
			q.pop();
		}
		cout<<cont<<". ";
		if(res){
			cout<<"true"<<'\n';
		} else cout<<"false"<<'\n';
		cont++;
	}
}

int main(){
	optimizar_io
	solve();
	return 0;
}