#include <iostream>
#include <bits/stdc++.h> 
#include <vector>
#include <random>
#include <fstream>

using namespace std;

//Delta p con el cual va a ir disminuyendo  el parametro p de la percolacion hasta llegar a cero
int num_ps = 5;
//A partir del numero de ps se calcula el delta p necesario
float dp=1.0/(num_ps-1);

int main() {
	
	vector<pair <int, int>> M;
	float p;
	
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
	  	//cout<<U_vec[i]<<endl;
  	}
  	
  	
	//Se itera para diferente valores de la percolacion a partir de 1
	std::ofstream Matriz_de_enlaces_sq;
	Matriz_de_enlaces_sq.open("Matriz_de_enlaces_sq.csv");
	
	for(int i=0;i<num_ps-1;i++){
			Matriz_de_enlaces_sq<<1-(dp*i)<<",";
	}
	Matriz_de_enlaces_sq<<0<<endl;
	
	for(int k=0;k<U_vec.size();k++){
		Matriz_de_enlaces_sq<<1<<",";
		for(int j=1;j<(num_ps-1);j++){
			p=1-(dp*j);  
			if(U_vec[k]<p){
				Matriz_de_enlaces_sq<<1<<",";
			}
			else{
				Matriz_de_enlaces_sq<<0<<",";
			}
		}
		Matriz_de_enlaces_sq<<0<<endl;
		
		
	}
  	
  return 0;
}
