#include <iostream>
using namespace std;

string l;
int n;
int cont[1001];

void limpiar(){
    for(int i=0; i<n; i++){
        cont[i]=0;
    }
}

int convertir(int x){
    if((x>='A' && x<='Z')){
        return x-64;
    }else return x-96;

}


int pros(){
    for(int i=0, j=0; j<l.size();  i++, j++){
        cont[i]=((cont[i]+convertir(int(l[j])))%10);
        if(i==n-1) i=-1;
    }
    int mul=1;
    for(int i=0; i<n; i++){
        mul=((mul*(cont[i]+1)%10));
    }
    return ((mul%10)+1);
}


void solve(){
    int P,O;
    cin>>l>>n>>l;
    P=pros();
    cin>>l>>n>>l;
    limpiar();
    O=pros()+64;
    cout<<P<<'-'<<char(O)<<'\n';
}

int main(){
    solve();
    return 0;
}
