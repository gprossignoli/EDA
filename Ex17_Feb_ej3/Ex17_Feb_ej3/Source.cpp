// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


void printSol(std::vector<int> const& v) {
	int i = 0;
	for (i; i < v.size() - 1; ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << v[i] << '\n';
}

void generateSolutions(int n, int d, int e, int currentSize,int countE, std::vector<int> sol) {
	if (currentSize == n) {
		printSol(sol);
	}

	else {
		if (countE < d) {
			sol.push_back(e);
			generateSolutions(n, d, e, currentSize + 1, countE + 1, sol);
			sol.pop_back();
		}

		if(((e + 1) - sol.back()) <= 1)
			generateSolutions(n, d, e + 1, currentSize, 0, sol);
		
	}
}

void escribeCrecientesPorLosPelosDivertidos(int n, int d, int e) {
	int currentSize = 1;
	int insertionPos = 0;
	int countE = 1;
	std::vector<int> sol;
	sol.push_back(e);
	generateSolutions(n, d, e, currentSize,countE, sol);
	std::cout << '\n';
}

void resuelveCaso() {
	int n, d, e; //n -> size of vector
				//d -> d-divertido condition
				//value of first element of solution
	std::cin >> n >> d >> e;

	escribeCrecientesPorLosPelosDivertidos(n,d,e);
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