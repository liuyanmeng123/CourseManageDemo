#include <string>

#include "course.h"

//int Course::getStuNum(){
//	return stunum;
//}
Course::Course() {}

Course::Course(string coursename, string coursetype, string id, unsigned int credit, int time, string teachername){
	_coursename = coursename;
	_coursetype = coursetype;
	_id = id;
	_credit = credit;
	_time = time;
	_teachername = teachername;
} 

string Course::getName(){
	return _coursename;
}

string Course::getCourseType(){
	return _coursetype;
}

unsigned int Course::getCredit(){
	return _credit;
}

int Course::getTime(){
	return _time;
}

string Course::getTeacherName(){
	return _teachername;
}

string Course::getId(){
    return _courseid;
}
