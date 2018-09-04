// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
void resolver(std::vector<int> & v,const int sizeV) {
	int evenToRelocate = 1; 
	int oddToRelocate = 0;

	if (v.size() == 1) {
		v.resize(0);
	}

	else if (v.size() == 2 && v[0] == v[1])
		v.resize(0);


	else {
		while (evenToRelocate < sizeV && oddToRelocate < sizeV) {
			if (v[oddToRelocate] % 2 == 0 || v[evenToRelocate] % 2 != 0) {
				if (v[oddToRelocate] % 2 == 0)
					oddToRelocate += 2;
				if (v[evenToRelocate] % 2 != 0)
					evenToRelocate += 2;
			}
			else {
				std::swap(v[oddToRelocate], v[evenToRelocate]);
				oddToRelocate += 2;
				evenToRelocate += 2;
			}
		}
	
		if (oddToRelocate >= sizeV && evenToRelocate < sizeV) {
			while (evenToRelocate < sizeV && v[evenToRelocate] % 2 != 0) {
				evenToRelocate += 2;
			}
			v.resize(evenToRelocate);
		}

		else if (evenToRelocate >= sizeV && oddToRelocate < sizeV) {
			while (oddToRelocate < sizeV && v[oddToRelocate] % 2 == 0) {
				oddToRelocate += 2;
			}
			v.resize(oddToRelocate);
		}

		if (oddToRelocate >= sizeV && evenToRelocate >= sizeV && v.size() % 2 != 0)
			v.resize(v.size() - 1);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int sizeV;
	std::vector<int> v;

	std::cin >> sizeV;
	if (!std::cin)
		return false;

	for (int i = 0; i < sizeV; ++i) {
		int elem;
		std::cin >> elem;
		v.push_back(elem);
	}

	resolver(v, sizeV);
	if (v.size() > 0) {
		int i = 0;
		for (i; i < v.size() - 1; ++i) {
			std::cout << v[i] << " ";
		}
		std::cout << v[i];
	}
	std::cout << '\n';

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