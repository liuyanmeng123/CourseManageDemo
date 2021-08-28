
#include "config.h"
#if CONFIG_STUDENT_FUNCTION

#include <string>
#include <iostream>

#include "student.h"
#include "global.h"

void Student::selectCourse(){		
	string coursename;
	//string coursetype;
	//unsigned int credit;
	//int time;
	//string teachername;

	cout << "请输入想要选择的课程名称：" << endl;
	cin >> coursename;
	Context& context = Context::get_instance();
	string course_id = context.getCourseID(coursename);
	if (!course_id.empty()) {
	    course_id_list.push_back(course_id);
	    cout << "选课成功！" << endl;
	} else {
	    cout << "该课程未开设！" << endl;
	}
} 

void Student::dropCourse(){
	string coursename;
	int i;
	cout << "请输入想退选的课程id：" << endl;
	cin >> coursename;

	Context& context = Context::get_instance();
	string course_id = context.getCourseID(coursename);

	if (!course_id.empty()) {
	    for(i = 0;i < course_id_list.size(); i++ ){
	        if(course_id_list[i] == course_id){
	            course_id_list.erase(course_id_list.begin() + i);
	            cout << "退选成功！" << endl;
	            break;
	        }
	    }
	    cout << "退选成功！" << endl;
	} else {
	    cout << "该课程未开设！" << endl;
	}
} 

void Student::getCourseInfo(){
    string coursename;
    int i;
    cout << "请输入想要查询的课程名称：" << endl;
    cin >> coursename;

    Context& context = Context::get_instance();
    string course_id = context.getCourseID(coursename);
    if (!course_id.empty()) {
        for(i = 0;i < course_id_list.size(); i++ ){
            if(course_id_list[i] == course_id){
                Course _course = context.getCourse(course_id,coursename);
                cout << "课程名称：" << _course.getName() << endl;
                cout << "课程类型：" << _course.getCourseType() << endl;
                cout << "课程学分：" << _course.getCredit() << endl;
                cout << "课程时长：" << _course.getTime() << endl;
                cout << "课程教师：" << _course.getTeacherName() << endl;
                }
                break;
            }
        }

}

Student::Student() {

}
#endif //CONFIG_STUDENT_FUNCTION







