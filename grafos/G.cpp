#include <iostream>
#include <queue>
#include <vector>
using namespace std;

queue<int> cola;
int n;
vector<int> lista[500];
bool marcas[500];
int nodo;


void limpiar(){
    for(int i=0; i<n; i++){
        marcas[i]=false;
    }

    while(!cola.empty()) cola.pop();
}

void meterHijos(){
    for(int i=0; i<lista[nodo].size(); i++){
        if(marcas[lista[nodo][i]]==false) cola.push(lista[nodo][i]);

    }

}

bool isCiclo(){
    bool ciclo=false;
    while(!cola.empty() && ciclo==false){
        nodo=cola.front();
        if(marcas[nodo]==false){
           meterHijos();
           marcas[nodo]=true;
        }else ciclo=true;
        cola.pop();
    }

    return ciclo;
}

int main(){
    int a,b;
    cin>>n;
    while(cin>>a>>b){
        lista[a].push_back(b);
        lista[b].push_back(a);
        cola.push(0);
        if(isCiclo()){
          cout<<"SI es ciclo"<<"\n";
        } else cout<<"NO es ciclo"<<"\n";
        limpiar();
    }


}
