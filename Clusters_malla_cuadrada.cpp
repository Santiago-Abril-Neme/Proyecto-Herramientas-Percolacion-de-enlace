#include <iostream>
#include <bits/stdc++.h> 
#include <vector>
#include <random>
#include <fstream>

using namespace std;

//Delta p con el cual va a ir disminuyendo  el parametro p de la percolacion hasta llegar a cero
float dp = 0.5;

int main() {
	
	vector<pair <int, int>> M;
	
	//Lee el csv Matriz_interconexion_sq, lo guarda en una matriz M
	ifstream M_data;
    M_data.open("Matriz_interconexion_sq.csv");
    
    //Variables auxiliares que contendran: (row) Cada fila al leer, (Pareja) cada pareja en los datos antes de ser guardados, (num) cada numero en los datos antes de asignarse a una pareja
	string row, num;
    pair <int, int> Pareja;
    
    //Se itera sobre cada fila de M_data
    while (getline(M_data, row)) {
		stringstream s(row);
		
		//Contador del numero de bucles para formar Pareja
		int count = 0;
		
		//Se itera sobre cada numero en row
		while(getline(s,num,',')){
			//Antes de guardar cada num se conviere a entero usando la funcion atoi()
			//La extension .c_str() se debe a que atoi() recibe el puntero, no el string directamente
			if(count%2==0){
				Pareja.first = atoi(num.c_str());
			}
			else{
				Pareja.second = atoi(num.c_str());
				M.push_back(Pareja);
			}
			count +=1;
		}
    }
    M_data.close();
	
	
	//Genera un vector de numeros aleatorios uniformes en el intervalo (0,1) del mismo tamaño que parejas en N
  	vector<float> U_vec;
	  
	random_device rd;
	mt19937 gen(rd());
  	uniform_real_distribution<> dist(0, 1);
  	
  	for(int i=0; i<M.size(); i++){
	  	U_vec.push_back(dist(gen));
  	}
  	
  	//Se itera para diferente valores de la percolacion a partir de 1
  	for(int p =1; p>0; p+=dp){
  			
	}
  	
	return 0;
}
