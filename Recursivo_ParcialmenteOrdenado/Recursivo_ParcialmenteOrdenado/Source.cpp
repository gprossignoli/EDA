// Gerardo Parra Rossignoli	
// E45

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSolucion {
	int max;
	int min;
	bool partiallyOrdered;
};
// función que resuelve el problema
tSolucion resolver(std::vector<int> const& v,int ini,int end) {
	tSolucion sol;
	if (ini + 1 == end) {
		if (v[ini] >= v[end]) {
			sol.max = v[ini];
			sol.min = v[end];
		}
		else {
			sol.max = v[end];
			sol.min = v[ini];
		}
	}
	else {
		int half = (ini + end + 1) / 2;
		tSolucion left = resolver(v, ini, half);
		if (left.partiallyOrdered) {
			tSolucion right = resolver(v, half, end);
			if (right.partiallyOrdered) {
				sol.partiallyOrdered = (right.max >= left.max) && (right.min >= left.min);
				if (sol.partiallyOrdered) {
					sol.max = right.max;
					sol.min = left.min;
				}
				else {
					sol.max = left.max;
					sol.min = right.min;
				}
			}
			else
				right.partiallyOrdered = false;
		}
		else
			sol.partiallyOrdered = false;
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int elem;
	std::cin >> elem;
	if (elem == 0)
		return false;
	std::vector<int> input;
	while (elem != 0) {
		input.push_back(elem);
		std::cin >> elem;
	}
	if (input.size() > 1) {
		tSolucion sol = resolver(input, 0, input.size() - 1);
		if (sol.partiallyOrdered)
			std::cout << "SI";
		else
			std::cout << "NO";
	}
	else
		std::cout << "SI";
	std::cout << " \n";
	// escribir sol

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