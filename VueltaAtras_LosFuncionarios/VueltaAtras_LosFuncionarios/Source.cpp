// Gerardo Parra Rossignoli	
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

void generateSol(std::vector<std::vector<long int>> const& m, int f, std::vector<bool> marked,long int sum,long int & sol) {
	for (int k = 0;k < m[0].size(); ++k) {
		sum += m[f][k];
		
		if (!marked[k]) {
			if (f + 1 == marked.size()) {
				if (sum < sol) sol = sum;
			}

			else {
				marked[k] = true;
				generateSol(m, f + 1, marked, sum, sol);
				marked[k] = false;
			}
		}
		sum -= m[f][k];
	}
}

void distributeTasks(std::vector<std::vector<long int>> const& m) {
	long int sum = 0, sol = 0;
	const int functionary = 0;
	for (int d = 0; d < m.size(); ++d) { //initializing with the diagonal
		sol += m[d][d];
	}
	std::vector<bool> marked;
	for (int i = 0; i < m.size(); ++i) {
		marked.push_back(false);
	}
	generateSol(m, functionary, marked, sum, sol);

	std::cout << sol << '\n';
}

bool resuelveCaso() {
	// leer los datos de la entrada
	int N; //nFunctionaries and nTasks
	std::vector<std::vector<long int>> data;
	int timeToCompleteTask;

	std::cin >> N;
	if (N == 0)
		return false;

	for (int i = 0; i < N; ++i) {
		std::vector<long int> tmp;
		for (int j = 0; j < N; ++j) {
			std::cin >> timeToCompleteTask;
			tmp.push_back(timeToCompleteTask);
		}
		data.push_back(tmp);
	}

	distributeTasks(data);

	// escribir sol

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