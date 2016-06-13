#include<iostream>
#include<queue>
#include<fstream>
using namespace std;
fstream fin("A-large.in",fstream::in);
fstream fout("Aout.txt",fstream::out);

const string enun ="Case #";
queue<unsigned long long> q;

void solve(){
    unsigned long long t;
    fin>>t;
    unsigned long long n;
    for(unsigned long long i=1; i<=t; i++){
        fin>>n;
        unsigned long long p;
        for(unsigned long long j=0; j<2*n;j++){
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
        }
        while(!q.empty()){
            q.pop();
        }
        fout<<'\n';

    }
}

int main(){
    solve();
    return 0;
}

