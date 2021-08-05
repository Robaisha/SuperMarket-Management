#ifndef SIGNUP_H
#define SIGNUP_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class signup {
public:
	int flag = 1, i, j=0, count = 0; 
	int small = 0, special = 0, numbers = 0 , caps = 0; 
	int success = 0, x, choice; 
	char id[100], pass[100],pass2[100], email[100],details[100]; 
	char num[100], age,ch1,ch2;

	signup();
	~signup();

	bool account_check(std::string username, std::string password);
	bool account_check2(std::string username, std::string password);
	void signup1(std::string username, std::string password);
	void signup2(std::string username, std::string password);
	int validate(char pass[100],char pass2[100], char num[100], int age);
};
#endif
#pragma once
