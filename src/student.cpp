
#include "config.h"
#if CONFIG_STUDENT_FUNCTION

#include <string>
#include <iostream>
#include <algorithm>

#include "student.h"
#include "global.h"
#include "utils.h"

void Student::selectCourse(){		
	string coursename;

	showInfo("请输入想要选择的课程名称：");
	cin >> coursename;

	Context& context = Context::get_instance();
	string course_id = context.getCourseID(coursename);

	if (!course_id.empty()) {
	    Course* course_p = context.getCourse(course_id,coursename);
	    course_id_list.push_back(course_id);
	    course_p->stu_id_list.push_back(this->getId());

	    showInfo("选课成功！");
	} else {
	    showInfo("该课程未开设！");
	}
} 

void Student::dropCourse(){
	string coursename;
	int i;
	showInfo("请输入想要退选的课程名称：");
	cin >> coursename;

	Context& context = Context::get_instance();
	string course_id = context.getCourseID(coursename);

	if (!course_id.empty()) {
	    for(i = 0;i < course_id_list.size(); i++ ){
	        if(course_id_list[i] == course_id){
	            Course* course_p = context.getCourse(course_id,coursename);

	            course_id_list.erase(course_id_list.begin() + i);
	            course_p->stu_id_list.erase(remove(course_p->stu_id_list.begin(),course_p->stu_id_list.end(),this->getId()),course_p->stu_id_list.end());

	            showInfo("退课成功！");
	            break;
	        }
	    }
	} else {
	    showInfo("该课程未开设！");
	}
} 

void Student::getCourseInfo(){
    string coursename;
    int i;
    showInfo("请输入想要查询的课程名称：");
    cin >> coursename;

    Context& context = Context::get_instance();
    string course_id = context.getCourseID(coursename);
    if (!course_id.empty()) {
        for(i = 0;i < course_id_list.size(); i++ ){
            if(course_id_list[i] == course_id){
                Course* course_ptr = context.getCourse(course_id,coursename);
                cout << "课程名称：" << course_ptr->getName() << endl;
                cout << "课程类型：" << course_ptr->getCourseType() << endl;
                cout << "课程学分：" << course_ptr->getCredit() << endl;
                cout << "课程时长：" << course_ptr->getTime() << endl;
                cout << "课程教师：" << course_ptr->getTeacherName() << endl;
                }
                break;
        }
    }
}

Student::Student() {

}
#endif //CONFIG_STUDENT_FUNCTION







