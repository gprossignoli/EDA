// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
bool checkV(std::vector<int> const& v,const int n,const int d) {
	int i = 1;
	bool ok = true; //v is ok if forall int i :: 0 <= i < v.size() then v[i] <= v[i + 1] && (v[i + 1] - v[i]) <= 1 && !exists int k :: (v[i] == k) > d
	int countK = 1;
	//invariante: 1 <= i < n && countK >= 1 
	while (i < n && ok) {

		if (v[i] < v[i - 1] || (v[i] - v[i - 1]) > 1 )
			ok = false;

		if (v[i] == v[i - 1])
			++countK;
		else
			countK = 1;

		if (countK > d)
			ok = false;
		++i;
	}
	//invariant: 1 < i <= n && countK <= d 
	return ok;
}


void resuelveCaso() {
	int d, n; //d > 0, and n >= 0 
	std::vector<int> v;

	std::cin >> d >> n;

	if (d > 0 && n > 0) {

		for (int i = 0; i < n; ++i) {
			int elem;
			std::cin >> elem;
			v.push_back(elem);
		}

		if (checkV(v, n,d))
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