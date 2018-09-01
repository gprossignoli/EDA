// Gerardo Parra Rossignoli
// E45


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include "drivingSchool.h"

bool resuelveCaso() {

	DrivingSchool myAcademy;
	std::string op = "";

	std::cin >> op;
	if (!std::cin)
		return false;

	while (op != "FIN") {

		if (op == "alta") {
		std::string teacher, student;
		std::cin >> student >> teacher;
		myAcademy.alta(student, teacher);
		}

		else if (op == "es_alumno") {
			std::string teacher, student;
			std::cin >> student >> teacher;
			if (myAcademy.es_alumno(student, teacher))
				std::cout << student + " es alumno de " + teacher;
			else
				std::cout << student + " no es alumno de " + teacher;
			std::cout << '\n';
		}

		else if (op == "puntuacion") {
			std::string student;
			std::cin >> student;
			try {
				std::cout << "Puntuacion de " + student + ": " << myAcademy.puntuacion(student) << '\n';
			}

			catch (std::domain_error e) {
				std::cout << "ERROR\n";
			}
		}

		else if (op == "actualizar") {
			std::string student;
			int points;
			std::cin >> student >> points;

			try {
				myAcademy.actualizar(student, points);
			}

			catch (std::domain_error& e) {
				std::cout << "ERROR\n";
			}
		}

		else if (op == "examen") {
			std::string teacher;
			int points;
			std::cin >> teacher >> points;
			const std::vector<std::string> examList = myAcademy.examen(teacher, points);

			std::cout << "Alumnos de " + teacher + " a examen :\n";
			for (int i = 0; i < examList.size(); ++i) {
				std::cout << examList[i] + '\n';
			}
		}

		else if (op == "aprobar") {
			std::string student;
			std::cin >> student;

			try {
				myAcademy.aprobar(student);
			}
			catch (std::domain_error e) {
				std::cout << "ERROR\n";
			}
		}
		std::cin >> op;
	}
	std::cout << "------\n";
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