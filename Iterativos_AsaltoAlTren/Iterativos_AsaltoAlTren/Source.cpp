// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
void resolver(std::vector<int> const& t,int const& n) { 
	int partialLoot = 0;
	int i = 0;
	while (i < n) {
		partialLoot += t[i];
		++i;
	}
	int bestLoot = partialLoot;
	int iniPos = 0;
	int j = 0;
	while (j < t.size() - n) { 
		partialLoot += t[j + n]; //se hace avanzar la ventana, añadiendo uno por detras y quitando el primero
 		partialLoot -= t[j];
		if (partialLoot >= bestLoot) {
			bestLoot = partialLoot;
			iniPos = j + 1;
		}
		++j;
	}

	std::cout << iniPos << " " << bestLoot << '\n';
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int trainSize;
	int nWagons;
	int wagon;
	std::vector<int> train;
	std::cin >> trainSize;
	std::cin >> nWagons;
	for (int i = 0; i < trainSize; ++i) {
		std::cin >> wagon;
		train.push_back(wagon);
	}
	resolver(train, nWagons);
	// escribir sol


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