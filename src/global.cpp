//
// Created by 86189 on 2021/8/22.
//
#include <iostream>

#include "course.h"
#include "user.h"
#include "global.h"
#include "utils.h"


bool Context::changeCourse(int index, Course* course) {
    course_list[index] = course;
    return true;
}

int Context::findCourse(string name) {
    for (int i = 0; i < course_list.size(); i++) {
        if (course_list[i]->getName() == name) {
            return i;
        }
    }
    return -1;
}

bool Context::changeUser(string id, string major) {
    for (int i; i < user_list.size(); i++) {
        if (user_list[i]->getId() == id) {
            user_list[i]->setMajor(major);
            return true;
        }
    }
    return false;
}

int Context::findUser(string id, string name) {
    if (!id.empty()) {
        for (int i = 0; i < user_list.size(); i++) {
            if (user_list[i]->getId() == id) {
                return i;
            }
        }
    }

    if (!name.empty()) {
        for (int i = 0; i < user_list.size(); i++) {
            if (user_list[i]->getName() == name) {
                return i;
            }
        }
    }

    return -1;
}

int Context::findCourse(string id,string name) {
    if(!id.empty()){
        for(int i = 0;i < course_list.size();i++) {
            if(course_list[i]->getId() == id) {
                return i;
            }
        }
    }

    if(!name.empty()) {
        for (int i = 0;i < course_list.size();i++){
            if(course_list[i]->getName() == name) {
                return i;
            }
        }
    }

    return -1;
}

void Context::addCourse(string name) {
    /*
    string id;
    string coursetype;
    unsigned int credit;
    int time;
    string teachername;
    int i = findCourse(name);

    if(i >= 0) {
        showInfo("已开设该课程！");
    }
    else{
        cout << "请输入该课程id："  << endl;
        cin >> id;

        cout << "请输入该课程类型："  << endl;
        cin >> coursetype;

        cout << "请输入该课程学分：" << endl;
        cin >> credit;

        cout << "请输入该课程课时：" << endl;
        cin >> time;

        cout << "请输入您的姓名：" << endl;
        cin >> teachername;

        Course course(name,coursetype, id, credit,time,teachername);
        course_list.push_back(course);

        cout << "开课成功！" << endl;
    }
*/


}

bool Context::addUser(User* user) {
    user_list.push_back(user);
    return true;
}

string Context::getCourseID(string name) {
    int i = findCourse(name);
    if (i >= 0) {
        return course_list[i]->getId();
    }
    return "";
}

Course Context::getCourse(string id, string name) {
    if (!id.empty()) {
        for (int i = 0; i < course_list.size(); i++) {
            if (course_list[i]->getId() == id) {
                return *course_list[i];
            }
        }
    }

    if (!name.empty()) {
        for (int i = 0; i < course_list.size(); i++) {
            if (course_list[i]->getName() == name) {
                return *course_list[i];
            }
        }
    }
}

int Context::verifyUser(string id, string password) {
    for (int i = 0; i < user_list.size(); i++) {
        if (user_list[i]->getId() == id && user_list[i]->getPassword() == password) {
            return i;
        }
    }
    return -1;
}




