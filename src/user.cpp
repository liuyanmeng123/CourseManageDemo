#include <string>
#include <iostream>

#include "user.h"


User::User(string name, string id, string password, int type){
	_name = name;
	_id = id;
	_password = password;
	_type = type;
}


User::~User(){

}

void User::changePassword(){
	string newP;
	cout << "请输入更改后的密码：" << endl;
	cin >> newP;
			 
	_password = newP;
	
	cout << "修改成功！" << endl;
} 

string User::getName(){
	return _name;
} 

string User::getId(){
	return _id;
} 

string User::getPassword(){
	return _password;
}

int User::getType(){
	return _type;
}

void User::setMajor(string major){
    _major = major;
}

void User::setCollege(string college){
    _college = college;
}

User::User() {

}


