// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool resolver(std::vector<int> const& v, const int maxHeight) {
	int iniSeg, endSeg;
	bool valid = true;
	int i = 1;
	iniSeg = 0;

	/*I --> 1 <= i <= v.size() && valid = forall j,k : 0 <= j <= k < i : v[k] - v[j] <= maxHeight */
	while (i < v.size()) {
		if (v[i - 1] >= v[i] && valid)  {
			endSeg = i - 1;
			
			if (v[endSeg] - v[iniSeg] > maxHeight)
				valid = false;

			iniSeg = i;
		}
		/*I --> 1 <= i <= v.size() && valid = exists j,k : 0 <= j < k <= i : v[k] - v[j] > maxHeight*/
		++i;
	}
	//f(i) = v.size() - 1 - i
	return valid;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int maxHeight, nHeights, height;
	std::vector<int> mountain;

	std::cin >> maxHeight;
	if (!std::cin)
		return false;
	std::cin >> nHeights;

	for (int i = 0; i < nHeights; ++i) {
		std::cin >> height;
		mountain.push_back(height);
	}

	bool validRoute = resolver(mountain,maxHeight);

	if (validRoute)
		std::cout << "apta\n";

	else
		std::cout << "no apta\n";



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