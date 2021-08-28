#ifndef STUDENT_H
#define STUDENT_H

#include "config.h"
#if CONFIG_STUDENT_FUNCTION

#include <vector>
#include <string>

#include "course.h"
#include "user.h"

using namespace std;


//int location = 0;
class Student:public User {
public:
	Student();
	void selectCourse();		//选课 
	void dropCourse();			//退课 
	void getCourseInfo();		//获得课程信息 
	//void setMajor(string major);			//设置专业
	
	vector<string> course_id_list;	//学生课表
		
private:
	//string _major;
	
}; 
#endif //CONFIG_STUDENT_FUNCTION

#endif
