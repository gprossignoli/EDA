// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

void exploreTheMap(bintree<int> const& tree, int nDragons, int & lowestNDragons, int & idPath) {
	if (tree.left().empty() && tree.right().empty()) {
		if (nDragons < lowestNDragons) {
			lowestNDragons = nDragons;
			idPath = tree.root();
		}
	}

	else {
		if (tree.root() == 1) {
			if (!tree.left().empty())
				exploreTheMap(tree.left(), nDragons + 1, lowestNDragons, idPath);
			if(!tree.right().empty())
				exploreTheMap(tree.right(), nDragons + 1, lowestNDragons, idPath);
		}
		else if (tree.root() == 2 ||tree.root() == 0) {
			if (!tree.left().empty())
				exploreTheMap(tree.left(), nDragons, lowestNDragons, idPath);
			if (!tree.right().empty())
				exploreTheMap(tree.right(), nDragons, lowestNDragons, idPath);
		}
	}
}

int findBestPathToTheTreasure(bintree<int> const& tree) {
	
	int lowestNDragons = INT_MAX;
	int idPath = -1;
	exploreTheMap(tree, 0, lowestNDragons, idPath);
	return idPath;
}

void resuelveCaso() {
	//root == 0 -> the treasure
	//node == 1 -> there's a dragon...
	//node == 2 -> no dragons around here :)
	//leaf node >= 3 -> id of the path
	bintree<int> treasureMap;

	treasureMap = leerArbol(-1);
	if(!treasureMap.empty())
		std::cout << findBestPathToTheTreasure(treasureMap);
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