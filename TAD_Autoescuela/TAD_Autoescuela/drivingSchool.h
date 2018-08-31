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
	typedef std::pair < teacher, int> studentInfo;

	std::map<student, studentInfo> students;
	std::unordered_map<teacher, std::vector<student>> teachers;

public:
	DrivingSchool() {
		teachers.insert({ "PACO",{} });
		teachers.insert({ "JUAN",{} });
		teachers.insert({ "RAMON",{} });
		teachers.insert({ "ISABEL",{} });
	}

	void signUpStudent(const student s, const teacher t) {
		auto itToStudents = students.find(s);

		if (itToStudents == students.end()) { //new student
			students.insert({ s,{t,0} });
			auto itToTeachers = teachers.find(t);
			itToTeachers->second.push_back(s);
		}

		else { //change of teacher
			teacher oldTeacher = itToStudents->second.first;
			itToStudents->second.first = t;

			//erase the student from the old teacher
			auto itToOldTeacher = teachers.find(oldTeacher);
			auto aux = itToOldTeacher->second.begin();
			while (*aux != s) {
				++aux;
			}
			itToOldTeacher->second.erase(aux);

			//insert the student into the new teacher
			auto itToNewTeacher = teachers.find(t);
			itToNewTeacher->second.push_back(itToStudents->first);
		}
	}

	bool is_student(const student s, const teacher t) {
		auto itToStudents = students.find(s);
		return t == itToStudents->second.first;
	}

	int checkPoints(const student s) {
		auto itToStudents = students.find(s);

		if (itToStudents == students.end())
			throw new std::domain_error("El alumno A no esta matriculado");

		return itToStudents->second.second;
	}
	
	void updatePoints(const student s, const int n) {
		auto itToStudents = students.find(s);

		if (itToStudents == students.end())
			throw new std::domain_error("El alumno A no esta matriculado");

		itToStudents->second.second += n;
	}
};
#endif
