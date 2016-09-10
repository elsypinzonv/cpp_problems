struct UnionFind {
    int nconjuntos;
    vector<int> padre;
    vector<int> tamano;

    UnionFind(int n) : nconjuntos(n),
        padre(n), tamano(n, 1) {
        for(int i = 0; i < n; ++i)
            padre[i] = i;
    }

    int Encontrar(int u) {
        if (padre[u] == u) return u;
        return padre[u] = Encontrar(padre[u]);
    }

    void Unir(int u, int v) {
        int Ru = Encontrar(u);
        int Rv = Encontrar(v);
        if (Ru == Rv) return;
        --nconjuntos, padre[Ru] = Rv;
        tamano[Rv] += tamano[Ru];
    } 

    bool MismoConjunto(int u, int v) {
        return Encontrar(u) == Encontrar(v);
    }

    int TamanoConjunto(int u) {
        return tamano[Encontrar(u)];
    }
};