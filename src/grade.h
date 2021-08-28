#ifndef GRADE_H
#define GRADE_H

#include <string>

using namespace std;

class Grade {
public:
	Grade(string stuid, double grade);
	string getStuId();
	double getGrade();
	
private:
	string _stuid;
	double _grade;
};

#endif
