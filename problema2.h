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

#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cctype>
#include <string>
#include <queue>
#include <map>
using namespace std;

#define INF INT_MAX
#define Edge pair<int,int>
#define Graph vector<vector<Edge>>
#define Vertex pair<int, int> 
#define MAX 10
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

/*5 8 1 2                    
(5 colonias, 8 conexiones, 1 conexion que ya cuenta con el nuevo cableado, 2 nuevas colonias)

LindaVista 200 120 1
Purisima 150 75 0
Tecnologico -50 20 1
Roma -75 50 0
AltaVista -50 40 0
(nombre colonia, posicion cartesiana, es central si o no)

LindaVista Purisima 48
LindaVista Roma 17
Purisima Tecnologico 40
Purisima Roma 50
Purisima AltaVista 80
Tecnologico Roma 55
Tecnologico AltaVista 15
Roma AltaVista 18
(nombres de las colonias conectadas y el costo de la conexion)

Purisima Tecnologico
(nombres de las colonias que ya cuentan con el nuevo cableado)

Independencia 180 -15
Roble 45 68
(nuevas colonias y sus posiciones cartecianas) 
*/

void leeDatos(int matAdj[MAX][MAX], Graph&G, int n, int m, int k, int q, vector<int>& visitar){
    string nombreCol;
    int x, y, esCentral;
     //para guardar los que son no centrales, asi we keep track of them
    //build dictionary
    //name-> index(not for weight): translates names to numbers
    unordered_map<string,int> coloniasIdx;
    //
    string col1, col2;
    int peso;

    
    for(int i=0;i<n;i++){
        cin >> nombreCol >> x >> y >> esCentral;
        coloniasIdx[nombreCol] =i; //el mapa
        if (esCentral ==1){
            visitar.push_back(i);
        }
    }

  
    for(int i=0; i<m; i++){
        cin >> col1 >> col2 >> peso; 
        int idx1=coloniasIdx[col1];
        int idx2=coloniasIdx[col2];
        matAdj[idx1][idx2] = matAdj[idx2][idx1] = peso;
        Edge edge1(idx2, peso);
        G[idx1].push_back(edge1);
        Edge edge2(idx1, peso);
        G[idx2].push_back(edge2);
    }
}

void floyd(int matAdj[MAX][MAX], int v){
    for(int k=0; k<v; k++){
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                if(matAdj[i][k] != INF && matAdj[k][j] != INF &&
                    matAdj[i][j] > matAdj[i][k] + matAdj[k][j]){
                    matAdj[i][j] = matAdj[i][k] + matAdj[k][j];
                }
            }
        }
    }
}


/*void TSP(int matAdj[MAX][MAX], vector<int>& visitar) {
    //Matriz de adyacencia inicializada con INF
    matAdj[visitar[0]][visitar[1]];
        //DP bitmask: dp[mask][i] = menor costo para visitar mask y terminar en i
        int Nmask = 1 << n; //vertices 
        vector<vector<int>> dp(Nmask, vector<int>(n, INF));
        dp[1][0] = 0; 
        //Transiciones del algoritmo Held-Karp
        for (int mask = 1; mask < Nmask; mask++) {
            for (int u =0; u < n; u++) {
                if (!(mask & (1 << u))) continue; 
                if (dp[mask][u] == INF) continue;
                
                for (int v = 0; v < n; v++) {
                    if (mask & (1 <<v)) continue; 
                    if (min(dist[m][k], esCentral) ==INF) continue; 
                    int nextMask = mask | (1 << v);
                    dp[nextMask][v] =min(dp[nextMask][v], dp[mask][u] + min(dist[m][k], esCentral));
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
}*/


void despliega(int matAdj[MAX][MAX], Graph &G, int n){ 
    cout << "Floyd:"<<endl;
    for (int i =0; i<n;++i){
        for (int j =0; j<n;++j){
            if(matAdj[i][j] >=INF) cout << "INF";
            else cout <<matAdj[i][j]<<"";
        }
    }
}

/* 
void solucionProblema2(){
    Graph G(n);
    vector<int> visitar;
    initMatAdj(matAdj);
    leeDatos(matAdj, G, n,m,k,q,visitar);
    floyd(matAdj, n);
    despliega(matAdj, G,n);
    return 0;
}*/


#endif