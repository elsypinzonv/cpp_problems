#include<iostream>
#include<fstream>
using namespace std;

fstream fin("in.txt",fstream::in);
fstream fout("out.txt",fstream::out);

const string enun ="Case #";
long long d,k,n;

void exucte(){
    long long r=0;
    long long ri,le;
    if(k%2==0){
        r=(k-n)%d;
        cout<<r<<'\n';
        le=(r+1+d)%d;
        ri=(r-1+d)%d;
        cout<<le<<' '<<ri<<'\n';
        cout<<(((le-n+n*d)%d)+1)%d<<' '<<(((ri-n+n*d)%d)+1)%d<<'\n';
    }else{

        r=(k+n)%d;
        cout<<r<<'\n';
        le=(r+1+d)%d;
        ri=(r-1+d)%d;
        cout<<le<<' '<<ri<<'\n';
        cout<<(((le+n)%d)+1)%d<<' '<<(((ri+n)%d)+1)%d<<'\n';
    }
}


void solve(){
    long long t;
    fin>>t;
    for(int i=1; i<=t; i++){
        fin>>d>>k>>n;
        fout<<enun<<i<<':'<<' ';
        k=(k-1+d)%d;
        exucte();
    }
}

int main(){
    solve();
    return 0;

}

