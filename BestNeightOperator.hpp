#ifndef __META_TSP_BNOperator__
#define __META_TSP_BNOperator__

#include "solution.hpp"
#include "NeightOperator.hpp"

using namespace std;

class bestNeightOperator{

private:
solution inicial;
solution fin;

public:
	bestNeightOperator(solution pasada,Instancia & solucion){
		inicial=pasada;
		inicial.calcularPeso(solucion);
		bestNeightOp(solucion);
	}
	void bestNeightOp(Instancia & solucion);
	void printFin(){fin.imprimir();};
	solution devolver(){return fin;};



};

void bestNeightOperator::bestNeightOp(Instancia & solucion){
	fin=inicial;
solution auxiliar;
	for(int i=0;i<inicial.getCamino().size()-1;i++){
		for(int j=i+1;j<inicial.getCamino().size()-1;j++){
			NeightOperator a (inicial,i,j);
			auxiliar=a.devolver();
			auxiliar.calcularPeso(solucion);
			if(auxiliar.getPeso()<fin.getPeso()){
				std::cout << "lo cambio" << std::endl;
				fin=auxiliar;
			}

		}
	}

}


#endif
