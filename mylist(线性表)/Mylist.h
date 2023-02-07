#pragma once

#include<string>
#include<iostream>
#include"student.h"

using namespace std;

typedef class Mylist
{
public:
	//Êı¾İÓò
	student stu;

	//Ö¸ÕëÓò
	Mylist* next;

	void heard_getelem();

	void print();
}*mylist;

