#include <string>

#include "grade.h"


double Grade::getGrade() {
	return _grade;
}

string Grade::getStuId() {
	return _stuid;
}

Grade::Grade(string stuid, double grade) {
	_stuid = stuid;
	_grade = grade;
}


