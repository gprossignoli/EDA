// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int lookForLostPartnerPos(std::vector<int> const& v, int ini , int end) {
	
	if (ini == end)
		return -1;

	else if (v[ini] != v[ini - 1] && v[ini] != v[ini + 1])
		return ini;

	else if (v[end] != v[end - 1] && v[end] != v[end + 1])
		return end;

	else {
		int mid = (ini + end) / 2;
		int solL = lookForLostPartnerPos(v, ini, mid);
		if (solL != -1) {
			return solL;
		}
		int solR = lookForLostPartnerPos(v, mid + 1, end);
		
		return solR;
	}
	
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int tamV,elem;
	std::vector<int> v;

	std::cin >> tamV;
	for (int i = 0; i < tamV; ++i) {
		std::cin >> elem;
		v.push_back(elem);
	}
	int sol = 0;

	if (tamV > 1) {
		if (v[tamV - 2] != v[tamV - 1])
			sol = tamV - 1;
		else if (v[0] != v[1])
			sol = 0;
		else
			sol = lookForLostPartnerPos(v, 1, v.size() - 1);
	}
		
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