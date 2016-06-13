#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

const int MAX=1000001;
bool comp[MAX];
int batch[MAX];
int divs[MAX];
vector<int> primes;
void createComp(){
    comp[1]=true;
    for(int i=2; i<MAX; i++){
        if(!comp[i]){
            for(int j=i; j<MAX; j+=i){
                comp[j]=true;
                if(divs[j]==0){
                    divs[j]=i;
                }
            }
            comp[i]=false;
            primes.push_back(i);
        }
    }
    reverse(primes.begin(), primes.end());
}

void calBatchs(){

    batch[1]=1;
    for(int i=2; i<MAX; i++){
        if(!comp[i]){
            batch[i]=1;
        }else{
            int x=i;
            int aux;
            while(x!=1){
                aux=x;
                x=x/divs[x];
            }

            batch[i]=batch[i-aux]+1;
      }
    }
}

void solve(){
    int n;
    while(cin>>n){
        cout<<batch[n]<<'\n';
    }
}

int main(){
    createComp();
    calBatchs();
    solve();
    return 0;
}
