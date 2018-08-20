// Gerardo Parra Rossignoli	
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>


typedef struct {
	int r = 0;
	int b = 0;
	int g = 0;
}tCubes;


bool validSolution(std::string sol, tCubes const& c, tCubes usedCubes) {
	if (usedCubes.r <= (usedCubes.b + usedCubes.g))
		return false;
	
	return true;
}

void printTower(std::string tower) {
	int i = 0;
	for (i; i < tower.size() - 1; ++i) {
		if (tower[i] == 'r')
			std::cout << "rojo ";
		else if (tower[i] == 'b')
			std::cout << "azul ";
		else if (tower[i] == 'g')
			std::cout << "verde ";
	}

	if (tower[i] == 'r')
		std::cout << "rojo\n";
	else if (tower[i] == 'b')
		std::cout << "azul\n";
	else if (tower[i] == 'g')
		std::cout << "verde\n";
}

void generateSolutions(const int hT, tCubes const& c,tCubes usedCubes,std::string sol,int cH,bool & printed) {
	
	if (hT == cH) {
		if (validSolution(sol, c, usedCubes)) {
			printTower(sol);
			printed = true;
		}
	}

	else {
		if (usedCubes.b < c.b) {
			++usedCubes.b;
			generateSolutions(hT, c, usedCubes, sol + 'b', cH + 1,printed);
			--usedCubes.b;
		}
		if (usedCubes.r < c.r) {
			++usedCubes.r;
			generateSolutions(hT, c, usedCubes, sol + 'r', cH + 1,printed);
			--usedCubes.r;
		}
		if (usedCubes.g < c.g && sol.size()-1 != 'g' && usedCubes.g + 1 <= usedCubes.b) {
			++usedCubes.g;
			generateSolutions(hT, c, usedCubes, sol + 'g', cH + 1,printed);
			--usedCubes.g;
		}
	}
}


void buildTower(const int hT, tCubes const& c) {
	std::string tower;
	tCubes usedCubes;
	bool printed = false;
	int currentHeight = 1;
	tower.push_back('r');
	++usedCubes.r;
	generateSolutions(hT, c, usedCubes, tower, currentHeight,printed);
	if (!printed)
		std::cout << "SIN SOLUCION\n";
	std::cout << '\n';

}

bool resuelveCaso() {
	// leer los datos de la entrada
	int heightOfTower;
	tCubes cubes;
	
	std::cin >> heightOfTower;
	std::cin >> cubes.b >> cubes.r >> cubes.g;

	if (heightOfTower == 0 && cubes.b == 0 && cubes.r == 0 && cubes.g == 0)
		return false;

	if (heightOfTower < 2 || cubes.r == 0)
		std::cout << "SIN SOLUCION\n";
	
	else {
		buildTower(heightOfTower, cubes);
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