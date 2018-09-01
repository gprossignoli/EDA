// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/* Precondition: { (0 < n/2 <= m <= n: length(w) = m && length(v) = n)  && 
* forall i:: 0 < i < length(v): v[i - 1] < v[i] && forall k:: 0 < k < length(w): v[k-1] < v[k] &&
* max(w[]) <= max(v[]) }
*/

/* PostCondition: {  forall i:: 0 <= i < m: exists k:: 0 <= k < n: w[i] == v[k]   }
*/
const bool resolver(std::vector<int> const& v, std::vector<int> const& w,const int n,const int m) {
	int indexV = 1;
	int indexW = 1;

	if (w[m - 1] > v[n - 1] || w[0] < v[0])
		return false;

	//Invariant: { 1 <= indexW <= m <= indexV <= n && forall i:: 0 <= i <= indexW: exists k:: 0 <= k <= indexV: w[i] == v[k]}
	
	while (indexW < m && indexV < n) {
		if (w[indexW] != v[indexV])
			++indexV;
		else {
			++indexW;
			++indexV;
		}
	}
	/*Invariant : { 1 <= indexW <= m <= indexV <= n && ( forall i:: 0 <= i <= indexW: exists k:: 0 <= k < indexV: w[i] == v[k] ||
	* forall i:: 0 <= i < indexW: exists k:: 0 <= k <= indexV: w[i] == v[k] ) }
	*/
	if (indexW < m)
		return false;

	return true;
}


void resuelveCaso() {
	int n, m; // n/2 <= m <= n
	std::vector<int> v, w; //length(v) = n && length(w) = m
	std::cin >> m >> n;

	if (n / 2 <= m && m <= n) {
		for (int i = 0; i < m; ++i) {
			int elem;
			std::cin >> elem;
			w.push_back(elem);
		}

		for (int i = 0; i < n; ++i) {
			int elem;
			std::cin >> elem;
			v.push_back(elem);
		}

		if (resolver(v, w, n, m))
			std::cout << "YES";
		else
			std::cout << "NO";
	}

	else
		std::cout << "NO";
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