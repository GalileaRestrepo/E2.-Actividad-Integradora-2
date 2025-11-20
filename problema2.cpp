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

#include "problema2.h"
#include "general.h"

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
}