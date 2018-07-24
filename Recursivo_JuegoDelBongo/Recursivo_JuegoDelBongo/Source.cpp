// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


struct tSolution {
	bool found;
	int num;
};
// función que resuelve el problema
tSolution resolver(std::vector<int> const& v,int ini,int end,int const& wanted) {
	tSolution sol;
	sol.found = wanted + ini == v[ini];
	if (ini + 1 == end) {

		if (sol.found) {
			sol.num = v[ini];
		}
		else
			sol.num = -1;

		return sol;
	}
	else {
		int half = (ini + end + 1) / 2;

		tSolution left = resolver(v,ini,half,wanted);
		if (left.found)
			return sol = left;

		tSolution right = resolver(v, half, end,wanted);
		if (right.found)
			return sol = right;
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada

	int nElems, elem, wanted;
	std::vector<int> v;
	std::cin >> nElems >> wanted;
	for (int i = 0; i < nElems; ++i) {
		std::cin >> elem;
		v.push_back(elem);
	}
	tSolution sol = resolver(v,0,v.size()-1,wanted);
	if (sol.found)
		std::cout << sol.num << '\n';
	else
		std::cout << "NO\n";
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