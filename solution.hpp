#ifndef __META_TSP_Solution__
#define __META_TSP_Solution__

#include <iostream>
#include <vector>
#include "InstanciaTSP.hpp"
#include <cmath>
using namespace std;

class solution{

private:
vector <int> camino;
int peso;
public:
	solution(vector <int> X){
		camino=X;
		peso=0;
		
	}
	solution(const solution & copia){
		camino=copia.camino;
		peso=0;
	}
	solution(){
	}

	vector <int> & getCamino(){return camino;};
	int getPeso(){return peso;};
	void calcularPeso(Instancia & solucion);
	solution& operator = (const solution &p);
	void imprimir();

};

void solution::calcularPeso(Instancia & solucion){
vector<Nodo> aux=solucion.getInstance();
int i=0;
int j=1;
	for(i=0;i<aux.size();i++){
	peso+=sqrt((pow(aux[camino[i]].getEjeX()-aux[camino[j]].getEjeX(),2)) + (pow(aux[camino[i]].getEjeY()-aux[camino[j]].getEjeY(),2)));
	j++;
	}


};
solution& solution::operator = (const solution &p){
    if(this!=&p){ //Comprueba que no se esté intentanod igualar un objeto a sí mismo
        this->camino = p.camino;
        this->peso = p.peso;
    }
    return *this;
};
void solution::imprimir(){
	cout<<"camino: "<<endl;
	for(int i=0;i<camino.size();i++){
		cout<<camino[i]<<" ";
	}
	cout<<endl;
	cout<<"Peso: "<<peso<<endl;	

}

#endif
