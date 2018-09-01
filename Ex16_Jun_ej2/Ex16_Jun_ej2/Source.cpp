// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//coste = 2 * T(v.size()/2) + c 
const int resolver(std::vector<int> const& v, const int d, const int ini,const int end) {

	if (ini + 1 == end) {
		if (v[ini] + d != v[end])
			return v[ini] + d;
		else
			return -1;
	}

	else {
		const int mid = (ini + end) / 2;
		const int left = resolver(v, d, 0, mid);
		if (left != -1)
			return left;
		else
			return resolver(v, d, mid, end);
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int sizeV, d; //sizeV >= 2 && ai = a1 + (i − 1) ∗ d
	std::cin >> sizeV >> d;
	if (sizeV >= 2) {
		std::vector<int> v;
		for (int i = 0; i < sizeV; ++i) {
			int elem;
			std::cin >> elem;
			v.push_back(elem);
		}
		std::cout << resolver(v,d, 0, sizeV - 1) << '\n';
	}

	else
		std::cout << '\n';


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