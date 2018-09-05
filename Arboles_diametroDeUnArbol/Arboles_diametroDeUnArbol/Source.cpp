// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

// función que resuelve el problema
int resolver(bintree<char> const& t,int & diameter) {


	if (t.left().empty() && t.right().empty()) {
		return 1;
	}
	else {
		int left = 0;
		int right = 0;
		if (!t.left().empty()) 
			left += resolver(t.left(), diameter) + 1;
		
		if (!t.right().empty() && !t.left().empty())
			right += resolver(t.right(), diameter);
		else if (!t.right().empty() && t.left().empty())
			right += resolver(t.right(), diameter) + 1;

		int depth = std::max(left, right);
		diameter = std::max(diameter, (left + right));

		return depth;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	bintree<char> tree;
	tree = leerArbol('.');

	int diameter = 0;
	if (tree.empty())
		diameter = 0;
	else if (tree.left().empty() && tree.right().empty())
		diameter = 1;
	else
		resolver(tree,diameter);
	std::cout << diameter << '\n';


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