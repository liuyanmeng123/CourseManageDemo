#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>

#include "grade.h"

using namespace std;

class Course {
public:
    Course();
	Course(string coursename, string coursetype, string id, unsigned int credit, int time, string teachername);
	string getName();
	string getCourseType();
	unsigned int getCredit();
	int getTime();
	string getTeacherName();
	string getId();
	//int getStuNum();
		
	vector<string> stu_id_list;		//学生名单
	vector<Grade*> grade_list;		//成绩名单
	//int stunum;				    //学生数量 
		
private:
	string _coursename;
	string _coursetype;
	string _courseid;
    unsigned int _credit;
	int _time;
	string _teachername;
//	string _id;

    string _id;
};


#endif
