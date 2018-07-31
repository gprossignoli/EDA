// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
void resolver(std::vector<int> & v, int left, int right) {
	int i = left;
	int j = right;

	int pivot = v[(left + right) / 2];
	
	while (i <= j) {
		while (v[i] < pivot) {
			++i;
		}
		while (v[j] > pivot) {
			--j;
		}
		if (i <= j) {
			std::swap(v[i], v[j]);
			++i;
			--j;
		}
	}

	if (left < j) {
		resolver(v, left, j);
	}
	if (i < right) {
		resolver(v, i, right);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nElem, elem;
	std::vector<int> v;

	std::cin >> nElem;
	if (!std::cin)
		return false;

	for (int i = 0; i < nElem; ++i) {
		std::cin >> elem;
		v.push_back(elem);
	}

	resolver(v, 0, v.size()-1);
	
	std::cout << v[0] << '\n';
	
	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}