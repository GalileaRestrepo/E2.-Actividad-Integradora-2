#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

struct Graph{
	// V = Cantidad de nodos (Vertex)
	// E = Cantidad de Arcos (Edges)
	int V, E;
    long long costMSTKruskal;
	vector<pair<long long, pair<int, int>>> edges;	// Utilizar en Kruskal
	vector<pair<int, pair<int,int>>> selectedEdgesK;		// Arcos seleccionados por Kruskal
	Graph(int V, int E){
		this->V = V;
		this->E = E;
		costMSTKruskal = 0;
	}
	// u = salida del arco
	// v = llegada del arco
	// w = costo del arco
	void addEdge(int u, int v, long long w){
		edges.push_back({w, {u, v}}); // first = costo, second = conexión
	}
	void load();
	void kruskalMST();
	void printTotalCost();
};


//Disjoint Sets (Union-Find)
struct DisjointSets{
	int *parent, *rank;
	int n;
	DisjointSets(int n){
		this->n = n;
		parent = new int[n+1];
		rank = new int[n+1];
		for (int i=0; i<=n; i++){
			rank[i] = 0;
			parent[i] = i;
		}
	}
	// Para encontrar el parent de 'u'
	int find(int u){
		if (u != parent[u]){
			parent[u] = find(parent[u]);
		}
		return parent[u];
	}
	void merge(int x, int y){
		x = find(x);
		y = find(y);
		if (rank[x] > rank[y]){
			parent[y] = x;
		}
		else{
			parent[x] = y;
		}
		if (rank[x] == rank[y]){
			rank[y]++;
		}
	}
};

void Graph::load(){
	int a, b;
    long long c;
	for (int i=0; i<E; i++){
		cin >> a >> b >> c;
		addEdge(a, b, c);
	}
}


// Complejidad: O(E log E)
void Graph::kruskalMST(){
	sort(edges.begin(), edges.end());
	DisjointSets ds(V);

	costMSTKruskal = 0;
	for(auto it:edges){
		int p1 = ds.find(it.second.first);
		int p2 = ds.find(it.second.second);
        
		if(p1 != p2){
			costMSTKruskal += it.first;
			selectedEdgesK.push_back(it);
			ds.merge(it.second.first, it.second.second);
		}
	}
}

void Graph::printTotalCost(){
	//verificar si el grafo está conectado
	if(selectedEdgesK.size() == V-1){
		cout << "Costo Total: "<< costMSTKruskal << endl; //costo total de reparación
	} else {
		cout << "IMPOSSIBLE" << endl;
	}

}

int main(){
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
