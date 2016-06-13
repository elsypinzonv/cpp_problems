//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=400
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int grafo[27];

int getRaiz(int nodo){
    while(nodo != grafo[nodo]){
        nodo= grafo[nodo];
    }
    return nodo;
}

bool isUnido(int a, int b){
    return (getRaiz(a) == getRaiz(b));
}

void unir(int a, int b){
    if(!isUnido(a,b)){
        grafo[getRaiz(a)]= getRaiz(b);
    }
}

int contarRaices(){
    int sum=0;
    for(int i=0; i<=n; i++){
        if(grafo[i]==i) sum++;
    }
    return sum;
}

int inicializar(){
     for(int i=0; i<=26; i++){
       grafo[i]=i;
    }
}

void solve(){
 int casos;
    cin>>casos;
    char c;
    for(int i=0; i<casos; i++){
        if(i!=0) cout<<'\n';
        cin>>c;
        n=c-'A';
        inicializar();
        string edge;
        getline(cin, edge);

        while(true){
            getline(cin, edge);
            if(edge.size()==0) break;
            unir(edge[0]-'A',edge[1]-'A');
        }
        cout<<contarRaices()<<'\n';
     }
}

int main(){
    solve();
    return 0;
}


