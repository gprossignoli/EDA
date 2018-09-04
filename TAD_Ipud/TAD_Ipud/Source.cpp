// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdexcept>
#include <list>
#include "Ipud.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	std::string op;
	std::string cancion, artista;
	int duracion;
	ipud reproductor;

	std::cin >> op;
	if (!std::cin)
		return false;
	while (op != "FIN") {
		if (op == "addSong") {
			std::cin >> cancion >> artista >> duracion;
			try { reproductor.addSong(cancion, artista, duracion); }
			catch (std::domain_error e) { std::cout << e.what() << '\n'; }
		}
		else if (op == "addToPlaylist") {
			std::cin >> cancion;
			try { reproductor.addToPlaylist(cancion); }
			catch (std::domain_error e) { std::cout << e.what() << '\n'; }
		}
		else if (op == "play") {
			try {
				std::string song = reproductor.play();
				std::cout << "Sonando " << song << '\n';
			}
			catch (std::domain_error e) { std::cout << "No hay canciones en la lista \n"; }
		}
		else if (op == "current") {
			try { reproductor.current(); }
			catch (std::domain_error e) { std::cout << e.what() << '\n'; }
		}
		else if (op == "totalTime") {
			try { 
				int out = reproductor.totalTime(); 
				std::cout << "Tiempo total " << std::to_string(out) << '\n';
				}
			catch (std::domain_error e) { std::cout << e.what() << '\n'; }
		}
		else if (op == "recent") {
			int n; 
			std::cin >> n;
			try {
				std::list<std::string> out = reproductor.recent(n);
				std::cout << "Las " << out.size() << " mas recientes \n";
				for (std::string s : out) {
					std::cout << '\t' << s << '\n';
				}
			}
			catch (std::domain_error e) { std::cout << e.what() << '\n'; }
		}
		else if (op == "deleteSong") {
			std::cin >> cancion;
			reproductor.deleteSong(cancion); 
		}
		std::cin >> op;
	}
	std::cout << "---- \n";
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