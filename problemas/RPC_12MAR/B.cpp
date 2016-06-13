#include<iostream>
using namespace std;
//fstream fout("Aout.txt",fstream::out);

const int MAX=101;
int star[MAX][MAX];
int k;

void inn(int x, int y){
    star[x][y]=true;
    star[x][4*k-y]=true;
    star[4*k-x][y]=true;
    star[4*k-x][4*k-y]=true;
}

void cruz(){
   for(int i=0; i<=2*k; i++){
        inn(k,i);
        inn(i,k);
       // star[k][i]=true;
       // star[i][k]=true;
   }
}

void diag(){
    for(int i=0; i<=k; i++){
        inn(0+i,k+i);
        inn(k+i,0+i);
        inn(k+i,2*k-i);
    }
}


void spaces(){
    int x;
    for(int i=0; i<=4*k; i++){
        x=4*k;
        while(x>-1){
            if(star[i][x]==0){
              star[i][x]=2;
            } else break;
            x--;
        }
    }
}

void print(int z){
    for(int i=0; i<=4*k; i++){
        if(z>0)cout<<'\n';
        z++;
        for(int j=0; j<=4*k; j++){
            if(star[i][j]==1){
                cout<<'*';
            }else if(star[i][j]==0)cout<<' ';

        }
    }

}

void clean(){
     for(int i=0; i<=4*k; i++){
            for(int j=0; j<=4*k; j++){
                star[i][j]=false;
        }
    }
}

void solve(){
    int z=0;
     while(cin>>k){
        cruz();
        diag();
        spaces();
        print(z);
        clean();
        z++;
    }
}

int main(){
    solve();
    return 0;
}
