// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"


void findBorder(bintree<int> const& tree, std::vector<int> & sol) {
	if (tree.left().empty() && tree.right().empty()) {
		sol.push_back(tree.root());
	}
	else {
		if(!tree.left().empty())
			findBorder(tree.left(), sol);
		if(!tree.right().empty())
			findBorder(tree.right(), sol);
	}
}


void resuelveCaso() {
	bintree<int> tree;
	std::vector<int> sol;
	tree = leerArbol(-1);
	
	if (!tree.empty()) {
		findBorder(tree, sol);

		int i = 0;
		for (i; i < sol.size() - 1; ++i) {
			std::cout << sol[i] << " ";
		}
		std::cout << sol[i];
	}

	std::cout << '\n';



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