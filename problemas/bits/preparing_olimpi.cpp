//http://codeforces.com/problemset/problem/550/B
#include <iostream>
#include <algorithm>
using namespace std;

const long long MAXIMO=16;

void solve(){
    long long n , l ,r ,x;
    long long s=0;
    long long num[MAXIMO];
    cin>> n >> l >> r >>x ;
    long long j, cont, maxi, mini, sum;

    for(long long i=0; i<n;i++){
        cin>>num[i];
    }

    sort(num, num+n);

    for(long long i=0; i<pow(2,n); i++){
        j=i;
        cont=maxi =mini= sum=0;
        while(j!=0){
            if(j & 1){
                if(mini==0){
                    maxi= num[cont];
                    mini= num[cont];
                }
                maxi= max(maxi,num[cont]);
                sum+=num[cont];
            }
            j=j>>1;
            cont++;
        }
      //  cout<<maxi<<' '<<mini<<' '<<sum<<'\n';
        if(maxi-mini>=x && (l<=sum && sum<=r) && (maxi!=mini)) s++;
    }

    cout<<s<<'\n';
}

int main(){
    solve();
    return 0;
}



