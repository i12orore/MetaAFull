//LocalSearch
#ifndef __META_TSP_LocalSearch__
#define __META_TSP_LocalSearch__

#include "solution.hpp"
#include "NeightOperator.hpp"
#include "BestNeightOperator.hpp"
#include "FirstNeighOperator.hpp"

using namespace std;

class LocalSearch{

private:
solution inicial;

public:
	localSearch(solution pasada,Instancia & solucion){
		solution inicial=solucion;
		solution fin;
	}
	void localSearch(Instancia & solucion,solution & b);
	void printFin(){fin.imprimir();};
	solution devolver(){return fin;};



};

void LocalSearch::localSearch(Instancia & solucion, solution & b)
{
	int metodo;
	int contador=0;
	std::cout << "Antes de nada, debes decidir que tipo de Método de Búsqueda quieres aplicar, siendo:\n1 -- Para First Neigh Explorator\n2 -- Para Best Neig Explorator" << std::endl;
	std::cin >> metodo;
	if(metodo != (1||2)
		std::cout << "Seleccion erronea" << std::endl;
	else
	{
		if (metodo == 1)
		{
			for (int i = 0; i <1000 && contador < 3; i++)
			{
					final=firstNeightOperator q(b,prueba);
					final.calcularPeso();
					if(inicial.getPeso()!=fin.getPeso())
					{
						//si pasa esto, se intercambian, esto es lo que tengo que guardar
					}
					else
						contador++;
					inicial=final;
					inicial.getPeso();
			}//for
		}//if
		else
		{
			for (int i = 0; i < 1000 && contador < 3; i++)
			{
				if((inicial.getPeso()!=fin.getPeso())&&(contador<3))
				{
					bestNeightOperator q(b,prueba);
				}
				else
					contador++;
			}

		}

	}
}


#endif
