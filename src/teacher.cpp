#include "config.h"
#if CONFIG_TEACHER_FUNCTION

#include <string>
#include <vector>
#include <iostream>


#include "teacher.h"
#include "course.h"
#include "global.h"

using namespace std;

//开课
void Teacher::openCourse(){
    /*
    string coursename;

    cout << "请输入想要开设的课程名称：" << endl;
    cin >> coursename;

    Context& context = Context::get_instance();
    context.addCourse(coursename);
    tea_course_id_list.push_back(id);

     */

}


void Teacher::getStuList(){
    /*
	for(int i = 0; i < teacourselist.size(); i++){
		for(int j = 0; j < teacourselist[i].stu_id_list.size(); j++){
		    cout << teacourselist[i].stu_id_list[j] << "  ";
		}

		cout << endl;
	}
     */
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



