// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int mergeSort(std::vector<int> & v, int ini, int end) {
	int moves = 0;
	
	if (v[ini] != ini - 1) {
		std::swap(v[ini], v[v[ini] - 1]);
		++moves;
		return moves;
	}

	else {
		int half = (ini + end + 1) / 2;
		
		int left = resolver(v, ini, half);
		int right = resolver(v, half-1, end);
	
		return moves + left + right;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nSpaceships, spaceship;
	std::vector<int> battleFormation;
	
	std::cin >> nSpaceships;
	if (!std::cin)
		return false;
	
	for(int i = 0; i < nSpaceships; ++i) {
		std::cin >> spaceship;
		battleFormation.push_back(spaceship);
	}
	
	int necessaryMoves = mergeSort(battleFormation, 0, battleFormation.size()-1 );


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