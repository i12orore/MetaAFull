#ifndef __META_TSP__
#define __META_TSP__
#include <iostream>
#include <time.h>
#include <stdlib.h>



int aleatorio(int maximo){
int tope;	
	if(maximo!=-1){
		tope=maximo;
	}else{
		tope=964645486;
	}
	return rand()%tope;
}
#endif
