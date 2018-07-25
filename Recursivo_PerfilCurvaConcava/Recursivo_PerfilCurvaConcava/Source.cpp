// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector<int> const& v,int ini,int end,int min) {

	if (ini + 1 == end) {
		if (v[ini] < min)
			min = v[ini];
		if (v[end] < min)
			min = v[end];
		return min;
	}
	
	else {
		int half = (ini + end + 1) / 2;
		int left = resolver(v, ini, half, min);
		int right = resolver(v, half, end, min);
		if (left < right)
			return min = left;
		else
			return min = right;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int nElem, elem,sol;
	std::vector<int> v;
	
	std::cin >> nElem;
	if (!std::cin)
		return false;

	for (int i = 0; i < nElem; ++i) {
		std::cin >> elem;
		v.push_back(elem);
	}
	
	sol = elem;

	if (v.size() > 1)
	 sol = resolver(v,0,v.size()-1,v[0]);
	std::cout << sol << '\n';
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