#ifndef BASICOS_H
#define BASICOS_H
// ↑ abre el bloque

/*
header guards: previenen que general.h se incluya varias veces
indirectamente cuando varios .h lo incluyen, asi no se procesaran dos veces, 
si eso pasa habria errores de "redefinicion" de structs/funciones 
*/ 

//INCLUDES - NO NECESITAMOS VOLVERLOS A INCLUIR EN LOS .CPP
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cctype>
#include <string>

using namespace std;

// STRUCTS OF BASIC STRUCTS NEEDED & GRAPH STRUCTS NEEDED

//CONSTANTS
const int INF = 1000000000;  // ← problema2.cpp 

#endif