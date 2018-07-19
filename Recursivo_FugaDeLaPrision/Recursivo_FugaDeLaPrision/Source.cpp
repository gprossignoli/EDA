// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

struct tSolucion {
	int pos;
	bool prisionerFound;
};
// función que resuelve el problema
tSolucion resolver(std::vector<char> const& v,int ini,int end) {
	tSolucion sol;
	if (ini + 1 == end) {
		if (v[end] - v[ini] > 1)
			return { ini,true };
		else
			return { -1,false };
	}
	else {
		int half = (ini + end + 1) / 2;
		tSolucion left = resolver(v, ini, half);
		if (left.prisionerFound) 
			return left;
		tSolucion right = resolver(v, half, end);
		if (right.prisionerFound)
			return right;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	char ini, end;
	tSolucion sol = { -1,false };
	std::string prisioners;
	std::vector<char> v;

	std::cin >> ini >> end;
	std::cin.ignore(256, '\n');
	std::getline(std::cin, prisioners);
	
	for (int i = 0; i < prisioners.size(); ++i) {
		if (prisioners[i] != ' ')
			v.push_back(prisioners[i]);
	}


	if (ini != v[0]) {
		sol.prisionerFound = true;
		std::cout << ini << '\n';
	}

	if (end != v[v.size() - 1]) {
		sol.prisionerFound = true;
		std::cout << end << '\n';
	}
	
	if(!sol.prisionerFound) {
		sol = resolver(v, 0, v.size() - 1);
		char tmp = v[sol.pos];
		++tmp;
		std::cout << tmp << '\n';
	}	
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