#ifndef __META_TSP_Instancia__
#define __META_TSP_Instancia__
#include <iostream>
#include <vector>
#include <fstream>
#include "Nodo.hpp"
using namespace std;

class Instancia{
private:
	vector <Nodo> _instance;
public:
	Instancia(int numInstancias,char * fich){
	leerFichero(fich,&_instance);
	};
	
	void leerFichero(char * fichero,vector <Nodo> * _instance);
	void imprimirInstancia();

	inline vector <Nodo> getInstance(){return _instance;};

	
};




void Instancia::leerFichero(char * fichero,vector <Nodo> * _instance){

	char cadena [50];
	float x,y;
	int n;
	Nodo aux;

	ifstream fe(fichero);
	if(!fe){
		cout<<"Error al cargar los puntos"<<endl;
	}else{
		while(!fe.eof()){
			fe.getline(cadena,50);
			if(sscanf(cadena,"%d %f %f",&n,&x,&y)){
			//cout<<"numero: "<<n<<" coordenadas: "<<x<<" - "<<y<<endl;
				aux.setIdNodo(n);
				aux.setEjeX(x);
				aux.setEjeY(y);
				_instance->push_back(aux);
			}
		}
		_instance->erase(_instance->end());

//cout<<instance.size()<<endl;

	}

}

void Instancia::imprimirInstancia(){
	cout<<endl;
	for(int i=0; i < _instance.size();i++)
	cout<<"Nodo -->"<<_instance[i].getIdNodo()<<" "<<_instance[i].getEjeX()<<" "<<_instance[i].getEjeY()<<endl;
}

#endif
