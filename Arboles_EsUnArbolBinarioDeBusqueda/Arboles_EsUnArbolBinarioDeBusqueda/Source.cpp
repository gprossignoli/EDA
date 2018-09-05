// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
const bool resolver(bintree<int> const& t) {

	if (t.left().empty() && t.right().empty())
		return true;

	else {
		bool left = true;
		bool right = true;
		if (!t.left().empty()) {
			if (t.left().root() < t.root())
				left = resolver(t.left());
			else
				left = false;
		}

		if (left) {
			if (!t.right().empty()) {
				if (t.right().root() > t.root())
					right = resolver(t.right());
				else
					right = false;
			}
		}


		return (left && right);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int> tree;
	tree = leerArbol(-1);

	bool isBinaryTreeOfSearch = false;
	if (tree.empty())
		isBinaryTreeOfSearch = true;
	else
		isBinaryTreeOfSearch = resolver(tree);

	if (isBinaryTreeOfSearch)
		std::cout << "SI\n";
	else
		std::cout << "NO\n";


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