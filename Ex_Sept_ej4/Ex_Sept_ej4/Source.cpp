// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolve(const int sizeV,std::vector<int>const&v,int sumLeft,int pivot,int sumRight) {
	int sol = 1;
	//Invariable => 0<=pivot < sizeV - 1 && 0 <= pivot < sol
	while (pivot < sizeV-1) {
		++pivot;
		sumLeft += v[pivot -1];
		sumRight -= v[pivot];
		if (sumLeft < sumRight)
			++sol;
	}
	//Invariable => 0 < pivot <= sizeV - 1 && 1 <= sol < pivot
	//f(pivot) = (sizeV - 1) - pivot + 1
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int sizeV;
	std::vector<int> v;
	int sumRight = 0;

	std::cin >> sizeV;
	for (int i = 0; i < sizeV; ++i) {
		int elem;
		std::cin >> elem;
		v.push_back(elem);
		sumRight += elem;
	}
	sumRight -= v[0];
	
	int sol = resolve(sizeV,v,0,0,sumRight);

	std::cout << sol << '\n';


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}