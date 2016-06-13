#include <iostream>
using namespace std;

int n;
int raiz;
int arbol[500];

void rastrear(){
    int pa;
    pa= arbol[raiz];
    arbol[raiz]= raiz;
    int j;
    while(arbol[pa]!=pa){
        j= arbol[pa];
        arbol[pa]=raiz;
        raiz=pa;
        pa=j;

    }
    arbol[pa]=raiz;
}


int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arbol[i];
    }
    cin>>raiz;

    rastrear();

    for(int i=0; i<n; i++){
        cout<<arbol[i]<<' ';
    }
    cout<<"\n";
}
