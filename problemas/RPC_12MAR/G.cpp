#include<iostream>
#include<cmath>
using namespace std;

const long double PI  =3.1415926535897;

void solve(){
    long double a,b;
    cin>>a>>b;

    long double rs=(pow(a+b,2))* asin((4*abs(a+b)*sqrt(a*b))/(a+b))-2*((a*a)-(b*b))*(sqrt(a*b))-2*PI*b*b;

    cout<<asin(1);


}

int main(){
    solve();
    return 0;
}

