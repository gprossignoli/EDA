// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

/* predicate: totalProfit (b[],x) {
*  forall i: 0 <= i < length(b) : x = (elemMenor: forall j: 0 <= j <= i : b[j] < b[i] ) + ( elemMayor : forall k: i <= k < length(b) : b[i] < b[k] )
*	}	
*/

/* precondicion: { 0 <= n && 0 <= m && length(a) = n && length(b) = m && a.size() > 0 && b.size() > 0 &&
* forall i: 0 < i < length(a) : a[i - 1] <= a[i] && forall k: 0 < i < length(b) : b[k - 1] <= b[k] }
*/

/* postcondicion: { totalProfit = forall i: 0 <= i < n : totalProfit = totalProfit + profit(i) && indexA = forall k : 0 <= k <= length(a) && 
* firstBiggerElem = exists j: indexA <= j < length(a) : a[indexA] < b[j] && firstSmallerElem = exists t : 0 <= t <= indexA : b[t] < a[indexA] }
*/
int resolver(std::vector<int> const& a,std::vector<int> const& b, const int n, const int m) {
	int firstBiggerElem = 0;
	int firstSmallerElem = 0;
	int indexA = 0;
	int totalProfit = 0;

	while (indexA < n) {
		if (indexA > 0 && firstSmallerElem >= 0 && firstBiggerElem < m) {
			if (a[indexA] <= b[firstSmallerElem] || a[indexA] >= b[firstBiggerElem]) {
				if (a[indexA] <= b[firstSmallerElem]) {
					--firstSmallerElem;
				}

				if (a[indexA] >= b[firstBiggerElem]) {
					++firstBiggerElem;
				}
			}

			else {
				int nElemsSmaller = firstSmallerElem + 1;
				int nElemsBigger = (m - 1) - firstBiggerElem + 1;
				totalProfit += nElemsSmaller * nElemsBigger;

				firstSmallerElem = indexA;
				firstBiggerElem = indexA;
				++indexA;
			}
		}
		else {
			++indexA;
			firstSmallerElem = indexA;
			firstBiggerElem = indexA;
		}
	}
	return totalProfit;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int n, m; // 0 <= n && 0 <= m 
	std::vector<int> a, b; //a[n] b[m]

	std::cin >> n >> m;

	if (n >= 0 && m >= 0) {
		for (int i = 0; i < n; ++i) {
			int elem;
			std::cin >> elem;
			a.push_back(elem);
		}
		for (int i = 0; i < m; ++i) {
			int elem;
			std::cin >> elem;
			b.push_back(elem);
		}
		int sol = resolver(a,b,n,m);
		std::cout << sol;
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