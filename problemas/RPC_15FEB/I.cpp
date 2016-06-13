#include <iostream>
using namespace std;

const int MAX = 103;

int b[MAX];
int g[MAX];
int r[MAX];
int y[MAX];
bool pas;

void clean(){
    for(int i=1; i<=100; i++){
        b[i]=0;
        g[i]=0;
        r[i]=0;
        y[i]=0;
    }
    pas=false;
}


void check2(int ar[], int num){
    if(ar[num-1]>0 && ar[num]>0 && ar[num+1]>0) pas=true;
    if(ar[num]>0 && ar[num+1]>0 && ar[num+2]>0) pas=true;
    if(num>1) {
        if(ar[num-1]>0 && ar[num-2]>0 && ar[num]>0) pas=true;
    }
}

void check(int num, int ar[]){
    int sum=0;

    if(b[num]>0) sum++;
    if(g[num]>0) sum++;
    if(r[num]>0) sum++;
    if(y[num]>0) sum++;

    if(sum>=3) pas=true;
    check2(ar, num);

}


void save(int n, char a){
    switch(a){
        case 'b':
            b[n]++;
            check(n,b);
            break;
        case 'g':
            g[n]++;
            check(n,g);
            break;
        case 'r':
            r[n]++;
            check(n,r);
            break;
        case 'y':
            y[n]++;
            check(n,y);
            break;
    }


}

void solve(){
    int t;
    cin>>t;
    int m;
    for(int i=0; i<t; i++){
        cin>>m;
        int n;
        char a;
        for(int j=0; j<m; j++){
            cin>>n;
            cin>>a;
            save(n,a);
        }
        if(pas){
            cout<<"YES"<<"\n";
        }else cout<<"NO"<<"\n";
        clean();
    }
}

int main(){
    solve();
    return 0;
}

