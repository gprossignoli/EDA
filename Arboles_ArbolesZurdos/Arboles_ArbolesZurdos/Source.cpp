// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
void resolver(bintree<char> const& t,bool & isLefty,int & nLeftSons,int & nRightSons) {
	
	if (!t.empty()) {
		if (!t.left().empty()) {
			++nLeftSons;
			resolver(t.left(), isLefty, nLeftSons, nRightSons);
		}


		if (!t.right().empty()) {
			++nRightSons;
			resolver(t.right(), isLefty, nLeftSons, nRightSons);

			const int nSons = nLeftSons + nRightSons;
			if (nLeftSons <= (nSons / 2))
				isLefty = false;
		}
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<char> tree;
	
	tree = leerArbol('.');

	if (tree.empty() || (tree.left().empty() && tree.right().empty() ))
		std::cout << "Si\n";

	else {
		bool isLefty = true;
		int nLeftSons = 0;
		int nRightSons = 0;

		resolver(tree, isLefty, nLeftSons,nRightSons);
		if (isLefty)
			std::cout << "SI\n";
		else
			std::cout << "NO\n";
	}


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