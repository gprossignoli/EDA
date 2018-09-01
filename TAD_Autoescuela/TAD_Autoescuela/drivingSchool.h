#ifndef drivingSchool_h
#define drivingSchool_h

#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <vector>
#include <stdexcept>

class DrivingSchool {
	typedef std::string teacher;
	typedef std::string student;
	typedef int points;

private:
	std::unordered_map < teacher, std::map<student, points>> teachers; 
	std::unordered_map<student, teacher> students;

public:
	DrivingSchool() {
		teachers.insert({ "PACO",{} });
		teachers.insert({ "RAMON",{} });
		teachers.insert({ "JUAN",{} });
		teachers.insert({ "ISABEL",{} });
	}

	void alta(const student s, const teacher t) {
		auto itToStudent = students.find(s);

		if (itToStudent == students.end()) { //new student
			students.insert({ s,t });

			auto itToTeacher = teachers.find(t);
			itToTeacher->second.insert({ s,0 });
		}

		else { //change of teacher
			auto itToOldTeacher = teachers.find(itToStudent->second);
			int points = itToOldTeacher->second.find(s)->second;
			itToOldTeacher->second.erase(s);

			auto itToNewTeacher = teachers.find(t);
			itToNewTeacher->second.insert({ s,points });

			itToStudent->second = t;
		}
	}

	const bool es_alumno(const student s, const teacher t) const{
		auto itToStudent = students.find(s);

		return itToStudent->second == t;
	}

	const int puntuacion(const student s) const{
		auto itToStudent = students.find(s);
		if (itToStudent == students.end())
			throw std::domain_error("El alumno A no esta matriculado");
		
		auto itToTeacher = teachers.find(itToStudent->second);
		return itToTeacher->second.find(s)->second;
	}

	void actualizar(const student s, const points p) {
		auto itToStudent = students.find(s);
		if (itToStudent == students.end()) 
			throw std::domain_error("El alumno A no esta matriculado");
	
		auto itToTeacher = teachers.find(itToStudent->second);
		auto itToPoints = itToTeacher->second.find(s);
		itToPoints->second += p;
		
	}

	const std::vector<student> examen(const teacher t, const points p) const{
		std::vector<student> examList;
		auto itToTeacher = teachers.find(t);
		auto itToStudents = itToTeacher->second.begin();

		while (itToStudents != itToTeacher->second.end()) {
			if (itToStudents->second >= p)
				examList.push_back(itToStudents->first);
			
			++itToStudents;
		}
		return examList;
	}

	void aprobar(const student s) {
		auto itToStudent = students.find(s);
		if (itToStudent == students.end())
			throw std::domain_error("El alumno A no esta matriculado");

		
		auto itToTeacher = teachers.find(itToStudent->second);
		itToTeacher->second.erase(s);

		students.erase(s);
		
	}
};
#endif
