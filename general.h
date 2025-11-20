#ifndef BASICOS_H
#define BASICOS_H

/*
header guards ↑ 
previenen que general.h se incluya varias veces
indirectamente cuando varios .h lo incluyen, asi no se procesaan dos veces, 
si eso pasa habria errores de redefinicion de structs/funciones 
*/ 

//INCLUDES - NO NECESITAMOS VOLVERLOS A INCLUIR EN LOS .CPP
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cctype>
#include <string>

using namespace std;

// STRUCTS WE BOTH NEED

struct datosInput {
    int n; // # de colonias
    int m; // # de conexiones
    int k; // # conexiones con nuevo cableado
    int q; // # futuras colonias
};

struct colonia {
    string nombre;
    int x,y; // pos
    int esCentral; // 1 si es central, 0 si no
};

struct conexion {
    string col1, col2;
    int costo;
};

// FUNCIONES WE BOTH NEED

datosInput leerDatosIniciales() {
    datosInput datos;
    cin >> datos.n >> datos.m >> datos.k >> datos.q;
    return datos;
}

//CONSTANTS
const int INF = 1000000000;  // ← problema2.cpp 

#endif