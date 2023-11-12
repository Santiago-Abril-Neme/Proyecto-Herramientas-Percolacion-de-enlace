#include <iostream>
#include <vector>
#include <random>

// este arreglo es solo para hacer test
std::vector<int> generarArregloAleatorio(int N, int k, int n) {
    std::vector<int> arreglo;
    std::random_device rd;
    std::mt19937 gen(rd());

    int longitud = N;
    int contador = 0;
    int valorActual = 1;
    int repeticiones = 0;

    while (contador < longitud) {
        int cantidad = std::rand() % n + 1; 

        if (cantidad + contador > longitud) {
            cantidad = longitud - contador; 
        }

        for (int i = 0; i < cantidad; ++i) {
            arreglo.push_back(valorActual);
            ++contador;
        }

        ++repeticiones;

        if (repeticiones <= k) {
            ++valorActual;
            repeticiones = 0;
        }
    }

    return arreglo;
}


std::pair<int, int> encontrarPosiciones(std::vector<int> arreglo, int valor, int k) {
    std::pair<int, int> posiciones = {-1, -1}; // Inicializar con valores que indican que no se encontro ninguna posicion

    for (int i = k / 2; i < arreglo.size(); ++i) {
        if (arreglo[i] == valor) {
            if (posiciones.first == -1) {
                posiciones.first = i + 1; // Primera ocurrencia encontrada
            }
            posiciones.second = i + 1; // Ultima ocurrencia actualizada
        }
    }

    return posiciones;
}


int main() {
    int N, n, k;

    std::cout << "Ingrese la longitud del arreglo: ";
    std::cin >> N;

    std::cout << "Ingrese el valor máximo (n) para los elementos del arreglo: ";
    std::cin >> n;

    std::cout << "Ingrese el número máximo de repeticiones (k): ";
    std::cin >> k;

    std::vector<int> arregloAleatorio = generarArregloAleatorio(N, n, k);

    std::cout << "Arreglo aleatorio: ";
    for (int num : arregloAleatorio) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int numeroBuscado;
    std::cout << "Ingrese el número a buscar (entre 1 y " << n << "): ";
    std::cin >> numeroBuscado;

    if (numeroBuscado >= 1 && numeroBuscado <= n) {
        std::pair<int, int> posiciones = encontrarPosiciones(arregloAleatorio, numeroBuscado, k);

        if (posiciones.first != -1) {
            std::cout << "Primera posición del número " << numeroBuscado << ": " << posiciones.first << std::endl;
            std::cout << "Última posición del número " << numeroBuscado << ": " << posiciones.second << std::endl;
        } else {
            std::cout << "El número no se encontró en el arreglo." << std::endl;
        }
    } else {
        std::cout << "Número ingresado fuera de rango." << std::endl;
    }

    return 0;
}
