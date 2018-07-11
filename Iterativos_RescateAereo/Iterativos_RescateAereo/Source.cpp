// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
void resolver(std::vector<int> const& map,int const& h) {
	int largestSegmentSize = 0;
	int currentSegmentSize = 0;
	int largestSegmentIni = -1;
	int currentSegmentIni = -1;
	for (int i = 0; i < map.size(); ++i) {
		if (map[i] > h) {
			if(currentSegmentSize == 0) //new segment
				currentSegmentIni = i;
			++currentSegmentSize;
		}
		else {
			if (currentSegmentSize > largestSegmentSize) { //end of current segment
				largestSegmentIni = currentSegmentIni;
				largestSegmentSize = currentSegmentSize;
			}
			currentSegmentIni = -1;
			currentSegmentSize = 0;
		}
	}
	if (currentSegmentSize > largestSegmentSize) { //end of current segment
		largestSegmentIni = currentSegmentIni;
		largestSegmentSize = currentSegmentSize;
	}
	std::cout << largestSegmentIni << " " << largestSegmentIni + largestSegmentSize - 1 << '\n';
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	int nSkyscrapers;
	int transportHeight;
	std::vector<int> map;
	std::cin >> nSkyscrapers;
	std::cin >> transportHeight;
	int skyscraperHeight;
	for (int i = 0; i < nSkyscrapers; ++i) {
		std::cin >> skyscraperHeight;
		map.push_back(skyscraperHeight);
	}
	resolver(map,transportHeight);
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