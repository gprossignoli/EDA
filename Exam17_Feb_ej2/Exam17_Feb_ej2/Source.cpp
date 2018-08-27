// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//a vector is ok when for all int i :: 1 <= i < v.size() ==> (v[i] - v[i - 1]) <= 1 

bool isOK(std::vector<int> const& v,const int ini,const int end) { 
	if (ini == end)
		return true;
	
	else if (ini + 1 == end) {
		if ((v[end] - v[ini]) <= 1)
			return true;
		else
			return false;
	}
	
	else {
		int mid = (end + ini) / 2;
		
		if (isOK(v, ini, mid))
			return isOK(v, mid, end);
		else
			return false;
	}
	

	

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int n; //tamV >= 0
	std::vector<int> v; //v is growing, not necessarily strictly increasing

	std::cin >> n;
	if (n > 0) {
		for (int i = 0; i < n; ++i) {
			int elem;
			std::cin >> elem;
			v.push_back(elem);
		}

		if (isOK(v, 0, n - 1))
			std::cout << "SI\n";
		else
			std::cout << "NO\n";
	}
	else
		std::cout << "NO\n";



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