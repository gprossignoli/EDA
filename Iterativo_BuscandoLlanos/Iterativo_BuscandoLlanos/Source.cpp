// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
const std::vector<int> resolver(std::vector<int> const& v,const int sizeV,const int L,int & maxLength,int & nAvailablePlaces) {
	int i = sizeV - 1;
	int posIni = sizeV - 1;
	std::vector<int> placesToBuild;
	while (i > 0) {
		if (v[i - 1] != v[i]) {
			const int currentLength = (posIni - i) + 1;
			if (currentLength > maxLength)
				maxLength = currentLength;
			if (currentLength >= L && (posIni == sizeV-1 || v[posIni] >= v[posIni + 1]) ) {
				++nAvailablePlaces;
				placesToBuild.push_back(posIni);
			}
			posIni = i - 1;
		}

		--i;
	}


	if (v[i] == v[posIni]) {
		const int currentLength = (posIni - i) + 1;
		if (currentLength > maxLength)
			maxLength = currentLength;
		if (currentLength >= L && (posIni == sizeV - 1 || v[posIni] >= v[posIni + 1])) {
			++nAvailablePlaces;
			placesToBuild.push_back(posIni);
		}
	}

	return placesToBuild;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int sizeV, l;
	std::cin >> sizeV >> l;
	if (!std::cin)
		return false;

	std::vector<int> v;
	for (int i = 0; i < sizeV; ++i) {
		int elem;
		std::cin >> elem;
		v.push_back(elem);
	}

	int maxLength = 0;
	int nAvailablePlaces = 0;
	std::vector<int> sol = resolver(v,sizeV,l,maxLength,nAvailablePlaces);
	
	if (sol.size() > 0) {
		std::cout << maxLength << " " << nAvailablePlaces << " ";
		int i = 0;
		for (i; i < sol.size()-1; ++i) {
			std::cout << sol[i] << " ";
		}
		std::cout << sol[i] << '\n';
	}

	else {
		std::cout << "0" << " " << "0" << '\n';
	}



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