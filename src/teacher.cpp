#include "config.h"
#if CONFIG_TEACHER_FUNCTION

#include <string>
#include <vector>
#include <iostream>


#include "teacher.h"
#include "course.h"
#include "global.h"
#include "utils.h"

using namespace std;

//开课
void Teacher::openCourse(){

    string coursename;
    string id;
    string coursetype;
    unsigned int credit;
    int time;
    string teachername;

    showInfo("请输入该课程id：");
    cin >> id;

    showInfo("请输入该课程类型：");
    cin >> coursetype;

    showInfo("请输入该课程学分：");
    cin >> credit;

    showInfo("请输入该课程课时：");
    cin >> time;

    showInfo("请输入您的姓名：");
    cin >> teachername;

    showInfo("请输入想要开设的课程名称：");
    cin >> coursename;

    Course*course_p = nullptr;

    course_p = new Course(coursename,coursetype,id,credit,time,teachername);

    Context& context = Context::get_instance();

    if(course_p) {
        context.addCourse(course_p);
        tea_course_id_list.push_back(id);

        showInfo("开课成功！");
    } else {
        showInfo("开课失败！");
    }

}


void Teacher::getStuList(){
    Context& context = Context::get_instance();

	for(int i = 0; i < tea_course_id_list.size(); i++){
	    Course* course_ptr = context.getCourse(tea_course_id_list[i]);
	    showInfo(course_ptr->getName());
		for(int j = 0; j < course_ptr->stu_id_list.size(); j++){
		    User* user = context.getUser(course_ptr->stu_id_list[j]);
		    showInfo(user->getName());
		}

	}

}


void Teacher::postGrades(){

	for(int i = 0; i < tea_course_id_list.size(); i++){
	    Context& context = Context::get_instance();
        Course*course_ptr = context.getCourse(tea_course_id_list[i]);

        cout << "请登入" << course_ptr->getName() << "课的成绩：" << endl;
		for(int j = 0; j < course_ptr->stu_id_list.size(); j++){
			string stuid;
			double stugrade;

			showInfo("请输入学生id：" );
			cin >> stuid;
			showInfo("请输入该学生成绩：");
			cin >> stugrade;

			Grade*grade_ptr = nullptr;
			grade_ptr = new Grade(stuid, stugrade);

			if(grade_ptr) {
			   course_ptr->grade_list.push_back(grade_ptr);
			   showInfo("登入成功！");
			} else {
			    showInfo("登入失败！");
			}
		}
	}
}

Teacher::Teacher(string name, string id, string password, int type) : \
User(name, id, password, type) {
}

Teacher::Teacher(){};

#endif // CONFIG_TEACHER_FUNCTION



