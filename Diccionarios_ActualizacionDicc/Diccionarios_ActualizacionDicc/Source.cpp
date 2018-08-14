// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <vector>
// función que resuelve el problema
void resolver(std::map<char,char> const& oldD, std::map<char, char> const& newD) {
	std::vector<char> erased;
	std::vector<char> added;
	std::vector<char> modified;
	auto iteratorToOldD = oldD.begin();
	for (int i = 0; i < oldD.size(); ++i) {
		auto iteratorToNewD = newD.find(iteratorToOldD->first);

		if (iteratorToNewD == newD.end()) {
			erased.push_back(iteratorToOldD->first);
		}

		else if (iteratorToNewD->second != iteratorToOldD->second) {
			modified.push_back(iteratorToOldD->first);
		}

		++iteratorToOldD;
	}

	auto iteratorToNewD = newD.begin();
	for (int i = 0; i < newD.size(); ++i) {
		auto iteratorToOldD = oldD.find(iteratorToNewD->first);

		if (iteratorToOldD == oldD.end()) {
			added.push_back(iteratorToNewD->first);
		}
		
		++iteratorToNewD;
	}
	
	if (added.size() > 0) {
		std::cout << "+ ";
		for (int i = 0; i < added.size(); ++i) {
			std::cout << added[i] << " ";
		}
		std::cout << '\n';
	}
	if (erased.size() > 0) {
		std::cout << "- ";
		for (int i = 0; i < erased.size(); ++i) {
			std::cout << erased[i] << " ";
		}
		std::cout << '\n';
	}
	if (modified.size() > 0) {
		std::cout << "* ";
		for (int i = 0; i < modified.size(); ++i) {
			std::cout << modified[i] << " ";
		}
		std::cout << '\n';
	}
	if (!added.size() > 0 && !erased.size() > 0 && !modified.size() > 0) {
		std::cout << "Sin cambios\n";
	}
	std::cout << "----\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	std::string line;
	std::map<char, char> oldDict,newDict;

	std::getline(std::cin, line);
	if (line != "") {
		for (int i = 2; i < line.size(); i = i + 4) {
			oldDict.insert({ line[i - 2], line[i] });
		}

		std::getline(std::cin, line);
		for (int i = 2; i < line.size(); i = i + 4) {
			newDict.insert({ line[i - 2], line[i] });
		}
		resolver(oldDict,newDict);
	}
	
	else {
		std::cout << "+ ";
		std::getline(std::cin, line);
		int i = 0;
		while (i < line.size()) {
			std::cout << line[i] << " ";
			i = i + 4;
		}
		std::cout << "\n----\n";
	}
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
	std::cin.ignore(1000, '\n');
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}