// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
void resolve(const int k,bintree<int> const& t,int & nLeafsUnderK,int level) {
	if (t.empty()) {
		nLeafsUnderK = 0;
	}

	else if (t.left().empty() && t.right().empty()) {
		if (level >= k)
			++nLeafsUnderK;
	}

	else {
		if (!t.left().empty()) {
			resolve(k, t.left(), nLeafsUnderK, level + 1);
		}
		if (!t.right().empty()) {
			resolve(k, t.right(), nLeafsUnderK, level + 1);
		}
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int k;
	bintree<int> tree;

	std::cin >> k;
	tree = leerArbol(-1);

	int sol = 0;
	resolve(k,tree,sol,0);
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