//#include "general.h"
#include "problema1.h"
//#include "problema2.h"
//#include "problema3.h"
//#include "problema4.h"

#include <map>

using namespace std;

// clang++ main.cpp -o programa
// ./programa

// clang++ main.cpp -o programa
// ./programa

int main(){

    //PROBLEMA 1
    int n, m, k, q; // cantidad de colonias, num conexiones entre colonias, 
    //las conexiones con el nuevo cableado, y futuras colonias
    cin >> n >> m >> k >> q;

    Graph g(n, m);
    
    string nombreCol; 
    int x, y; 
    int esCentral; // 1 si es central, 0 si no


    map<string, int> coloniasIdx;
    vector<string> colonias(n);

    for (int i = 0; i < n; i++){
        cin >> nombreCol >> x >> y >> esCentral;
        coloniasIdx[nombreCol] = i;
        colonias[i] = nombreCol;
    }

    string con1, con2; // conexiones entre colonias
    int costo;
    int idxCol1;
    int idxCol2;
    for (int i = 0; i < m; i++){
        cin >> con1 >> con2 >> costo;
        idxCol1 = coloniasIdx[con1];
        idxCol2 = coloniasIdx[con2];
        g.addEdge(idxCol1, idxCol2, costo);
    }

    int idxNuevoCol1;
    int idxNuevoCol2;
    //map<string, int> cableadoNuevo;
    string nuevaCon1, nuevaCon2; // nuevas conexiones con el nuevo cableado
    for (int i = 0; i < k; i++){
        cin >> nuevaCon1 >> nuevaCon2;
        idxCol1 = coloniasIdx[nuevaCon1];
        idxCol2 = coloniasIdx[nuevaCon2];
        g.addEdge(idxCol1, idxCol2, 0);
    }

    string nuevaCol;
    for (int i = 0; i < q; i++){
        cin >> nuevaCol >> x >> y; // nuevas colonias y sus puntos cartecianos
    }


	g.kruskalMST();

    string cableado1, cableado2;
    int costoCon;
    cout << "-------------------" << endl << "1 - Cableado óptimo de nueva conexión." << endl;
    cout << endl;
    for (auto it:g.selectedEdgesK){
        if (it.first != 0){
            cableado1 = colonias[it.second.first];
            cableado2 = colonias[it.second.second];
            costoCon = it.first;
            cout << cableado1 << " - " << cableado2 << " " << costoCon << endl;
        }
	}
    cout << endl;
    g.printTotalCost();
    cout << endl;

    cout << "-------------------" << endl;
    return 0;

    /*
    int matAdj[MAX][MAX];
    int n, m, k, q;
    cin >> n >> m >> k>> q;
    Graph G(n);
    vector<int> visitar;
    initMatAdj(matAdj);
    leeDatos(matAdj, G, n,m,k,q,visitar);
    floyd(matAdj, n);
    despliega(matAdj, G,n);
    return 0;
    */

}

// clang++ main.cpp -o programa
// ./programa

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
