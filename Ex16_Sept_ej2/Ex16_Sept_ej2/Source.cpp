// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <math.h>



bool loadBag(const int b1,const int b2,int & wOfB1,int &  wOfB2,const int obj) {
	if (wOfB1 + obj > b1 && wOfB2 + obj > b2)
		return false;

	else if (wOfB1 + obj <= b1) {
		wOfB1 += obj;
	}

	else if (wOfB2 + obj <= b2) {
		wOfB2 += obj;
	}

	return true;
}

void generateSolutions(const int bag1, const int bag2, const int N, 
					   std::vector<bool> & marks, std::vector<int> const& v,
					   std::vector<int> const& w, int obj,int & sol,
					   int currentSol,int wOfB1,int wOfB2) {

	if (obj == N) {
		const int totalWeight = wOfB1 + wOfB2;
		const float fivePercentOfTotal = totalWeight * 0.05;
		if (abs(wOfB1 - wOfB2) > fivePercentOfTotal)
			sol = currentSol;
	}

	else {
		if (marks[obj] == false && loadBag(bag1, bag2, wOfB1, wOfB2, w[obj])) {
				marks[obj] = true;
				generateSolutions(bag1, bag2, N, marks, v, w, obj + 1, sol, currentSol + v[obj], wOfB1, wOfB2);
				marks[obj] = false;
		}
		else
			generateSolutions(bag1, bag2, N, marks, v, w, obj + 1, sol, currentSol, wOfB1, wOfB2);
	}

}


void loadTheCamel(const int bag1,const int bag2,const int N,
				 std::vector<bool> & marks, std::vector<int> const& v, 
				 std::vector<int> const& w) {
	int object = 0;
	int sol = 0;
	generateSolutions(bag1, bag2, N, marks, v, w, object,sol,0,0,0);
	std::cout << sol << '\n';
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int bag1, bag2,n;
	std::vector<int> values;
	std::vector<int> weights;
	std::vector<bool> marks;

	std::cin >> bag1 >> bag2 >> n;
	for (int i = 0; i < n; ++i) {
		int value, weight;
		std::cin >> value >> weight;
		values.push_back(value);
		weights.push_back(weight);
		marks.push_back(false);
	}

	loadTheCamel(bag1,bag2,n,marks,values,weights);
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