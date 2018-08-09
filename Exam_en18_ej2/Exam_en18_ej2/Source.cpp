// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdlib.h>

struct tSolucion {
	int distance;
	int value;
};

// función que resuelve el problema
tSolucion resolver(std::vector<int> const& v, int const& x,int ini, int end) {

	if (ini + 1 == end) {
		if (abs(x - v[ini]) < (abs(x - v[end]))) {
			return { abs(x - v[ini]), v[ini] };
		}

		if (abs(x - v[ini]) > (abs(x - v[end]))) {
			return { abs(x - v[end]), v[end] };
		}

		if (abs(x - v[ini]) == (abs(x - v[end]))) {
			if (v[ini] < v[end])
				return { abs(x - v[ini]), v[ini] };
			else
				return { abs(x - v[end]), v[end] };
		}
	}

	else {
		int half = (ini + end + 1) / 2;
		tSolucion left = resolver(v, x, ini, half);
		tSolucion right = resolver(v, x, half, end);

		if (left.distance < right.distance)
			return left;
		if (right.distance < left.distance)
			return right;
		if (left.distance == right.distance) {
			if (left.value < right.value)
				return left;
			else
				return right;
		}
	}

	

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int x, nNumbers,number;
	std::vector<int> v;

	std::cin >> x >> nNumbers;
	for (int i = 0; i < nNumbers; ++i) {
		std::cin >> number;
		v.push_back(number);
	}

	tSolucion closestNumToX = resolver(v,x,0,v.size()-1);
	
	std::cout << closestNumToX.value << '\n';


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