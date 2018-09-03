// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// precondicion : { 0 <= sizeV && length(v) = sizeV } 

/* postcondicion: { ( posFirstPositive = exists i : 0 <= i < length(v) && posFirstNegative = exists j : 0 <= posFirstNegative < length(v) ) : 
*  0 <= posFirstPositive <= posFirstNegative && v = forall k,t: 0 <= k < posFirstNegative <= t < length(v) : v[k] >= 0 && v[t] < 0 }
*/
int resolver(std::vector<int> & v,const int sizeV) {
	int posFirstPositive = sizeV - 1;
	int posFirstNegative = 0;

	/* invariante = { ( posFirstPositive = exists i : 0 <= i < length(v) && posFirstNegative = exists j : 0 <= posFirstNegative < length(v) ) : 
	*  0 <= posFirstPositive <= posFirstNegative }
	*/
	while (posFirstNegative <= posFirstPositive) {
		if (v[posFirstPositive] < 0 || v[posFirstNegative] >= 0) {
			if (v[posFirstPositive] < 0) {
				--posFirstPositive;
			}
			if (v[posFirstNegative] >= 0) {
				++posFirstNegative;
			}
		}

		else {
			std::swap(v[posFirstNegative], v[posFirstPositive]);
		}
	}
	/* invariante = { ( posFirstPositive = exists i : 0 <= i < length(v) && posFirstNegative = exists j : 0 <= posFirstNegative < length(v) ) :
	*  0 <= posFirstPositive <= posFirstNegative && v = forall k,t: 0 <= k < posFirstNegative <= t < length(v) : v[k] >= 0 && v[t] < 0  }
	*/
	return posFirstNegative;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int sizeV;
	std::vector<int> v;

	std::cin >> sizeV;

	if (sizeV >= 0) {
		for (int i = 0; i < sizeV; ++i) {
			int elem;
			std::cin >> elem;
			v.push_back(elem);
		}

		int posFirstNegative = resolver(v,sizeV);

		int i = 0;
		for (i; i < sizeV - 1; ++i) {
			std::cout << v[i] << " ";
		}
		std::cout << v[i] << '\n' << posFirstNegative;
	}
	std::cout << '\n';
	
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