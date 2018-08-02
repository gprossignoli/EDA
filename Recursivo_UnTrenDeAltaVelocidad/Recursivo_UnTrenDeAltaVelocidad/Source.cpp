// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>


int calculateAverage(std::vector<int> const & v) {
	int average = 0;
	for (int i = 0; i < v.size(); ++i) {
		average += v[i];
	}
	return average / v.size();
}

bool checkCondition(int const& elem, int const& avg) {
	int relation = elem - avg;
	const int halfOfAvg = avg / 2;
	
	if (relation > halfOfAvg)
		return false;

	return true;
}
// función que resuelve el problema
bool resolver(std::vector<int> const& v, int ini, int end, int const& avg) {

	if (ini + 1 == end) {
		if (!checkCondition(v[ini],avg) || !checkCondition(v[end],avg))
			return false;
		
		return true;
	}

	else {
		int half = (ini + end + 1) / 2;
		
		bool left = resolver(v, ini, half, avg);
		if (!left)
			return false;

		bool right = resolver(v, half, end, avg);
		if (!right)
			return false;

		return true;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nElems, elem;
	std::vector<int> section;

	std::cin >> nElems;
	if (!std::cin)
		return false;

	for (int i = 0; i < nElems; ++i) {
		std::cin >> elem;
		section.push_back(elem);
	}

	int average = calculateAverage(section);
	bool sol = resolver(section, 0 , section.size() - 1, average);

	if (sol)
		std::cout << "SI\n";
	else
		std::cout << "NO\n";
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