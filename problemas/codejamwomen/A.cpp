#include<iostream>
#include<queue>
#include<fstream>
using namespace std;
fstream fin("in.txt",fstream::in);
fstream fout("out.txt",fstream::out);

const string enun ="Case #";
queue<int> q;

void solve(){
    int t;
    fin>>t;
    int n;
    for(int i=1; i<=t; i++){
        fin>>n;
        int p;
        for(int j=0; j<2*n;j++){
            fin>>p;
            if(j==0){
                q.push(p*100/75);
                fout<<enun<<i<<':'<<' '<<p;
            }else{
                if(q.empty()){
                     q.push(p*100/75);
                     fout<<' '<<p;
                }else{
                    if(p==q.front()){
                        q.pop();
                    }else{
                        q.push(p*100/75);
                        fout<<' '<<p;
                    }
                }

            }
        } fout<<'\n';
    }
}

int main(){
    solve();
    return 0;
}
