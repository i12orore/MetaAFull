// X1NeighExplorator
#ifndef __X1_NEIGH_EXPLORATOR__
#define __X1_NEIGH_EXPLORATOR__

#include <vector>
#include <iostream>
#include "aleatorio.hpp"
//Suponiendo X1 First Improvement Strategy --> Mira a los vecinos y el primero que se cambia es el que sea mejor al que estoy buscando
//el X2 será el Best Improvement Strategy --> Mira todos los vecinos y coge el mejor
class FirstImprovementStrategyNeighExplorator
{
private:



public:

int SolucionVecina(){
//solucion aleatoria
int posicionABuscar=aleatorio()
//declaro el vector que voy a usar
std::vector<int> vector;
//encontrar posicion para buscar vecinos
for (int i = 0; i < vector.size(); i++) {
  if (posicionABuscar==vector[i]) {
      posicionAnterior==vector[i-1];
      posicionPosterior==vector[i+1];
  }
}

}






};



#endif
