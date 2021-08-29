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
	    Course* course = context.getCourse(tea_course_id_list[i]);
	    showInfo(course->getName());
		for(int j = 0; j < course->stu_id_list.size(); j++){
		    User* user = context.getUser(course->stu_id_list[j]);
		    showInfo(user->getName());
		}

	}

}


void Teacher::postGrades(){
    /*
	for(int i = 0;i < teacourselist.size();i++){
		cout << "登入第" << i + 1 << "门课的成绩：" << endl;

		for(int j = 0; j < teacourselist[i].stu_id_list.size(); j++){
			string stuid;
			double stugrade;

			cout << "请输入学生id：" << endl;
			cin >> stuid;
			cout << "请输入该学生成绩：" << endl;
			cin >> stugrade;
			Grade grade(stuid,stugrade);
		    teacourselist[i].grade_list.push_back(grade);
		}

		cout << "第" << i + 1 << "门课成绩录入成功！" << endl;
	}
     */
}

Teacher::Teacher(string name, string id, string password, int type) : \
User(name, id, password, type) {
}


#endif // CONFIG_TEACHER_FUNCTION



