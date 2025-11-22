#ifndef PROBLEMA4_H
#define PROBLEMA4_H
// Codigo basado en Actividad 15 - Best Friends in BeagleTown 

/*
PROBLEMA:
Se leera a continuación una serie de puntos cartecianos en el mapa de la ciudad en donde se planea conectar nuevas colonias -> q
y se deberá decir cual es la colina y punto carteciano más cercano con el cual se debe conectar.-> n 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cfloat>

using namespace std;

struct Point{
    string name;
    float x,y;
    Point(){
        x=y=0;
    }
    Point(float x, float y, string name){
        this->x =x;
        this->y = y;
    }
};


/*bool compareX(const Point &p1, const Point &p2){
    return (p1.x <p2.x);
}

bool compareY(const Point &p1, const Point &p2){
    return (p1.y < p2.y);
}*/

float dist(Point &p1, Point &p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

struct closestColonias{
    string colonia1;
    string colonia2;
    float dist;
};

/* External shared data from problema1
  struct coloniaDataGlobal {
      string nombre;
      int x, y;
      int esCentral;
  }*/

//GLOBAL DATA!!!
extern vector<coloniaDataGlobal> sharedExistingColonias;
extern vector<pair<string, pair<int, int>>> sharedNewColonias;
extern int sharedN, sharedM, sharedK, sharedQ;


//aqui lo que hice fue cambiar los floats al struct de arriba
/*closestColonias bruteForce(vector<Point> &P, int ini, int fin){
    closestColonias min_aux;
    min_aux.dist = FLT_MAX;

    for (int i=ini; i<fin; i++){
        for(int j=i+1; j<=fin; j++){
            float d = dist(P[i], P[j]);
            if (d < min_aux.dist){
                //structName.fieldName = value;
                min_aux.dist = d;
                min_aux.colonia1 = P[i].name;
                min_aux.colonia2 = P[j].name;
            }  
        }
    }
    return min_aux;
}*/

/*closestColonias stripClosest(vector<Point> &strip, float dMenor){
    closestColonias min_Strip;
    min_Strip.dist =FLT_MAX;
    sort(strip.begin(), strip.end(), compareY);

    for (int i=0; i<strip.size()-1; i++){
        for (int j=i+1; j<=strip.size()-1; j++){
            min_Strip = min(min_Strip, dist(strip[i], strip[j]));
        }
    }

    for (int i=0; i<strip.size()-1; i++){
        for (int j=i+1; j<=strip.size()-1; j++){
            float d_Strip = dist(strip[i], strip[j]);
            if (d_Strip < min_Strip.dist){
                min_Strip.dist = d_Strip;
                min_Strip.colonia1 = strip[i].name;
                min_Strip.colonia2 = strip[j].name;
            }
        }
    }
    return min_Strip;
}*/

/*closestColonias closest_Helper(vector<Point> &P, int ini, int fin){
    //como voa parar esa recursividad
    if (fin-ini <3){
        return bruteForce(P, ini, fin);
    }
    int mid = (fin+ini)/2;
    Point midPoint = P[mid];
    //buscame menor de izq y menor de der
    closestColonias dl;
    closestColonias dr;
    closestColonias dMenor;
    dl = closest_Helper(P, ini, mid);
    dr = closest_Helper(P,mid+1, fin);
    
    if (dl.dist < dr.dist){
        dMenor = dl;
    }else{
        dMenor = dr;
    }

    vector<Point> strip;
    for (int i=ini; i<=fin; i++){
        if(abs(P[i].x-midPoint.x) < dMenor.dist){ //comparamos 
            strip.push_back(P[i]);
        }
    }

    closestColonias ds;
    ds = stripClosest(strip, dMenor.dist);

    if (ds.dist < dMenor.dist){
        return ds;
    }else{
        return dMenor;
    }


    //float ds = stripClosest(strip, dMenor);
    //return ds;
}*/

// complejidad : O(n log n)
// metodo divide y venceras
/*closestColonias closest(vector<Point> &P){
    sort(P.begin(), P.end(), compareX); // sorts por x coordinate, esencial para divide and conquer
    return closest_Helper(P,0,P.size()-1);
}*/

void solucionProblema4(){
    //n =cantidad de puntos
    int n = sharedN;
    int q = sharedQ;
    /*int n, m, k, q;
    string colonia;
    float x, y;
    int c;  
    cin >> n >> m >> k >> q;*/
    vector<Point> existingColonias(n);
    vector<Point> newColonias(q);

    //GLOBAL DATA !!!
    for (int i=0; i<n; i++){
        existingColonias[i].x=sharedExistingColonias[i].x;
        existingColonias[i].y=sharedExistingColonias[i].y;
        existingColonias[i].name = sharedExistingColonias[i].nombre;
    }

    /*hago skip a m 
    string colonia1,colonia2;
    int distm;
    for(int i=0;i<m; i++){
        cin >> colonia1 >> colonia2 >> distm;
    }

    //hago skip a la k 
    for (int i=0; i<k;i++){
        cin >> colonia1 >> colonia2;
    }*/

    //GLOBAL DATA FROM PROB1!!
    for (int i=0; i<q; i++){
        newColonias[i].x=sharedNewColonias[i].second.first;
        newColonias[i].y= sharedNewColonias[i].second.second;
        newColonias[i].name = sharedNewColonias[i].first;
    }
    
    for (int i=0;i<q;i++){
        float minimumDist =FLT_MAX;
        string closestColonia = ""; //meaning?
        for (int j=0;j<n; j++){
            float d = dist(newColonias[i],existingColonias[j]);
            if (d < minimumDist){
                minimumDist = d;
                closestColonia = existingColonias[j].name; 
            }
        }
        cout << setprecision(2) << fixed;
        cout << newColonias[i].name << " debe conectarse con " << closestColonia << endl;
    }
}


/*
sample input:
5 <- total # of beagles  
Sparko 5 10 <- sparko esta en las coordenadas 5 y 10
Rocky 2 30 <- rocky esta en las 2 y 30
Prue 1 15 <- prue en las 1 y 15
Nico 10 2 <- nico en las 10 y 2 
Nerea 20 5 <- nerea en las 20 y 5 

sample output:
Best friend in BeagleTown are: Prue & Sparko (6.40) -> these beagles are closest to eachother according to distancia euclideana, ouput en lexographical order
*/




#endif