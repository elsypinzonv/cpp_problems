// http://www.spoj.com/problems/TOE2/
#include <iostream>
using namespace std;

string s;

bool isValidNumber(){
    int x=0;
    int o=0;
    for(int i=0; i<9; i++){
        if(s[i]=='X') x++;
        if(s[i]=='O') o++;
    }

    if(x==o || (x==(o+1))) return true;
    return false;
}


bool isColumnValid(){
    int cont=0;

    if((s[0]==s[1]) && (s[1]==s[2])) cont++;
    if((s[3]==s[4]) && (s[4]==s[5])) cont++;
    if((s[6]==s[7]) && (s[7]==s[8])) cont++;
    if((s[0]==s[3]) && (s[3]==s[6])) cont++;
    if((s[1]==s[4]) && (s[4]==s[7])) cont++;
    if((s[2]==s[5]) && (s[5]==s[8])) cont++;
    if((s[0]==s[4]) && (s[4]==s[8])) cont++;
    if((s[6]==s[4]) && (s[4]==s[2])) cont++;

    return (cont< 1);
}

void solve(){
    while(cin>>s){
        if(s=="end") break;
        if(isValidNumber()==true && isColumnValid()==true){
            cout<<"valid"<<'\n';
        }else cout<<"invalid"<<'\n';

    }


}

int main(){
    solve();
    return 0;
}


