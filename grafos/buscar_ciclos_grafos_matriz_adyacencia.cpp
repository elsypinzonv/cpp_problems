#include <iostream>
#include <queue>
#include <vector>
using namespace std;



int n;
bool grafo[500][500];
bool marcas[500];
queue<int> cola;
int nodo;

void limpiar(){
    while(!cola.empty()) cola.pop();
    for(int i=0; i<n; i++) marcas[i]=false;

}

void meterHijos(){
    for(int i=0; i<n; i++){
        if(grafo[nodo][i]==true){
            if(!marcas[i]) cola.push(i);
        }

    }
}

bool isCiclo(){
    bool ciclo=false;

    while(!cola.empty() &&  ciclo==false){
        nodo=cola.front();
        if(!marcas[nodo]){
           marcas[nodo]=true;
           meterHijos();
        }else ciclo=true;
        cola.pop();

    }

    return ciclo;
}

int main(){
    int a,b;
    cin >> n;

    while(cin>>a>>b){
        grafo[a][b]=true;
        grafo[b][a]=true;
        cola.push(0);
        if(isCiclo()){
            cout<<"SI  es ciclo"<<"\n";
        }else cout<<"NO es ciclo"<<"\n";
        limpiar();
    }
}
