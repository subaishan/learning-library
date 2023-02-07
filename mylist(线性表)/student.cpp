#include "student.h"

void student::print()
{
	cout << this->_name;
	cout << this->_age;
	cout << this->_ID;
	cout << this->fraction;
}

void student::getData(string name, string age, string id, string fraction)
{
	this->_name = name;
	this->_age = age;
	this->_ID = id;
	this->fraction = fraction;
}