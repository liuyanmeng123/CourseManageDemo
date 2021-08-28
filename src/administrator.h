//
// Created by 86189 on 2021/8/24.
//

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "config.h"
#if CONFIG_ADMIN_FUNCTION

#include "user.h"

using namespace std;

class Administrator:public User{
public:
    void changeStudentInfo();
    void changeTeacherInfo();
    void changeCourseInfo();

private:

};
#endif // CONFIG_ADMIN_FUNCTION

#endif
