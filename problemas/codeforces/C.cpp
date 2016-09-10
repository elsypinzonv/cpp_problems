#include<iostream>
#include<queue>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

string INSERT="insert";
string GET_MIN = "getMin"
string REMOVE = "remove";
queue<string> q;
priority_queue<int> pq;

bool operator<(int a, int b){
	return a>b;
}


void solve(){

	int n;
	string sentence;
	int a;
	cin>>n;

	for(int i=0; i<n; i++){
		cin>>sentence;
		if(sentence==INSERT){
			cin>>a;
			q.push(INSERT+" "+a);
			pq.push_back(a);
		}else{
			if(sentence==GET_MIN){
				cin>>a;
				if(!pq.empty()){
					q.push(INSERT+" "+a);
					q.push(GET_MIN+" "+a);
				}else{
					int b= pq.top();

					if(b=a){
						q.push(GET_MIN+" "+a);
						pq.pop();
					}else{
						if(b<a){
							q.push(INSERT+" "+a);
							q.push(GET_MIN+" "+a);
						}else{
							while(b>a){
								q.push(REMOVE);
								pq.pop();
								b=pq.top();
							}
							if(b==a){
								q.push(REMOVE);
								pq.pop();
							}else{
								q.push(INSERT+" "+a);
								q.push(REMOVE);
							}
						}
					}


				}

			}else{
				if(sentence==REMOVE){


				}
			}

		}
	}

}

int main(){
	optimizar_io
	solve();
	return 0;
}