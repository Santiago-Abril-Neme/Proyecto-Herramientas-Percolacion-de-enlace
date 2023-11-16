#include <iostream>
#include <bits/stdc++.h> 
#include <vector>
#include <random>
#include <fstream>

using namespace std;

const int N=20; //Lado de la malla

//La funcion vecinos_malla_triangular recibe el numero de una particula (i) y devuelve el numero de las particulas vecinas.

//Se consideran 8 casos de particulas en una red no periodica triangular: 
// I) Esquina superior izquierda
// II) Esquina superior derecha
// III) Esquina inferior izquierda
// IV) Esquina inferior derecha
// V) Borde superior
// VI) Borde izquierdo
// VII) Borde derecho 
// VIII) Borde inferior
// IX) Interior
vector<int> vecinos_malla_triangular(int i){
  
  	vector<int> neighbors;
  
  	switch(i){
	
    //I)
    case 1:
      	neighbors.push_back(i+1);
      	neighbors.push_back(i+N);
      	neighbors.push_back(i+N+1);
      	return neighbors;
    //II)
    case N:
      	neighbors.push_back(i-1);
      	neighbors.push_back(i+N);
      	return neighbors;
    //III)
    case N*(N-1)+1:
    	
    	neighbors.push_back(i-N);
    	
    	if(N%2!=0){
      		neighbors.push_back(i-N+1);
		  }
		  
      	neighbors.push_back(i+1);
      	
      	return neighbors;
    //IV)
    case N*N:
    	
    	if(N%2==0){
      		neighbors.push_back(i-N-1);
		  }
    	
    	neighbors.push_back(i-N);
		neighbors.push_back(i-1); 
      	
      	
    	return neighbors;
  	}
  	//V)
  	if((i>1)&&(i<N)){
  		neighbors.push_back(i-1);
    	neighbors.push_back(i+1);
    	neighbors.push_back(i+N);
    	neighbors.push_back(i+N+1);
  	}
  	//VI)
	else if(i%N==1 && i!=1 && i!=N*(N-1)+1){
		//fila impar
		if(i%(2*N)==1){
			neighbors.push_back(i-N);
			neighbors.push_back(i-N+1);
			neighbors.push_back(i+1);
	  	  	neighbors.push_back(i+N);
	  	  	neighbors.push_back(i+N+1);
		}
		//fila par
  	  	else{
  	  		neighbors.push_back(i-N);
  	  		neighbors.push_back(i+1);
	  	  	neighbors.push_back(i+N);
		}
			
 	 }
  	//VII)
 	 else if(i%N==0 && i!=N && i!=N*N){
 	 	//fila par
 	 	if(i%(2*N)==0){
 	 		neighbors.push_back(i-N-1);
 	 		neighbors.push_back(i-N);
 	 		neighbors.push_back(i-1);
 	 		neighbors.push_back(i+N-1);
		   	neighbors.push_back(i+N);
		  }
		//fila impar
		else{
			neighbors.push_back(i-N);
			neighbors.push_back(i-1);
	   		neighbors.push_back(i+N);
		}
	 	
 	 }
  	//VIII)
  	else if((i>N*(N-1)+1) && (i<N*N)){
  		neighbors.push_back(i-N-1);
  		neighbors.push_back(i-N);
  		neighbors.push_back(i-1);
    	neighbors.push_back(i+1);
  	}
  	//IX
  	else{
  		//fila par
  		if(i%(2*N)>N){
  			neighbors.push_back(i-N-1);
  			neighbors.push_back(i-N);
  			neighbors.push_back(i-1);
  			neighbors.push_back(i+1);
  			neighbors.push_back(i+N-1);  
	    	neighbors.push_back(i+N);
						
		  }
		//fila impar
		else{
			neighbors.push_back(i-N);
			neighbors.push_back(i-N+1);
			neighbors.push_back(i-1);
			neighbors.push_back(i+1);
    		neighbors.push_back(i+N);
			neighbors.push_back(i+N+1);	
		}
    	
  	}
	return neighbors;
}


int main() {
	
	vector<int> results_i;
	vector<int> results_j;
	
	
	
	for(int i=1; i<=N*N; i++){
		vector<int> vecinos = vecinos_malla_triangular(i);
		for(int j=0; j<vecinos.size(); j++){
			if(i<vecinos[j]){
				results_i.push_back(i);
				results_j.push_back(vecinos[j]);
			}
		}
	}
	
	
		 //Numero aleatorio

  random_device rd;
  mt19937 gen(rd());
  uniform_real_distribution<> dist(0, 1);

  ofstream Matriz_interconexion;
  Matriz_interconexion.open("Matriz_interconexion_tr.csv");

  int parejas = results_i.size();
  for(int i=0; i<parejas;i++){
    Matriz_interconexion<<results_i[i]<< "," <<results_j[i]<< "," << dist(gen) << endl;		
  }
	
	return 0;

}
