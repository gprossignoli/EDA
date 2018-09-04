// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


void printSol(std::vector<int> const& v){
	int i = 0;
	for (i; i < v.size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << v[i] << '\n';
}
bool checkValidInsertion(std::vector<int>const&v, const int N, const int elem,std::vector<bool> marcas) {
	int i = 0;

	if (!marcas[elem])
		return true;

	if (elem >= (v.size() - 1)) {
		return false;
	}

	bool seguir = true;
	int j = v.size() - 1;
	while (i < elem && seguir) {
		if (v[j] == elem)
			seguir = false;
		--j;
		++i;
	}
	if (v[j] != elem)
		return false;

	return true;
}

void generateSolutions(std::vector<int> & v, const int N, int elem,int & nSol,std::vector<bool> & marcas) {
	if (v.size() == 2 * N) {
		printSol(v);
		++nSol;
	}
	else {
		if (elem <= N) {
			if (checkValidInsertion(v, N, elem, marcas)) {
				marcas[elem] = true;
				v.push_back(elem);
				generateSolutions(v, N, elem + 1, nSol, marcas);
				v.pop_back();
				marcas[elem] = false;
			}
			else
				generateSolutions(v, N, elem + 1, nSol, marcas);
		}
		else
			generateSolutions(v, N, elem - 1, nSol, marcas);
	}

}
void resolver(const int N) {
	std::vector<int> v;
	std::vector<bool> marcas;
	for (int i = 0; i < N + 1; ++i)
		marcas.push_back(false);
	int solutions = 0;

	generateSolutions(v, N, 1,solutions,marcas);
	std::cout << "Soluciones: " << solutions << '\n';
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int n;
	std::cin >> n;
	resolver(n);
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