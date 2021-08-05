#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <string>
#include <fstream>
#include "signup.h"
using namespace std;
class signin : public signup {
public:
	std::string user;
	std::string pass;
	signin();
	~signin();
	void login(std::string user_1, std::string pass_1);
	void login2(std::string user_1, std::string pass_1);
};
#endif
