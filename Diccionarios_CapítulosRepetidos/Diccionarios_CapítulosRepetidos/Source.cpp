// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <unordered_map>

typedef int chapter;
typedef int pos;
// función que resuelve el problema
int resolver(std::vector<int> const& v) {
	std::unordered_map<chapter,pos> map; 
	int i = 0;
	int iniSeg = 0;
	int maxSeg = 0;
	
	while (i < v.size() && (v.size() - 1) - i >= maxSeg ) {
		auto it = map.find(v[i]);
		if (it == map.end())
			map.insert({ v[i],i });
		else {
			int tamCurrentSeg = (it->second - iniSeg) + (i - it->second);
			if (tamCurrentSeg > maxSeg) {
				maxSeg = tamCurrentSeg;
				iniSeg = i;
			}
			it->second = i;
		}
		++i;
	}
	return maxSeg;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int nElem;
	chapter c;
	std::vector<int> chapters;
	std::cin >> nElem;
	for (int i = 0; i < nElem; ++i) {
		std::cin >> c;
		chapters.push_back(c);
	}

	int sol = resolver(chapters);
	// escribir sol
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