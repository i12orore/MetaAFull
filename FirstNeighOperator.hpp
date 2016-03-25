#ifndef __META_TSP_FNOperator__
#define __META_TSP_FNOperator__

#include "solution.hpp"
#include "NeightOperator.hpp"

using namespace std;

class firstNeightOperator{

private:
solution inicial;
solution fin;

public:
	firstNeightOperator(solution pasada,Instancia & solucion){
		inicial=pasada;
		inicial.calcularPeso(solucion);
		firstNeightOp(solucion);
	}
	void firstNeightOp(Instancia & solucion);
	void printFin(){fin.imprimir();};
	solution devolver(){return fin;};



};

void firstNeightOperator::firstNeightOp(Instancia & solucion){
	fin=inicial;
solution auxiliar;
solution numerofinal;
int encontrado=0;

  	for(int i=0;i<inicial.getCamino().size()-1;i++)
    {
		    for(int j=i+1;j<inicial.getCamino().size()-1;j++)
        {
    			NeightOperator a (inicial,i,j);
    			auxiliar=a.devolver();
    			auxiliar.calcularPeso(solucion);
      			if(auxiliar.getPeso()<fin.getPeso()&&encontrado==0)
            {
							std::cout << "lo cambio" << std::endl;
              encontrado=1;
							fin=auxiliar;
	          }
        }
	   }

}


#endif
