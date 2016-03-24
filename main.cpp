#include <iostream>
#include <fstream>
#include "solution.hpp"
#include "SolGenerator.hpp"
#include "aleatorio.hpp"
#include "NeightOperator.hpp"

using namespace std;

main(){
int aleatoria;
srand(time(NULL));
Instancia prueba(52,"berlin52.tsp");
vector<int> auxiliar;

solGenerator p;
//aqui simplemente devuelve un peso con un vector que es auxiliar, donde esta ordenado en aleatorio
aleatoria=p.solAlgoritmoTSP(prueba,&auxiliar);
/*for(int i=0;i<auxiliar.size();i++){
	if(i<auxiliar.size()-1)	
		cout<<auxiliar[i]<<"->";
	else{
		cout<<auxiliar[i]<<endl;
	}
}*/
//hasta aqui, la solucion esta en el vector aleatoria
//convierto la solucion en un objeto 
solution t(auxiliar);
//para imprimirlo
vector <int> &  auxiliar2=t.getCamino();

for(int i=0;i<auxiliar2.size();i++){
	if(i<auxiliar2.size()-1)	
		cout<<auxiliar2[i]<<"->";
	else{
		cout<<auxiliar2[i]<<endl;
	}
}
//calculo el peso, del vector aleatorio, le paso prueba para que tenga donde mirar los pesos y lo imprimo
t.calcularPeso(prueba);
cout<<t.getPeso()<<endl;
//le paso el aleatorio para que obtenga un primo a distancia 1
NeightOperator a (t,2,3);
//asigno la nueva solucion a b, tras haber realizado un cambio del 2 por el 3
solution b(a.devolver());

auxiliar2=b.getCamino();
for(int i=0;i<auxiliar2.size();i++){
	if(i<auxiliar2.size()-1)	
		cout<<auxiliar2[i]<<"->";
	else{
		cout<<auxiliar2[i]<<endl;
	}
}
//imprimo el peso de uno cambiado
b.calcularPeso(prueba);
cout<<endl;
cout<<b.getPeso()<<endl;
}




