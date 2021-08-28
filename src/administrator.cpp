//
// Created by 86189 on 2021/8/24.
//

#include "config.h"
#if CONFIG_ADMIN_FUNCTION

#include <iostream>

#include "administrator.h"
#include "course.h"
#include "global.h"
#include "user.h"

void Administrator::changeCourseInfo(){
    //Course course;
    string coursename;
    string coursetype;
    string courseid;
    unsigned int credit;
    int time;
    string teachername;

    cout << "请输入想要修改的课程名称：" << endl;
    cin >> coursename;

    Context& context = Context::get_instance();
    int i = context.findCourse(coursename);
    if (i >= 0) {
        cout << "请输入修改后的课程类型：" << endl;
        cin >> coursetype;
        cout << "请输入修改后的课程id：" << endl;
        cin >> courseid;
        cout << "请输入修改后的课程学分：" << endl;
        cin >> credit;
        cout << "请输入修改后的课程时长：" << endl;
        cin >> time;
        cout << "请输入修改后的课程教师：" << endl;
        cin >> teachername;
        Course course(coursename,coursetype,courseid,credit,time,teachername);

        bool ret = context.changeCourse(i, course);
        if (ret)
            cout << "修改课程信息成功！" << endl;
    } else {
        cout << "该课程未开设！" << endl;
    }
}


void Administrator::changeStudentInfo(){
    int i;
    string id;
    string major;

    cout << "请输入想要修改的学生id：" << endl;
    cin >> id;

    cout << "请输入修改后的学生专业：" << endl;
    cin >> major;

    Context& context = Context::get_instance();
    bool  ret = context.changeUser(id, major);
    if (ret) {
        cout << "修改学生信息成功！" << endl;
    } else {
        cout << "无该学生信息!" << endl;
    }
}


void Administrator::changeTeacherInfo(){
    int i;
    string id;
    string college;

    cout << "请输入想要修改的教师id：" << endl;
    cin >> id;
/*
    for(i = 0;i < user_list.size();i++){
        if(user_list[i].getId() == id){
            cout << "请输入修改后的教师学院：" << endl;
            cin >> college;
            user_list[i].setCollege(college);
            cout << "修改教师信息成功！" << endl;
            break;
        }
    }

    if(i == user_list.size()){
        cout << "无该教师信息!" << endl;
    }
    */

    cout << "修改失败!" << endl;
}

#endif // CONFIG_ADMIN_FUNCTION


