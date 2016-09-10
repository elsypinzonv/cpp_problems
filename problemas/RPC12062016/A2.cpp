#include<iostream>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);


struct person{
    string name;
    long double kd;
    bool active;
};

person played[6];

void solve(){
    int T;
    cin>>T;
    string name;
    long double LOSE = (long double)1/(long double)3;
    long double LOOSE = (long double)1/(long double)2;
    long double k,d;
    int INFI=-1;
    for(int i=0; i<T; i++){
        for(int j=0; j<5; j++){
            cin>>name;
            cin>>k>>d;
            if(d!=0){
                if((k/d)<LOSE){
                    cout<<name<<' '<<"plz uninstall"<<'\n';
                }
            }
        }
        long double minKD;
        long double actualKD;
        for(int j=0; j<5; j++){
            cin>>name;
            cin>>k>>d;
            if(j==0 || minKD==INFI){
                if(d!=0){
                    minKD=(k/d);
                }else minKD=INFI;
            }

             if(d!=0){
                actualKD=(k/d);
                played[j]={name,actualKD,false};
                if((k/d)<LOOSE){
                    played[j]={name,actualKD,true};
                }
            } else {
                actualKD=INFI;
                played[j]={name,actualKD,true};  
            }

            if(minKD==INFI){
                minKD=actualKD;
            }
            if(minKD>actualKD ){
                minKD=actualKD;
            }

        }

        for(int l=0; l<5; l++){
            if(played[l].kd==minKD){
             played[l].active=true;   
            }
        }
       

        for(int k=0; k<5; k++){
            if(played[k].active==true){
               cout<<played[k].name<<' '<<"plz uninstall"<<'\n';
            }
        }

    }

}

int main(){
    optimizar_io
    solve();
    return 0;
}
