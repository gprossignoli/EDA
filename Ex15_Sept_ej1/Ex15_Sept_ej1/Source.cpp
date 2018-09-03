// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>

/*predicate Jacobstal(0) = 0
*			Jacobstal(1) = 1
*			Jacobstal(N) = J(N - 1) + 2 * J(N - 2) 
*/

// precondicion: { 0 <= N }

/*poscondicion: { ( J = forall k:: 1 < k <= N : k = Jacobstal(k) && 
*	J1 = forall t:: 1 <= t < J: Jacobstal(t) && J2 = forall c:: 0 <= c < J1: Jacobstal(c) ) : Jacobstal(J) = Jacobstal(J1) + 2 * Jacobstal(J2) }
*/

int resolver(const int N) { //return int J; coste = O(N) sobre el tamaño de N,en el peor caso, pues el bucle hara N iteraciones de coste constante
	if (N == 0)
		return 0;
	else if (N == 1)
		return 1;

	else {
		int J2 = 0;
		int J1 = 1;
		int J;
		int i = 2;

		//invariante:{ 2 <= i <= N + 1 && ( J = forall k:: 1 < k <= i : k = Jacobstal(k) && 
		//	J1 = forall t:: 1 <= t < i: Jacobstal(t) 
		//  && J2 = forall c:: 0 <= c < i - 1: Jacobstal(c) ) : Jacobstal(J) = Jacobstal(J1) + 2 * Jacobstal(J2) }
		while (i < N + 1) {
			J = J1 + 2 * J2;
			J2 = J1;
			J1 = J;
			++i;
		}
		//invariante:{ N < i <= N + 1 && ( J = forall k:: 1 < k < i : k = Jacobstal(k) && 
		//	J1 = forall t:: 1 <= t < i - 1: Jacobstal(t) 
		//  && J2 = forall c:: 0 <= c < i - 2: Jacobstal(c) ) : Jacobstal(J) = Jacobstal(J1) + 2 * Jacobstal(J2) }
		
		return J;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	int n;

	std::cin >> n;
	if (n >= 0) {
		int sol = resolver(n);
		std::cout << sol << '\n';
	}
	else
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