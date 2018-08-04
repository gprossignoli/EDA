// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

struct tPlayer {
	std::string name;
	int marbles;
};

// función que resuelve el problema
tPlayer resolver(std::vector<tPlayer> const& v, int ini, int end) {
	tPlayer winner;

	if (ini + 1 == end) {
		
		if (v[ini].marbles >= v[end].marbles) {
			winner = v[ini];
			winner.marbles += (v[end].marbles / 2);
			return winner;
		}

		winner = v[end];
		winner.marbles += (v[ini].marbles / 2);
		return winner;
	}

	else {
		int half = (ini + end + 1) / 2;
		tPlayer leftWinner = resolver(v, ini, half-1);
		tPlayer rightWinner = resolver(v, half, end);
		
		if (leftWinner.marbles >= rightWinner.marbles) {
			winner = leftWinner;
			winner.marbles += (rightWinner.marbles / 2);
			return winner;
		}

		winner = rightWinner;
		winner.marbles += (leftWinner.marbles / 2);
		return winner;
	}

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	int nPlayers;
	tPlayer newPlayer;
	std::vector<tPlayer> competition;

	std::cin >> nPlayers;
	if (!std::cin)
		return false;
	for (int i = 0; i < nPlayers; ++i) {
		std::cin >> newPlayer.name >> newPlayer.marbles;
		competition.push_back(newPlayer);
	}

	tPlayer winner = resolver(competition,0, competition.size()-1);

	std::cout << winner.name << " " << winner.marbles << '\n';
	
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