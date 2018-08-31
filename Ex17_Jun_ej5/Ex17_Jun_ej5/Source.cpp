// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
bool resolve(std::vector<int> const& a, std::vector<int> const& b,int&sol,int ini,int end) {

	if (ini == end)
		return false;

	else if (a[ini] != b[ini]) {
		sol = a[ini];
		return true;
	}

	else if (a[end - 1] == b[end - 1]) {
		sol = a[end];
		return true;
	}

	else {
		int mid = (ini + end) / 2;
		bool left = resolve(a, b, sol, ini, mid);
		if (!left)
			resolve(a, b, sol, mid, end);
	}


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int sizeA;
	std::vector<int> a;
	std::vector<int> b;

	std::cin >> sizeA;
	for (int i = 0; i < sizeA; ++i) {
		int elem;
		std::cin >> elem;
		a.push_back(elem);
	}
	for (int i = 0; i < sizeA - 1; ++i) {
		int elem;
		std::cin >> elem;
		b.push_back(elem);
	}
	int sol = -1;
	resolve(a, b, sol, 0, sizeA-1);
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