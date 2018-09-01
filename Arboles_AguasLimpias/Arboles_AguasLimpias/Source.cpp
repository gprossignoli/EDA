// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
void resolver(bintree<int> const& map,int & flow,int & sol) {
	
	if (map.left().empty() && map.right().empty())
		++flow;

	else {
		if (!map.left().empty()) {
			int leftFlow = 0;
			resolver(map.left(), leftFlow, sol);
			flow += leftFlow;
		}
		if (!map.right().empty()) {
			int rightFlow = 0;
			resolver(map.right(), rightFlow, sol);
			flow += rightFlow;
		}
	}

	if (map.root() > 0) {
		if (flow - map.root() < 0)
			flow = 0;
		else
			flow -= map.root();
	}

	if (flow >= 3) {
		++sol;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<int> hydrographicMap;
	int navigableStretches = 0;
	hydrographicMap = leerArbol(-1);

	if (!hydrographicMap.empty()) {
		int leftFlow = 0;
		int rightFlow = 0;
		if(!hydrographicMap.left().empty())
			resolver(hydrographicMap.left(), leftFlow, navigableStretches);
		if (!hydrographicMap.right().empty())
			resolver(hydrographicMap.right(), rightFlow, navigableStretches);
	}
	else
		navigableStretches = 0;

	std::cout << navigableStretches << '\n';


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