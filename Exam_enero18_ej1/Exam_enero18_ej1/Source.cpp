// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector<int> const& v) {
	int maxLenght = 1;
	int currentLenght = 1;
	int i = 1;

	/* f(i) = v.size() - 1 - i*/ 
	/*Invariante --> 1 <= i <= v.size() 
	&& currentLenght = forall k : 0 <= k < v.size() : currentLenght < v.size() 
	&& maxLenght = forall t : 0 <= t < v.size() : maxLenght >= currentLenght*/ 

	while (i < v.size()) {
		if (v[i - 1] >= v[i]) {
			++currentLenght;
		}

		else {
			
			if (currentLenght > maxLenght) {
				maxLenght = currentLenght;
			}
			currentLenght = 1;

		}
		// R --> 1 <= currentLengt <= maxLenght
		++i;
	}
	
	if (currentLenght > maxLenght) {
		maxLenght = currentLenght;
	}

	return maxLenght;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int nHeights, height;
	std::vector<int> heights;

	std::cin >> nHeights;
	for (int i = 0; i < nHeights; ++i) {
		std::cin >> height;
		heights.push_back(height);
	}

	int longestTrack = resolver(heights);
	
	std::cout << longestTrack << '\n';


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