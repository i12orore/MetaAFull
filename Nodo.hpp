#ifndef __META_TSP_Nodo__
#define __META_TSP_Nodo__
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;



class Nodo{
public:
	Nodo(){
	idNodo=0;
	ejeX=0;
	ejeY=0;
	};
	void setIdNodo(int n){idNodo=n;};
	int getIdNodo(){return idNodo;};
	
	void setEjeY(float y){ejeY=y;};
	float getEjeY(){return ejeY;};
	
	void setEjeX(float x){ejeX=x;};
	float getEjeX(){return ejeX;};	
private:
	int idNodo;
	float ejeX,ejeY;
	
	
	
};
#endif

