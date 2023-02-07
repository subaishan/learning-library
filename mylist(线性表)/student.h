#pragma once

#include<string>
#include<iostream>

using namespace std;

class student
{
public:

	string _name;
	string _age;
	string _ID;
	string fraction;

	void getData(string,string,string,string);
	void print();
};