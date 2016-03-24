#ifndef __META_TSP_NeightO__
#define __META_TSP_NeightO__

#include <iostream>
#include <vector>
using namespace std;

class NeightOperator{
private:
int primero;
int segundo;
vector <int> auxiliar;
public:
	NeightOperator(solution pasada,int x, int y){
		primero=x;
		segundo=y;
		auxiliar=pasada.getCamino();	
		opt();
	}
	void opt();
	solution devolver();
		

};

void NeightOperator::opt(){
int aux;
	aux=auxiliar[primero];
	auxiliar[primero]=auxiliar[segundo];
	auxiliar[segundo]=aux;
		
		
};
solution NeightOperator:: devolver(){
	solution provisional(auxiliar);
	return provisional;	
};
#endif
