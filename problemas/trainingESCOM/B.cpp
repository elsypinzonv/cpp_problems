#include<iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);

void solve(){
    int station,result=0;
    cin>>station;

    if(540<=station && station<=1520){
        if(station<780){
            result=580-station;
        }else{
            if(station<1085){
                result=980-station;
            }else{
                if(station<1220){
                    result=1190-station;
                }else{
                    if(station<1335){
                        result=1250-station;
                    }else{
                        result=1420-station;
                    }
                }
            }
        }

        if(result<0){
            cout << "atras " << -1*result << '\n';
        }else cout << "adelante " << result << '\n';

    }else{
        cout<<"error"<<'\n';
    }

}

int main(){
    optimizar_io
    solve();
    return 0;
}
