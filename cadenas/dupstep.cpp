#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string cadena;
int marca;
bool espacio;
string sub="";

void concatenar(string cad){
    sub=sub+cad;
    marca=0;
}

void isW(char cad){
    if(cad=='W'){
        marca=2;
    }else {
        string s="";
        concatenar(s+((const char*)(cad)));
    }
}

void isU(char cad){
    if(cad=='U'){
        marca=3;
    } else{
        string s="W";
        concatenar(s+((const char*)(cad)));
    }
}

void isB(char cad){
    if(cad=='B'){
        marca=1;
    } else{
        string s="WU";
        concatenar(s+((const char*)(cad)));
    }
}

bool resolve(char cad){
    switch(marca){
        case 1:
            isW(cad);
        break;
        case 2:
            isU(cad);
        break;
        case 3:
            isB(cad);
        break;
    }

    if(marca==0){
        marca=1;
        return true;
    }else return false;

}

void solve(){
    marca=1;
    for(int i=0; i<cadena.size(); i++){
        if(resolve(cadena[i])){
          //  sub=sub+((const char*)(cadena[i]));
        }
    }
   cout<<sub<<'\n';
}

int main(){
    cin>>cadena;
    solve();
}
