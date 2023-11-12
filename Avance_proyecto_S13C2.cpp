#include <iostream>
#include <bits/stdc++.h> 
#include <vector>
#include <random>
#include <fstream>

using namespace std;

const int N=100; //Lado de la malla

//La funcion vecinos_malla_cuadrada recibe el numero de una particula (i) y devuelve el numero de las particulas vecinas.

//Se consideran 8 casos de particulas en una red no periodica cuadrada: 
// I) Esquina superior izquierda
// II) Esquina superior derecha
// III) Esquina inferior izquierda
// IV) Esquina inferior derecha
// V) Borde superior
// VI) Borde izquierdo
// VII) Borde derecho 
// VIII) Borde inferior
// IX) Interior
vector<int> vecinos_malla_cuadrada(int i){
  
  	vector<int> neighbors;
  
  	switch(i){
	
    //I)
    case 1:
      	neighbors.push_back(i+1);
      	neighbors.push_back(i+N);
      	return neighbors;
    //II)
    case N:
      	neighbors.push_back(i-1);
      	neighbors.push_back(i+N);
      	return neighbors;
    //III)
    case N*(N-1)+1:
      	neighbors.push_back(i+1);
      	neighbors.push_back(i-N);
      	return neighbors;
    //IV)
    case N*N:
      	neighbors.push_back(i-1);
      	neighbors.push_back(i-N);
    	return neighbors;
  	}
  	//V)
  	if((i>1)&&(i<N)){
    	neighbors.push_back(i+1);
    	neighbors.push_back(i-1);
    	neighbors.push_back(i+N);
  	}
  	//VI)
	else if(i%N==1 && i!=1 && i!=N*(N-1)+1){
  	  	neighbors.push_back(i+1);
  	  	neighbors.push_back(i+N);
  	  	neighbors.push_back(i-N);
 	 }
  	//VII)
 	 else if(i%N==0 && i!=N && i!=N*N){
 	   neighbors.push_back(i-1);
   	 neighbors.push_back(i+N);
 	   neighbors.push_back(i-N);
 	 }
  	//VIII)
  	else if((i>N*(N-1)+1) && (i<N*N)){
    	neighbors.push_back(i+1);
    	neighbors.push_back(i-1);
    	neighbors.push_back(i-N);
  	}
  	//IX
  	else{
    	neighbors.push_back(i+1);
    	neighbors.push_back(i-1);
    	neighbors.push_back(i+N);
    	neighbors.push_back(i-N);
  	}
	return neighbors;
}

//La funcion encontrarPosiciones recibe un vector de enteros ordenados con repeticion (arreglo), un numero a buscar (valor) y un numero maximo de repeticiones posibles (k)
//devuelve tanto la primera posicion en la que encuenta el numero a buscar como la la ultima 
std::pair<int, int> encontrarPosiciones(std::vector<int> arreglo, int valor, int k) {
    std::pair<int, int> posiciones = {-1, -1}; // Inicializar con valores que indican que no se encontro ninguna posicion

    for (int i = 0; i < arreglo.size(); ++i) {
        if (arreglo[i] == valor) {
            if (posiciones.first == -1) {
                posiciones.first = i; // Primera ocurrencia encontrada
            }
            posiciones.second = i; // Ultima ocurrencia actualizada
        }
    }

    return posiciones;
}

int main() {

	vector<int> results_i;
	vector<int> results_j;
	
	for(int i=1; i<=N*N; i++){
		cout<<i<<endl;
		vector<int> vecinos = vecinos_malla_cuadrada(i);
		for(int j=0; j<vecinos.size(); j++){
			pair<int, int> posiciones = encontrarPosiciones(results_i,vecinos[j],2);
			bool add_pair = true;
			for(int k=posiciones.first; k<=posiciones.second;k++){
				if(k==i){
					add_pair= false;
				}
			}
			if(add_pair){
				results_i.push_back(i);
				results_j.push_back(vecinos[j]);
			}
		}
	}
	
	ofstream Matriz_interconexion;
	Matriz_interconexion.open("Matriz_interconexion_sq.csv");
	
	int parejas = results_i.size();
	for(int i=0; i<parejas;i++){
		Matriz_interconexion<<results_i[i]<<","<<results_j[i]<<endl;		
	}
	
	return 0;
}
