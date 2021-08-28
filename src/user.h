#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User{
public:
    User();
	User(string name, string id, string password, int type);
	~User();
	void changePassword();		//修改密码 
	string getName();
	string getId();
	string getPassword();
	int getType();
	void setMajor(string major);
	void setCollege(string college);
		
private:
	string _name;
	string _id;
	string _password;
	int _type;
	string _major;
	string _college;
};

#endif


