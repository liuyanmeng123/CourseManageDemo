#include <iostream>
#include <vector>
#include <string>

#include "user.h"
#include "utils.h"
#include "global.h"
#include "student.h"
#include "teacher.h"
#include "debug.h"

#include "config.h"


using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


///////////////////////
// Macros

enum {
    MAIN_OP_SIGN_IN,
    MAIN_OP_LOG_IN,
    MAIN_OP_LOG_OUT,
};

enum {
    STUDENT_TYPE,
    TEACHER_TYPE,
    ADMINISTRATOR_TYPE,
};

enum {
    SELECT,
    DROP,
    SEARCH,
    CHANGE_STUDENT,
    EXIT_STUDENT,

};

enum {
    OPEN,
    GET,
    POST,
    CHANGE_TEACHER,
    EXIT_TEACHER,
};

enum {
    TEACHER,
    STUDENT,
    ADMINISTRATOR,
    CHANGE_ADMINISTRATOR,
    EXIT_ADMINISTRATOR,
};

enum {
    LOGIN_INPUT,
    SIGNIN_INPUT
};

typedef struct Info {
    string name;
    string password;
    string id;
    int type;
} Info_t;

///////////////////////


///////////////////////
// Globals

///////////////////////

///////////////////////
// Functions

Info_t inputUserInfo(int type) {
    Info_t info;
    if (type == SIGNIN_INPUT) {
        cout << "请输入用户姓名：" << endl;
        cin >> info.name;
        cout << "请输入用户类型：student(0)/teacher(1)/administrator(2)" << endl;
        cin >> info.type;
    }

    if (type == SIGNIN_INPUT || type == LOGIN_INPUT) {
        cout << "请输入用户id：" << endl;
        cin >> info.id;

        cout << "请输入用户密码：" << endl;
        cin >> info.password;
    }

    return info;
}

//注册 
void signIn() {
    showInfo("==== 注册 ====");
    Info_t info = inputUserInfo(SIGNIN_INPUT);


    Context &context = Context::get_instance();
    int i = context.findUser(info.id);
    if (i >= 0) {
        cout << "已注册！" << endl;
    } else {
        User *user_p = nullptr;
        switch (info.type) {
            case STUDENT_TYPE:
                user_p = new Student(info.name,info.id,info.password,info.type);
                break;
            case TEACHER_TYPE:
                user_p = new Teacher(info.name, info.id, info.password, info.type);
                break;
            case ADMINISTRATOR_TYPE:
                break;
        }
        if (user_p) {
            context.addUser(user_p);
            cout << "注册成功！" << endl;
        } else {
            showInfo("注册失败！");
        }
    }
}

int flag = 0;

void logIn() {
    showInfo("==== 登录 ====");
    Info_t info = inputUserInfo(LOGIN_INPUT);

    GET_CONTEXT;
    int i = context.verifyUser(info.id, info.password);
    if (i >= 0) {
        cout << "登录成功！" << endl;

        info.type = context.getUserType(info.id);
        info.name = context.getUserName(info.id);
        User* user_ptr = context.getUser(info.id,info.name);
        context.setCurrentUser(user_ptr);

        switch(info.type) {
            case STUDENT_TYPE:
                flag = 0;
                break;
            case TEACHER_TYPE:
                flag = 1;
                break;
            case ADMINISTRATOR_TYPE:
                flag = 2;
                break;
            default:
                break;


        }
    }
    /*
    if (i == user_list.size()) {
        cout << "信息错误！登录失败！" << endl;
    }
    else {
        if (user_list[i].getType() == STUDENT_TYPE) {

                flag = 0;
                cout << "你好，同学！" << endl;
                cout << "请选择操作：选课(0)/退课(1)/查看课程信息(2)/修改密码(3)/退出程序(4)" << endl;
                cin >> operation;
        }

        if (user_list[i].getType() == TEACHER_TYPE) {

            flag = 1;
            cout << "您好，老师！" << endl;
            cout << "请选择操作：开课(0)/获得学生名单(1)/公布成绩(2)/修改密码(3)/退出程序(4)"
                 << endl;
            cin >> operation;
        }

        if (user_list[i].getType() == ADMINISTRATOR_TYPE) {

            flag = 2;
            cout << "您好，管理员！" << endl;
            cout << "请选择操作：修改教师信息(0)/修改学生信息(1)/修改课程信息(2)/修改个人密码(3)/退出程序(4)"
                 << endl;
            cin >> operation;
        }
    }
*/
}

void logOut() {
    showInfo("欢迎下次使用");
//    system("pause");
    cin.get();
}

void studentInterface() {
#if CONFIG_STUDENT_FUNCTION
    GET_CONTEXT;
    Student* user_ptr = (Student*)context.getCurrentUser();
    bool boolean = true;
    int operation;
    while (boolean) {
        showInfo("请输入您的操作：选课(0)/退课(1)/查找课程信息(2)/修改密码(3)/退出系统(4)");
        operation = getIntInput();
        switch (operation) {
            case SELECT:    //学生选课
                user_ptr->selectCourse();
                break;
            case DROP:        //学生退课
                user_ptr->dropCourse();
                break;
            case SEARCH:    //学生查询课程信息
                user_ptr->getCourseInfo();
                break;
            case CHANGE_STUDENT:
                user_ptr->changePassword();
                break;
            case EXIT_STUDENT:
                boolean = false;
                break;
            default:
                break;
        }
    }
#else
    showInfo("没有实现此功能");
#endif
}

void teacherInterface() {
    DEBUG_STDOUT("enter teacherInterface!!!");
#if CONFIG_TEACHER_FUNCTION
    GET_CONTEXT;
    Teacher* user_ptr = (Teacher*)context.getCurrentUser();
    bool boolean = true;
    int operation;
    DEBUG_STDOUT("current user name: " + user_ptr->getName());
    while (boolean) {
        showInfo("请输入您的操作：开课(0)/获得学生名单(1)/登入成绩(2)/修改密码(3)/退出系统(4)");
        operation = getIntInput();

        switch(operation) {
            case OPEN:
                user_ptr->openCourse();
                break;
            case GET:
                user_ptr->getStuList();
                break;
            case POST:
                user_ptr->postGrades();
                break;
            case CHANGE_TEACHER:
                user_ptr->changePassword();
                break;
            case EXIT_TEACHER:
                boolean = false;
                break;
            default:
                break;
        }
    }
#else
    showInfo("没有实现此功能！");
#endif
}

///////////////////////

///////////////////////

// Main
int main(int argc, char **argv) {
    DEBUG_STDOUT("main start!!!");
    int choice;
    bool run_tag = true;
    while (run_tag) {
        showInfo("请输入您的操作：注册(0)/登录(1)/登出(2)");
        choice = getIntInput();
//		cout << "choice" << choice << endl;
        switch (choice) {
            case MAIN_OP_SIGN_IN:        //注册
                signIn();
                break;
            case MAIN_OP_LOG_IN:        //登录
                logIn();
                if (flag == 0) {
                    studentInterface();
                }

                if(flag == 1) {
                    teacherInterface();
                }
                break;
            case MAIN_OP_LOG_OUT:
                logOut();
                run_tag = false;
                break;
            default:
                exit(-1);
        }
    }

    return 0;
}

