//
// Created by 86189 on 2021/8/22.
//

#ifndef COURSEMANAGE_GLOBAL_H
#define COURSEMANAGE_GLOBAL_H

#include "course.h"
#include "user.h"
//using namespace std;

#define  GET_CONTEXT Context& context = Context::get_instance()

class Context {
public:
    ~Context() = default;

    Context(const Context &) = delete;

    Context &operator=(const Context &) = delete;

    static Context &get_instance() {
        static Context instance;
        return instance;

    }

    int findCourse(string name);

    bool changeCourse(int index, Course* course);

    string getCourseID(string name);

    Course getCourse(string id, string name = "");

    int findUser(string id, string name = "");

    int findCourse(string id, string name);

    void addCourse(Course* course);

    bool changeUser(string id, string major);

    int verifyUser(string id, string password);

    bool addUser(User* user);

private:
    Context() = default;

    vector<Course *> course_list;
    vector<User *> user_list;
    int current_usr_id;
};

/*
class Context {
public:
    static Context& getInstance()                  //Instance()作为静态成员函数提供里全局访问点
    {
        static Context instance;
        return instance;
    }

    int findCourse(string name);
    bool changeCourse(int index, Course course);

private:
    Context();                                  //这里将构造，析构，拷贝构造，赋值函数设为私有，杜绝了生成新例
    ~Context();
    Context(const Context&);
    Context& operator=(const Context&);

    vector<Course> course_list;
    vector<User> user_list;

};
*/

#endif //COURSEMANAGE_GLOBAL_H
