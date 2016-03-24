#ifndef __META_TSP_SolGen__
#define __META_TSP_SolGen__
#include <iostream>
#include "Nodo.hpp"
#include "InstanciaTSP.hpp"
#include "aleatorio.hpp"
#include <vector>
#include <cmath>
using namespace std;

class solGenerator{
private:

public:
	solGenerator(){};
	int solAlgoritmoTSP(Instancia & solucion, vector <int> * auxiliar);

};

int solGenerator::solAlgoritmoTSP(Instancia & solucion,vector <int> * auxiliar){
	
	vector<Nodo> aux;
	vector <int> porVisitar;
	aux=solucion.getInstance();
	int matrizDeDistancias[aux.size()][aux.size()];
	for (int i = 0; i < aux.size(); ++i)
	{
		for (int j = 0; j < aux.size(); ++j)
		{
			if (i == j)
			{
				matrizDeDistancias[i][j]=9999999;
			}
			else
			matrizDeDistancias[i][j]=sqrt((pow(aux[i].getEjeX()-aux[j].getEjeX(),2)) + (pow(aux[i].getEjeY()-aux[j].getEjeY(),2)));
		}
	}

//prueba

 ofstream fs("matrizDistancias.txt"); 

 for (int i = 0; i < aux.size(); ++i)
	{
		for (int j = 0; j < aux.size(); ++j)
		{
			fs<<matrizDeDistancias[i][j]<<" ";
		}
			fs<<endl;
	}

   fs.close();



	//creamos un vector de enteros que tenga las posiciones de todos los nodos.
	for(int i=0;i<aux.size();i++){
		porVisitar.push_back(i);
	}
	//a partir de aqui, ya tenemos la matriz de distancia y un vector que contenga todas las posiciones, ahora lo que hacemos es el propio algoritmo aleatorio, lo haremos con un while que se encarge de generar una posicion aleatoria nueva en la matriz de distancias, y ahora, del vector con todas las posiciones cojo y saco el nuevo en el que estoy, para no poder volver a el, aumento la distancia nueva desde el que estaba al que voy, y cambio el antiguo ahora sera el nuevo, seria como avanzar a ese nodo, para definir uno nuevo al que ir y así hasta que no queden mas nodos.

	int anterior=aleatorio((porVisitar.size()));//creo el nodo en el que comenzara
	int antiguo;
	int primero=anterior;//lo almaceno en el primero, para cerrar el ciclo con el
	int nuevo;
	int distanciaTotal=0;
	
	vector<int>::iterator it = porVisitar.begin();
	auxiliar->push_back(porVisitar[anterior]);
	advance(it, anterior);
	antiguo=porVisitar[anterior];
	porVisitar.erase(it);//lo elimino del vector por visitar
	
	
	while(porVisitar.size()>1){
		nuevo=aleatorio((porVisitar.size()));
		auxiliar->push_back(porVisitar[nuevo]);

		distanciaTotal+=matrizDeDistancias[antiguo][porVisitar[nuevo]];
		
		
		it=porVisitar.begin();
		antiguo=porVisitar[nuevo];
		advance(it, nuevo);	
		porVisitar.erase(it);
	}
		distanciaTotal+=matrizDeDistancias[antiguo][porVisitar[0]];
		auxiliar->push_back(porVisitar[0]);
		auxiliar->push_back(primero);
		

	return distanciaTotal;
}
#endif
