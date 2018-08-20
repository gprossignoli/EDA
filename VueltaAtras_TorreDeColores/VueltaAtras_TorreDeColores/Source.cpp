// Gerardo Parra Rossignoli	
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

bool validSolution(std::string t) {
	int nR = 0, nB = 0, nG = 0;

	if (t[0] != 'r')
		return false;

	for (int i = 0; i < t.size(); ++i) {
		if (t[i] == 'r')
			++nR;
		else if (t[i] == 'b')
			++nB;
		else if (t[i] == 'g')
			++nG;
	}

	if (nR <= (nB + nG))
		return false;

	return true;
}

void printTower(std::string t) {
	int i = 0;
	for (i; i < t.size() - 1; ++i) {
		if (t[i] == 'r')
			std::cout << "rojo ";
		else if (t[i] == 'b')
			std::cout << "azul ";
		else if (t[i] == 'g')
			std::cout << "verde ";
	}

	if (t[i] == 'r')
		std::cout << "rojo\n";
	else if (t[i] == 'b')
		std::cout << "azul\n";
	else if (t[i] == 'g')
		std::cout << "verde\n";
	
}

void buildTower(std::string t, const int hT, int b, int r, int g, int cH,bool & noPrint) {
	
	if (cH == hT) {
		if (validSolution(t)) {
			printTower(t);
			noPrint = false;
		}
	}

	else {
		if (b > 0) {
			buildTower(t + "b", hT, b - 1, r, g, cH + 1,noPrint);
		}
		if (r > 0) {
			buildTower(t + "r", hT, b, r - 1, g, cH + 1,noPrint);
		}
		if (g > 0 && g > b) {
			if (t.back() != 'g')
				buildTower(t + "g", hT, b, r, g-1, cH + 1,noPrint);
		}
	}
}
// función que resuelve el problema
void resolver(std::string & t,const int hT,int b,int r, int g) {
	const int currentHeight = 0;
	bool noPrint = true;
	buildTower(t, hT, b, r, g, currentHeight,noPrint);
	if (noPrint)
		std::cout << "SIN SOLUCION\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int heighOfTower, blue, red, green;
	std::string tower;

	std::cin >> heighOfTower >> blue >> red >> green;
	if (heighOfTower == 0)
		return false;

	resolver(tower,heighOfTower,blue,red,green);

	std::cout << '\n';
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