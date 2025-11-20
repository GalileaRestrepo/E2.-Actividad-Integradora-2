#include "general.h"
#include "problema1.h"
#include "problema2.h"
#include "problema3.h"
#include "problema4.h"

// clang++ main.cpp -o programa
// ./programa

// clang++ main.cpp -o programa
// ./programa
int main(){
    
    procesarCasos(); // problema 2
    
    return 0;

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
