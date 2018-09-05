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
	std::map<char,char> erased;
	std::map<char,char> added;
	std::map<char,char> modified;

	auto iteratorToOldD = oldD.begin();

	while(iteratorToOldD != oldD.end()) {
		auto iteratorToNewD = newD.find(iteratorToOldD->first);

		if (iteratorToNewD == newD.end()) {
			erased.insert({ iteratorToOldD->first,iteratorToOldD->second });
		}

		else if (iteratorToNewD->second != iteratorToOldD->second) {
			modified.insert({ iteratorToOldD->first,iteratorToOldD->second });
		}

		++iteratorToOldD;
	}

	auto iteratorToNewD = newD.begin();
	while(iteratorToNewD != newD.end()) {
		auto iteratorToOldD = oldD.find(iteratorToNewD->first);

		if (iteratorToOldD == oldD.end()) {
			added.insert({ iteratorToNewD->first,iteratorToNewD->second });
		}
		
		++iteratorToNewD;
	}
	
	if (added.empty() && erased.empty() && modified.empty()) {
		std::cout << "Sin cambios\n";
	}
	else {
		if (!added.empty()) {
			std::cout << "+ ";
			auto it = added.begin();
			while (it != added.end()) {
				std::cout << it->first;
				++it;
				if (it != added.end())
					std::cout << " ";
			}
			std::cout << '\n';
		}
		if(!erased.empty()){
			std::cout << "- ";
			auto it = erased.begin();
			while (it != erased.end()) {
				std::cout << it->first;
				++it;
				if (it != erased.end())
					std::cout << " ";
			}
			std::cout << '\n';
		}
		if (!modified.empty()) {
			std::cout << "* ";
			auto it = modified.begin();
			while (it != modified.end()) {
				std::cout << it->first;
				++it;
				if (it != modified.end())
					std::cout << " ";
			}
			std::cout << '\n';
		}
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