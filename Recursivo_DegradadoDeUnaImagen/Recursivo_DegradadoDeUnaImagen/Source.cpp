// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


struct tSolucion {
	int sum = 0;
	bool degraded = true;
};
// función que resuelve el problema
tSolucion resolver(std::vector<int> const& v, int ini, int end) {
	tSolucion sol;

	if (ini + 1 == end) {
		if (v[ini] >= v[end]) {
			sol.degraded = false;
		}
		sol.sum += v[ini] + v[end];
		return sol;
	}

	if (!sol.degraded) {
		return sol;
	}

	int half = (ini + end + 1) / 2;
	tSolucion left = resolver(v, ini, half-1);
	if (!left.degraded)
		return left;
		
	tSolucion right	= resolver(v, half, end);
	if (!right.degraded)
		return right;

	if (left.sum >= right.sum) {
		sol.degraded = false;
	}
	sol.sum += left.sum + right.sum;

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int nRows, nCols, row;
	
	tSolucion sol;

	std::cin >> nRows;
	if (!std::cin)
		return false;
	std::cin >> nCols;
	
	int i = 0;
	while (i < nRows) {
		std::vector<int> v;
		for (int j = 0; j < nCols; ++j) {
			std::cin >> row;
			v.push_back(row);
		}

		if(sol.degraded)
			sol = resolver(v, 0, v.size() - 1);	

		++i;
	}

	if (!sol.degraded)
		std::cout << "NO\n";

	else
		std::cout << "SI\n";

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