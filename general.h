#ifndef GENERAL_H
#define GENERAL_H

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
#include <queue>
#include <map>




using namespace std;

// STRUCTS WE BOTH NEED

// FUNCIONES WE BOTH NEED

//CONSTANTS
#define INF INT_MAX
#define Edge pair<int,int>
#define Graph vector<vector<Edge>>
#define Vertex pair<int, int> 
#define MAX 10
//COSAS DE GRAFOS MYBERS


#endif