// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

typedef struct {
	int sum;
	bool isDegraded;
}tSol;
tSol resolver(std::vector<int> const& v,int ini,int end) {
	tSol sol;

	if (ini + 1 == end) {
		sol.sum = v[ini] + v[end];
		if (v[ini] < v[end])
			sol.isDegraded = true;
		else
			sol.isDegraded = false;
	}

	else {
		int mid = (ini + end) / 2;

		tSol left = resolver(v, ini, mid);
		if (left.isDegraded) {
			tSol rigth = resolver(v, mid+1, end);
			if (rigth.isDegraded && left.sum < rigth.sum) {
				sol.sum = left.sum + rigth.sum;
				sol.isDegraded = true;
			}
			else {
				sol.sum = 0;
				sol.isDegraded = false;
			}
		}
		else {
			sol.sum = 0;
			sol.isDegraded = false;
		}
	}

	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int row, col;
	std::cin >> row >> col;
	if (!std::cin)
		return false;

	if (row > 0 && col > 1) {
		int r = 0;
		bool ok = true;
		while (r < row) {
			std::vector<int> v;
			for (int c = 0; c < col; ++c) {
				int elem;
				std::cin >> elem;
				v.push_back(elem);
			}
			if (!resolver(v, 0, v.size() - 1).isDegraded)
				ok = false;
			++r;
		}
		if (ok)
			std::cout << "SI\n";
		else
			std::cout << "NO\n";
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