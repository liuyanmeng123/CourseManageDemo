#ifndef TEACHER_H
#define TEACHER_H

#include "config.h"
#if CONFIG_TEACHER_FUNCTION

#include <string>

#include "user.h"

using namespace std;

class Teacher:public User {
public:
    Teacher(string basicString, string basicString1, string basicString2, int i);
    Teacher();
    void openCourse();		//开课
	void getStuList();		//获得学生名单 
	void postGrades();		//录入成绩
	vector<string> tea_course_id_list;      //老师开课列表
		
private:

	//string _college;
}; 

#endif // CONFIG_TEACHER_FUNCTION

#endif

