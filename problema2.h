/*
Complejidad:
TSP problem
Held-Karp (DP bitmask): O(n^2 * 2^n)
n = número de doghouses
*/
/* 
¿cuál es la ruta más corta posible que visita cada colonia exactamente una vez y al finalizar regresa a la colonia origen? 
Tomar en cuenta que muchas veces el costo mínimo puede pasar por una colonia central o más intermedias. 
El programa debe desplegar la ruta a considerar así como el costo.
*/

#ifndef PROBLEMA2_H
#define PROBLEMA2_H
#include "general.h"


/* 
ASC05 – Shortest Path.
Algoritmos de Dijkstra y Floyd-Warshall

Anna Galilea Restrepo Martínez - A01178273 
*/ 

/* Complejidades:

Dijkstra: O(E log V) V siendo el número de nodos tambien y E el numero de aristas.
*/

void initMatAdj(int matAdj[MAX][MAX]){
    for(int i=0; i<MAX; i++){
        matAdj[i][i]=0;
        for(int j=i+1; j<MAX; j++){
            matAdj[i][j] = matAdj[j][i] = INF;
        }
    }
}

void leeDatos(int matAdj[MAX][MAX], Graph&G, int e){
    int u, v, w;
    for(int i=0; i<e; i++){
        cin >> u >> v >> w;
        matAdj[u-1][v-1] = matAdj[v-1][u-1] = w;
        Edge edge1(v-1, w);
        G[u-1].push_back(edge1);
        Edge edge2(u-1, w);
        G[v-1].push_back(edge2);
    }
}

vector<int> dijkstra(Graph &G, int s){
    s--;
    vector<int> dist(G.size(), INF);
    dist[s] = 0;
    priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;
    Vertex vs(0, s); 
    pq.push(vs);
    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(d>dist[u]) continue;
        for(int j=0; j<G[u].size(); j++){
            Edge e = G[u][j];
            int v = e.first;    
            int w = e.second;  
            if(dist[v] > dist[u]+w){
                dist[v] = dist[u]+w;
                Vertex vtx(dist[v], v);
                pq.push(vtx);
            }
        }
    }
    return dist;
}

void despliega(int matAdj[MAX][MAX], Graph &G, vector<int> &dist, int s){
    s--; 
    cout << "Dijkstra: " << endl;
    for(int i=0; i<dist.size(); i++){
        if(s != i){
            cout << (s+1) << " --> " << (i+1) << ": " << dist[i] << endl;
        }
    }
}

/*int main() {
    int matAdj[MAX][MAX];
    int v, e, s;
    cin >> v >> e >> s;
    Graph G(v);
    initMatAdj(matAdj);
    leeDatos(matAdj, G, e);   
    vector<int> dist = dijkstra(G, s);
    despliega(matAdj, G, dist, s);
    return 0;
}

void procesarCasos() {
    int n, m, k, q; //n = numero de colonias, m = numero de conexiones entre colonias
    int esCentral;
    cin >> n>> m>> k>> q;
    //Matriz de adyacencia inicializada con INF
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
        dist[i][i] = 0;
    //Leer las conexiones entre doghouses
    for (int i = 0; i < m; i++) {
        char nombreCol;
        int x, y;
        cin >> nombreCol >> x >> y >> esCentral;
        int m = x-'A';
        int k = y-'A';
        dist[m][k] = min(dist[m][k], esCentral);
        dist[k][m] = min(dist[k][m], esCentral);
    }
    
    if (esCentral != 0){
        //DP bitmask: dp[mask][i] = menor costo para visitar mask y terminar en i
        int Nmask = 1 << n;
        vector<vector<int>> dp(Nmask, vector<int>(n, INF));
        dp[1][0] = 0; 
        //Transiciones del algoritmo Held-Karp
        for (int mask = 1; mask < Nmask; mask++) {
            for (int u =0; u < n; u++) {
                if (!(mask & (1 << u))) continue; 
                if (dp[mask][u] == INF) continue;
                
                for (int v = 0; v < n; v++) {
                    if (mask & (1 <<v)) continue; 
                    if (dist[u][v] ==INF) continue; 
                    int nextMask = mask | (1 << v);
                    dp[nextMask][v] =min(dp[nextMask][v], dp[mask][u] + dist[u][v]);
                }
            }
        }
        //Buscar el costo minimo para regresar a A
        int ans =INF;
        for (int u = 1; u <n; u++) {
            if (dist[u][0] <INF)
            ans = min(ans, dp[Nmask - 1][u] +dist[u][0]);
        }
        if (ans >= INF) cout << "INF\n";
        else cout << ans << "\n";  
    } else{
        // aplicar floyd warshall para permitir pasar por colonias centrales
        
    }
}*/

#endif